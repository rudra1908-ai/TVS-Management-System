#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define rate 8.0
struct date
{
	int month;
	int day;
	int year;	
};
struct customer
{
    char name[25],address[60],city[15],vehical_model[20],vcolor[20],modeltype[20];
    long long phone_no;
    int pincode,price,dp;
    char buying_status[10];
    int emi;
    int srno;
    struct date d;
};
struct employee
{
	char name[40],designation[20],email[50];
	int empid,salary;
	char qualification[20];
	struct date jd;
	long long accno,phoneno;
	
};
void functions();
void insertDetails();
void readDetails();
void updateMenu();
void updateRecords();
void updateName();
void updateDownpayment();
void updateModel();
void sortMenu();
void sortRecords();
void sortByDownpayment();
void sortByName();
void sortByPrice();
void searchMenu();
void searchRecords();
void searchBySrno();
void searchByName();
void details();
void detailsOfModel();
void detailsOfBuyingStatus();
void detailsOfParticularDate();
void detailsOfParticularDownpayment();
void deleteMenu();
void deleteRecords();
void deleteBySrno();
void deleteByName();
int checkPhno(long long );
int checkPincode(int);
long calculate_emi(int);
int cal_srno();
void maxDownpayment();
void minDownpayment();
int countRecords();
void printModel();
void printModelType();
void printModelColor();
void detailsOfModelType();
int selectPrice(int ,int );
int checkDate(int,int,int);
void empMenu();
void insertEmpDetails();
void readEmpDetails();
void updateEmpMenu();
void updateEmp();
void updateEmpName();
void updateEmpSalary();
void updateEmpDesignation();
void updateEmpPhoneno();
void updateEmpEmail();
void updateEmpAccno();
void findMaximumSalary();
void findMinimumSalary();
void sortEmpMenu();
int countEmpRecord();
void sortEmpDetails();
void sortEmpName();
void sortEmpSalary();
void sortEmpExp();
void searchEmpMenu();
void searchEmp();
void searchEmpId();
void searchEmpName();
void searchEmpDesignation();
void searchEmpPhoneno();
void searchEmpEmail();
void searchEmpQualification();
void searchEmpSalary();
void deleteEmpMenu();
void deleteEmp();
void deleteEmpByEmpId();
void deleteEmpByName();
int empId();
void checkPass1();
void checkPass2();
void greet(int );
int main()
{
	int choice,choice1;
	if(countEmpRecord() == 0)
	{
		goto insert;
	}
	checkPass1();
	do
	{
		again:
		functions();
		printf("\nEnter number of function that you want to perform : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertDetails();
				break;
			case 2:
				readDetails();
				break;
			case 3:
				updateRecords();
				break;
			case 4:
				maxDownpayment();
				break;
			case 5:
				minDownpayment();
				break;
			case 6:
				sortRecords();
				break;
			case 7:
				searchRecords();
				break;
			case 8:
				deleteRecords();
				break;
			case 9:
				insert:
				checkPass2();					
				do
				{
					again1:
					empMenu();
					printf("\nEnter number of function that you want to perform : ");
					scanf("%d",&choice1);
					switch(choice1)
					{
						case 1:
							insertEmpDetails();
							break;
						case 2:
							readEmpDetails();
							break;
						case 3:
							updateEmp();
							break;
						case 4:
							findMaximumSalary();
							break;
						case 5:
							findMinimumSalary();
							break;
						case 6:
							sortEmpDetails();
							break;
						case 7:
							searchEmp();
							break;
						case 8:
							deleteEmp();
							break;
						case 9:
							printf("\n\nExiting from employee menu\n");
							printf("\nThak you,Visit Again :)\n");
							break;
						default:
							printf("\nInvalid choice...\nTry again\n\n");
							goto again1;
					}
				}while(choice1 != 9);
				break;
			case 10:
				printf("\n\nExiting from functions\n");
				printf("\nThak you,Visit Again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
		}
	}while(choice != 10);
    return 0;
}
void insertDetails()
{
    struct customer c;
    FILE *f;
    c.srno = cal_srno()+1;
    int choice;
    int vmodel,vmtype;//Vehical model , Vehical moodel type
    f = fopen("customer.txt","a");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    printf("Enter customer name : ");
    scanf(" %[^\n]s",c.name);
    c.name[0] = toupper((char)c.name[0]);
    again:
    printf("Enter customer phone number : ");
    scanf("%lld",&c.phone_no);
    if(checkPhno(c.phone_no) == 1)
    {
        printf("\nPhone number contains exactly 10 digits..\n");
        printf("\nTry again...\n");
        goto again;
    }
    printf("Enter customer address : ");
    scanf(" %[^\n]s",c.address);
    printf("Enter customer city : ");
    scanf("%s",c.city);
    again1:
    printf("Enter customer pincode : ");
    scanf("%d",&c.pincode);
    if(checkPincode(c.pincode) == 1)
    {
        printf("\nPincode contains exactly 6 digits..\n");
        printf("\nTry again...\n");
        goto again1;
    }
    again2:
	printModel();
	char model[5][100] = {"TVS Ronin","TVS Apache RTX 300","TVS Raider","TVS Jupiter 125","TVS Jupiter 125"};
    printf("Enter vehical model no : ");
    scanf("%d",&choice);
    if(choice < 1 || choice > 5)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again2;
	}
    vmodel = choice-1;
    strcpy(c.vehical_model,model[choice-1]);
    again3:
    printModelColor();
    char color[5][15]={"Black","White","Blue","Silver","Green"};
    printf("Enter vehical colour no : ");
    scanf("%d",&choice);
    if(choice < 1 || choice > 5)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again3;
	}
    strcpy(c.vcolor,color[choice-1]);
    again4:
    printModelType();
    char type[3][20]={"Top","Medium","Based"};
	printf("Enter model type no : ");
    scanf("%d",&choice);
    if(choice < 1 || choice > 3)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again4;
	}
    vmtype = choice-1;
    strcpy(c.modeltype,type[choice-1]);
    c.price = selectPrice(vmodel,vmtype);
    printf("Price : %d\n",c.price);
    again5:
    printf("Enter downpayment : ");
    scanf("%d",&c.dp);
    if(c.dp > c.price)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again5;
	}
	again6:
    printf("Enter booking date(dd mm yyy) : ");
    scanf("%d %d %d",&c.d.day,&c.d.month,&c.d.year);
    if(checkDate(c.d.day,c.d.month,c.d.year) == 1)
    {
    	printf("\nInvalid date\nTry again...\n\n");
    	goto again6;
	}
    char status[2][10]={"Cash","Loan"};
    again7:
    printf("Enter buying mode(1-loan,0-cash) : ");
    scanf("%d",&choice);
    if(choice != 0 && choice != 1)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again7;
	}
    strcpy(c.buying_status,status[choice]);
    c.emi = 0;
    if(strcmp(c.buying_status,"Loan") == 0)
    {
        c.emi = calculate_emi(c.price-c.dp);
        printf("\nMonthly emi = %d\n",c.emi);
    }
    else
    {
    	c.emi = 0;
	}
    fwrite(&c,sizeof(c),1,f);
    printf("\nRecord inserted sucessfully...\n");
    fclose(f);
}
void readDetails()
{
    struct customer c;
    FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt=countRecords();
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
       c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
       c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    fclose(f);
    printf("\nThere are %d records found\n",cnt);
}
int checkPhno(long long c)
{
    long long a = c;
    int len=0;
    while(a != 0)
    {
        len++;
        a/=10;
    }
    if(len != 10)
        return 1;
    else
        return 0;
}
int checkPincode(int c)
{
    long long a = c;
    int len=0;
    while(a != 0)
    {
        len++;
        a/=10;
    }
    if(len != 6)
        return 1;
    else
        return 0;
}
long calculate_emi(int p)
{
     int month;
    float cal_rate;
    printf("Enter total number of emi month : ");
    scanf("%d",&month);
    cal_rate = rate/(12.0 * 100);
    long cal_emi;
    double pow2 = 1.0;
    int i;
    for(i=1;i<=month;i++)
    {
    	pow2 *= (1+cal_rate);
	}
    cal_emi = (p*cal_rate*pow2)/(pow2-1);
    return cal_emi;
}
int cal_srno()
{
	struct customer c;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int srno=0;
    while((fread(&c,sizeof(c),1,f)))
    {
    	srno++;
	}
    fclose(f);
    return srno;
}
int countRecords()
{
	struct customer c;
	FILE *f;
    f = fopen("customer.txt","r");
   	int cnt=0;
   	while((fread(&c,sizeof(c),1,f)))
    {
		cnt++;
	}
	fclose(f);
	return cnt;
}
void maxDownpayment()
{
	struct customer c;
	int cnt = countRecords();
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
	int a[cnt],i=0;
	while((fread(&c,sizeof(c),1,f)))
	{
		a[i] = c.dp;
		i++;
	}
	int  max = a[0];
	for(i=0;i<cnt;i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	fseek(f,0,SEEK_SET);
	printf("\n\n\t\t\t\t---------Max Downpayment---------\t\t\n");
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(max == c.dp)
    	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
      			 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);
   		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
}
void minDownpayment()
{
	struct customer c;
	int cnt = countRecords();
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
	int a[cnt],i=0;
	while((fread(&c,sizeof(c),1,f)))
	{
		a[i] = c.dp;
		i++;
	}
	int  min = a[0];
	for(i=0;i<cnt;i++)
	{
		if(a[i] < min)
		{
			min = a[i];
		}
	}
	fseek(f,0,SEEK_SET);
	printf("\n\n\t\t\t\t---------Minimum Downpayment---------\t\t\n");
		printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(min == c.dp)
    	{
	    	printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		  c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      		 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);	
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
}
void printModel()
{
	printf("+-----------------------+\n");
	printf("| 1. TVS Ronin          |\n");
	printf("| 2. TVS Apache RTX 300 |\n");
	printf("| 3. TVS Raider         |\n");
	printf("| 4. TVS Jupiter 125    |\n");
	printf("| 5. TVS Jupiter 110    |\n");
	printf("+-----------------------+\n");
	
}
void printModelType()
{
	printf("+-----------+\n");
	printf("| 1. Top    |\n");
	printf("| 2. Medium |\n");
	printf("| 3. Based  |\n");
	printf("+-----------+\n");
}
void printModelColor()
{
	printf("+------------+\n");
	printf("| 1. Black   |\n");
	printf("| 2. White   |\n");
	printf("| 3. Blue    |\n");
	printf("| 4. Silver  |\n");
	printf("| 5. Green   |\n");
	printf("+------------+\n");
}
int selectPrice(int vmodel,int vmtype)
{
	int price[5][3]={
					150000,135000,125000,
					170000,150000,135000,
					130000,125000,120000,
					117000,109000,103000,
					110000,105000,100000
					};
	if(vmodel == 0)
	{
		if(vmtype == 0)
			return price[0][0];
		else if(vmtype == 1)
			return price[0][1];
		else
			return price[0][2];
	}
	else if(vmodel == 1)
	{
		if(vmtype == 0)
			return price[1][0];
		else if(vmtype == 1)
			return price[1][1];
		else
			return price[1][2];
	}
	else if(vmodel == 2)
	{
		if(vmtype == 0)
			return price[2][0];
		else if(vmtype == 1)
			return price[2][1];
		else
			return price[2][2];
	}
	else if(vmodel == 3)
	{
		if(vmtype == 0)
			return price[3][0];
		else if(vmtype == 1)
			return price[3][1];
		else
			return price[3][2];
	}
	else
	{
		if(vmtype == 0)
			return price[4][0];
		else if(vmtype == 1)
			return price[4][1];
		else
			return price[4][2];
	}
}
void updateRecords()
{
	int choice;
	do
	{
		again:
		updateMenu();
		printf("\nEnter number of function that you want to perform : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				updateName();
				break;
			case 2:
				updateDownpayment();
				break;
			case 3:
				updateModel();
				break;
			case 4:
				printf("\n\nExiting from Update menu\n");
				printf("\nThak you,Visit Again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
		}
	}while(choice != 4);
}
void updateName()
{
	struct customer c;
	char nname[20],name[20];
	int i=0,cnt=0,pos;
	
	FILE *f,*f1;
    f = fopen("customer.txt","r");
    f1 = fopen("temp.txt","w");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter old name : ");
	scanf(" %[^\n]s",name);
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&c,sizeof(c),1,f)))
	{
		if(strcmp(name,c.name) == 0)
		{
			printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		  c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      		 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);	
			cnt++;	
		}
	}
	if(cnt == 0)
	{
		printf("\nName not found...\nTry again\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	printf("Enter new name : ");
	scanf(" %[^\n]s",nname);
	fseek(f,0,SEEK_SET);
	 while((fread(&c,sizeof(c),1,f)))
	{
		if(strcmp(name,c.name) == 0)
		{
				strcpy(c.name,nname);
		}
		fwrite(&c,sizeof(c),1,f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("customer.txt","w");
    f1 = fopen("temp.txt","r");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&c,sizeof(c),1,f1)))
	{
		fwrite(&c,sizeof(c),1,f);
	}
    fclose(f);
	fclose(f1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateDownpayment()
{
	struct customer c;
	int srno;
	int ndp,cnt=0,price;//ndp=New downpayment
	FILE *f,*f1;
    f = fopen("customer.txt","r");
    f1 = fopen("temp.txt","w");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter srno : ");
	scanf("%d",&srno);
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
		{
			printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		  c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      		 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);	
			cnt++;	
			price = c.price;
		}
	}
	if(cnt == 0)
	{
		printf("\nInvalid sr no...\nTry again\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	again1:
	printf("Enter new downpayment : ");
	scanf("%d",&ndp);
	if(ndp > price)
	{
		printf("\nInvalid downpayment\nTry again...\n\n");
    	goto again1;
	}
	fseek(f,0,SEEK_SET);
	 while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
		{
				c.dp = ndp;
				if(strcmp(c.buying_status,"Loan") == 0)
					c.emi = calculate_emi(c.price-c.dp);
		}
		fwrite(&c,sizeof(c),1,f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("customer.txt","w");
    f1 = fopen("temp.txt","r");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&c,sizeof(c),1,f1)))
	{
		fwrite(&c,sizeof(c),1,f);
	}
    fclose(f);
	fclose(f1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateModel()
{
	struct customer c;
	int srno;
	int choice,cnt=0,price,mtype,mcolor;
	FILE *f,*f1;
    f = fopen("customer.txt","r");
    f1 = fopen("temp.txt","w");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter srno : ");
	scanf("%d",&srno);
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
		{
			printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		  c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      		 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);	
			cnt++;	
		}
	}
	if(cnt == 0)
	{
		printf("\nInvalid sr no...\nTry again\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	again1:
	printModel();
	char model[5][100] = {"TVS Ronin","TVS Apache RTX 300","TVS Raider","TVS Jupiter 125","TVS Jupiter 110"};
	printf("Enter new model no : ");
	scanf("%d",&choice);
	if(choice < 1 || choice > 5)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again1;
	}
	again2:
	printModelType();
	char type[3][20]={"Top","Medium","Based"};
	printf("Choose model type : ");
	scanf("%d",&mtype);
	if(mtype < 1 || mtype > 3)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again2;
	}
	again3:
	printModelColor();
	char color[5][15]={"Black","White","Blue","Silver","Green"};
	printf("Choose color : ");
	scanf("%d",&mcolor);
	 if(mcolor < 1 || mcolor > 5)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again3;
	}
	fseek(f,0,SEEK_SET);
	 while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
		{
				strcpy(c.vehical_model,model[choice-1]);
				strcpy(c.modeltype,type[mtype-1]);
				strcpy(c.vcolor,color[mcolor-1]);
				c.price = selectPrice(choice-1,mtype-1);
				if(strcmp(c.buying_status,"Loan") == 0)
					c.emi = calculate_emi(c.price-c.dp);
		}
		fwrite(&c,sizeof(c),1,f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("customer.txt","w");
    f1 = fopen("temp.txt","r");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&c,sizeof(c),1,f1)))
	{
		fwrite(&c,sizeof(c),1,f);
	}
    fclose(f);
	fclose(f1);
	printf("\n\nRecord updated sucessfully...\n");
}
void sortRecords()
{
	int choice;
	do
	{
		again:
		sortMenu();
		printf("\nEnter number of function that you want to perform : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				sortByName();
				break;
			case 2:
				sortByDownpayment();
				break;
			case 3:
				sortByPrice();
				break;
			case 4:
				printf("\n\nExiting from Sort menu\n");
				printf("\nThak you,Visit Again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
		}
	}while(choice != 4);
}
void sortByDownpayment()
{
	int cnt = cal_srno();
	struct customer c,c1[cnt],temp;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int i=0,j;
    while((fread(&c,sizeof(c),1,f)))
    {
    	c1[i] = c;
    	i++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(c1[i].dp > c1[j].dp)
			{
				temp = c1[i];
				c1[i] = c1[j];
				c1[j] = temp;
			}
		}
	}
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<cnt;i++)
	{
    	printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
       c1[i].srno,c1[i].name,c1[i].phone_no,c1[i].vehical_model,c1[i].vcolor,
       c1[i].modeltype,c1[i].price,c1[i].dp,c1[i].buying_status,c1[i].emi,c1[i].d.day,c1[i].d.month,c1[i].d.year);
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    fclose(f);
}
void sortByName()
{
	int cnt = cal_srno();
	struct customer c,c1[cnt],temp;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int i=0,j;
    while((fread(&c,sizeof(c),1,f)))
    {
    	c1[i] = c;
    	i++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(strcmp(c1[i].name,c1[j].name) > 0)
			{
				temp = c1[i];
				c1[i] = c1[j];
				c1[j] = temp;
			}
		}
	}
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<cnt;i++)
	{
    	printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
       c1[i].srno,c1[i].name,c1[i].phone_no,c1[i].vehical_model,c1[i].vcolor,
       c1[i].modeltype,c1[i].price,c1[i].dp,c1[i].buying_status,c1[i].emi,c1[i].d.day,c1[i].d.month,c1[i].d.year);
		
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    fclose(f);
}
void sortByPrice()
{
	int cnt = cal_srno();
	struct customer c,c1[cnt],temp;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int i=0,j;
    while((fread(&c,sizeof(c),1,f)))
    {
    	c1[i] = c;
    	i++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(c1[i].price > c1[j].price)
			{
				temp = c1[i];
				c1[i] = c1[j];
				c1[j] = temp;
			}
		}
	}
	printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	for(i=0;i<cnt;i++)
	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
       c1[i].srno,c1[i].name,c1[i].phone_no,c1[i].vehical_model,c1[i].vcolor,
       c1[i].modeltype,c1[i].price,c1[i].dp,c1[i].buying_status,c1[i].emi,c1[i].d.day,c1[i].d.month,c1[i].d.year);
	
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    fclose(f);
}
void searchRecords()
{
	int choice;
	do
	{
		again:
		searchMenu();
		printf("\nEnter number of function that you want to perform : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				searchBySrno();
				break;
			case 2:
				searchByName();
				break;
			case 3:
				detailsOfModel();
				break;
			case 4:
				detailsOfBuyingStatus();
				break;
			case 5:
				detailsOfParticularDate();
				break;
			case 6:
				detailsOfModelType();
				break;
			case 7:
				detailsOfParticularDownpayment();
				break;
			case 8:
				printf("\n\nExiting from functions\n");
				printf("\nThak you,Visit Again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
		}
	}while(choice != 8);
}
void searchBySrno()
{
	struct customer c;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt,srno;
    again:
    cnt=0;
    printf("Enter sr no to search : ");
    scanf("%d",&srno);
    while((fread(&c,sizeof(c),1,f)))
    {
    	if(srno == c.srno)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(f,0,SEEK_SET);
		printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		while((fread(&c,sizeof(c),1,f)))
   		 {
    		if(srno == c.srno)
    		{
   				printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);
				
			   cnt++;
			}
		}	
			
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
    }
	fclose(f);
}
void searchByName()
{
	struct customer c;
	FILE *f;
    f = fopen("customer.txt","r");
    if(f == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    char name[20];
    again:
    cnt=0;
    printf("Enter name to search : ");
    scanf(" %[^\n]s",name);
    name[0] = toupper((char)name[0]);
    while((fread(&c,sizeof(c),1,f)))
    {
    	if(strcmp(name,c.name) == 0)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(f,0,SEEK_SET);
		printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	
		while((fread(&c,sizeof(c),1,f)))
   		 {
    		if(strcmp(name,c.name) == 0)
    		{
   				printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     		 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
      			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);
				   cnt++;
			}	
			
		}
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
	}
    fclose(f);
}
void detailsOfModel()
{
	struct customer c;
	FILE *f;
	f = fopen("customer.txt","r");
	if(f == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	again:
	printModel();
	int choice,cnt=0;
	char model[5][100] = {"TVS Ronin","TVS Apache RTX 300","TVS Raider","TVS Jupiter 125","TVS Jupiter 125"};
    printf("Enter no of models : ");
    scanf("%d",&choice);
    if(choice < 1 || choice > 5)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again;
	}
    printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(strcmp(c.vehical_model,model[choice-1]) == 0)
    	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     	 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
   			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);				  
    		cnt++;
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
	printf("\n%d records found\n",cnt);	
}
void detailsOfBuyingStatus()
{
	struct customer c;
	FILE *f;
	f = fopen("customer.txt","r");
	if(f == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	char buying_status[20]; 
	int choice,cnt=0;
	again:
    printf("Enter no of buying status(1-Loan,0-Cash) : ");
    scanf("%d",&choice);
    if(choice != 0 && choice != 1)
    {
    	printf("\nInvalid choice\nTry again...\n\n");
    	goto again;
	}
    (choice == 0)?strcpy(buying_status,"Cash"):strcpy(buying_status,"Loan");
    printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(strcmp(c.buying_status,buying_status) == 0)
    	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     	 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
   			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);				  
    		cnt++;
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
	printf("\n%d records found\n",cnt);	
}
void detailsOfParticularDate()
{
	struct customer c;
	FILE *f;
	f = fopen("customer.txt","r");
	if(f == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	int day,month,year; 
	int choice,cnt=0;
	again:
    printf("Enter date(dd mm yyyy) : ");
    scanf("%d %d %d",&day,&month,&year);
    if(checkDate(day,month,year) == 1)
    {
    	printf("\nInvalid date...\nTry again\n\n");
		goto again;
	}
    printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(c.d.day == day && c.d.month == month && c.d.year == year)
    	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     	 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
   			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);				  
    		cnt++;
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
	printf("\n%d records found\n",cnt);	
}
void detailsOfModelType()
{
	struct customer c;
	FILE *f;
	f = fopen("customer.txt","r");
	if(f == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	again:
	printModel();
	int choice,cnt=0,choice1;
	char model[5][100] = {"TVS Ronin","TVS Apache RTX 300","TVS Raider","TVS Jupiter 125","TVS Jupiter 125"};
    printf("Enter no of models : ");
    scanf("%d",&choice);
    if(choice < 1 || choice > 5)
    {
    	printf("\nInvalid choice...\nTry again\n\n");
    	goto again;
	}
	again1:
    printModelType();
    char type[3][20]={"Top","Medium","Based"};
    printf("Enter no of model type : ");
    scanf("%d",&choice1);
    if(choice1 < 1 || choice1 > 3)
    {
    	printf("\nInvalid choice...\nTry again\n\n");
    	goto again;
	}
    printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(strcmp(c.vehical_model,model[choice-1]) == 0)
    	{
    		if(strcmp(c.modeltype,type[choice1-1]) == 0)
    		{
    			printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     	 	 	c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
   			 	c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);				  
    			cnt++;
    		}
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
	printf("\n%d records found\n",cnt);	
}
void detailsOfParticularDownpayment()
{
	int ldp,mdp;
	printf("Enter minimum down payment : ");
	scanf("%d",&ldp);
	printf("Enter maximum down payment : ");
	scanf("%d",&mdp);
	struct customer c;
	FILE *f;
	f = fopen("customer.txt","r");
	if(f == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	int cnt=0;
    printf("\n%-5s %-15s %-15s %-20s %-10s %-12s %-10s %-12s %-12s %-10s %-12s\n",
       "SrNo","Name","PhoneNo","Vehicle","Color","ModelType",
       "Price","DownPayment","BuyingMode","EMI","date");
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&c,sizeof(c),1,f)))
    {
    	if(c.dp > ldp && c.dp < mdp)
    	{
    		printf("%-5d %-15s %-15lld %-20s %-10s %-12s %-10d %-15d %-10s %-10d %-02d %-02d %-02d\n",
     	 	 c.srno,c.name,c.phone_no,c.vehical_model,c.vcolor,
   			 c.modeltype,c.price,c.dp,c.buying_status,c.emi,c.d.day,c.d.month,c.d.year);				  
    		cnt++;
		}
	}
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(f);
	printf("\n%d records found\n",cnt);	
}
void deleteRecords()
{
	int choice;
	do
	{
		again:
		deleteMenu();
		printf("\nEnter number of function that you want to perform : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				deleteBySrno();
				break;
			case 2:
				deleteByName();
				break;
			case 3:
				printf("\n\nExiting from Delete menu\n");
				printf("\nThak you,Visit Again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
		}
	}while(choice != 3);
}
void deleteBySrno()
{
	struct customer c;
	int i=0,cnt=0,srno;
	FILE *f,*f1;
    f = fopen("customer.txt","r");
    f1 = fopen("temp.txt","w");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter srno : ");
	scanf("%d",&srno);
    while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
			cnt++;	
	}
	if(cnt == 0)
	{
		printf("\nInvalid Sr no...\nTry again\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	fseek(f,0,SEEK_SET);
	 while((fread(&c,sizeof(c),1,f)))
	{
		if(c.srno == srno)
			continue;
		else
			fwrite(&c,sizeof(c),1,f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("customer.txt","w");
    f1 = fopen("temp.txt","r");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&c,sizeof(c),1,f1)))
	{
		fwrite(&c,sizeof(c),1,f);
	}
    fclose(f);
	fclose(f1);
	printf("\n\nRecord deleted successfully...\n");
}
void deleteByName()
{
	struct customer c;
	char name[20];
	int i=0,cnt=0;
	FILE *f,*f1;
    f = fopen("customer.txt","r");
    f1 = fopen("temp.txt","w");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter name to delete : ");
	scanf("%s",name);
	name[0] = toupper((char)name[0]);
    while((fread(&c,sizeof(c),1,f)))
	{
		if(strcmp(c.name,name) == 0)
			cnt++;	
	}
	if(cnt == 0)
	{
		printf("\nInvalid Sr no...\nTry again\n");
		fseek(f,0,SEEK_SET);
		goto again;
	}
	fseek(f,0,SEEK_SET);
	 while((fread(&c,sizeof(c),1,f)))
	{
		if(strcmp(c.name,name) == 0)
			continue;
		else
			fwrite(&c,sizeof(c),1,f1);
	}
	fclose(f);
	fclose(f1);
	f = fopen("customer.txt","w");
    f1 = fopen("temp.txt","r");
    if(f == NULL || f1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&c,sizeof(c),1,f1)))
	{
		fwrite(&c,sizeof(c),1,f);
	}
    fclose(f);
	fclose(f1);
	printf("\n\nRecord deleted successfully...\n");
}
void functions()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|************Functions***********|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Insert Record               |\n\n");
	printf("\t\t\t\t|2.  Print All Record            |\n\n");
	printf("\t\t\t\t|3.  Update Record               |\n\n");
	printf("\t\t\t\t|4.  Maximum Downpayment         |\n\n");
	printf("\t\t\t\t|5.  Minimum Downpayment         |\n\n");
	printf("\t\t\t\t|6.  Print Sorted Record         |\n\n");
	printf("\t\t\t\t|7.  Search customer Record      |\n\n");
	printf("\t\t\t\t|8.  Delete Record               |\n\n");
	printf("\t\t\t\t|9.  Employee Data management    |\n\n");
	printf("\t\t\t\t|10. Exit                        |\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void updateMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|*********Update Menu************|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Update Name                 |\n\n");
	printf("\t\t\t\t|2.  Update Downpayment          |\n\n");
	printf("\t\t\t\t|3.  Update Vehical Model        |\n\n");
	printf("\t\t\t\t|4.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void sortMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|********Sorting Menu************|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Sorted By Name              |\n\n");
	printf("\t\t\t\t|2.  Sorted By Downpayment       |\n\n");
	printf("\t\t\t\t|3.  Sorted By Price             |\n\n");
	printf("\t\t\t\t|4.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void searchMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+---------------------------------------+\n");
	printf("\t\t\t\t|       TVS Management System           |\n");
	printf("\t\t\t\t|---------------------------------------|\n");
	printf("\t\t\t\t|*********Search Details Menu***********|\n");
	printf("\t\t\t\t+---------------------------------------+\n");
	printf("\t\t\t\t|1.  Search By Srno.                    |\n\n");
	printf("\t\t\t\t|2.  Search By Customer Name            |\n\n");
	printf("\t\t\t\t|3.  Search By Vehical Model            |\n\n");
	printf("\t\t\t\t|4.  Search By Buying Status            |\n\n");
	printf("\t\t\t\t|5.  Search By Particular Date          |\n\n");
	printf("\t\t\t\t|6.  Search By Model Type               |\n\n");
	printf("\t\t\t\t|7.  Search By Particular Downpayment   |\n\n");
	printf("\t\t\t\t|8.  Exit                              |\n");
	printf("\t\t\t\t+---------------------------------------+\n");
}
void deleteMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|********Delete Menu*************|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Delete By Sr no.            |\n\n");
	printf("\t\t\t\t|2.  Delete By Name              |\n\n");
	printf("\t\t\t\t|3.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
int checkDate(int day,int month,int year)
{
	if(year <= 999 || year > 9999)
	{
		return 1;
	}
	else
	{
		if(month < 1 || month > 12)
		{
			return 1;
		}
		else
		{
			if(month == 1 || month == 3 || month == 5 || month == 7 ||
				month == 8 || month == 10 || month == 12)
			{
				if(day < 1 || day > 31)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(month == 4 || month == 6 || month == 9 || month == 11)
			{
				if(day < 1 || day > 30)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else
			{
				if(year%4 == 0)
				{
					if(day < 1 || day > 29)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
				else
				{
					if(day < 1 || day > 28)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
		}
	}
}
void insertEmpDetails()
{
	struct employee emp;
	FILE *fp;
	fp = fopen("employee_data","a");
	if(fp == NULL)
	{
		printf("File is not created successfully....");
		exit(-1);
	}
	emp.empid = empId()+1;
	printf("Enter emploeyee name : ");
	scanf(" %s",emp.name); 
	again:
	printf("Enter employee joining date(dd mm yyyy) :");
	scanf("%d %d %d",&emp.jd.day,&emp.jd.month,&emp.jd.year);
	if(checkDate(emp.jd.day,emp.jd.month,emp.jd.year) == 1)
	{
		printf("Invalid date....\nTry again\n\n");
		goto again;
	}
	again2:
	printf("Enter employee phone no : ");
	scanf("%lld",&emp.phoneno);
	if(checkPhno(emp.phoneno) == 1)
	{
		printf("Invalid phone no.\nTry again...\n\n");
		goto again2;
	}
	printf("Enter employee qualification : ");
	scanf(" %[^\n]s",emp.qualification);
	printf("Enter employee email id : ");
	scanf(" %s",emp.email);
	printf("Enter employee designation : ");
	scanf(" %s",emp.designation);
	printf("Enter employee salary : ");
	scanf("%d",&emp.salary);
	printf("Enter employee account no : ");
	scanf("%lld",&emp.accno);
	fwrite(&emp,sizeof(emp),1,fp);
	fclose(fp);
}
void readEmpDetails()
{
    struct employee emp;
    FILE *fp;

    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File not found...");
        exit(-1);
    }

    printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    while(fread(&emp,sizeof(emp),1,fp))
    {
        printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
    }
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

    fclose(fp);
}
int empId()
{
	struct employee e;
	int id = 100;
	FILE *fp;
	fp = fopen("employee_data","r");
	while((fread(&e,sizeof(e),1,fp)))
	{
		id++;
	}
	fclose(fp);
	return id;
}
void empMenu()
{

	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|********Employee Menu***********|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Insert Employee Data        |\n\n");
	printf("\t\t\t\t|2.  Print All Employee Data     |\n\n");
	printf("\t\t\t\t|3.  Update Employee Data        |\n\n");
	printf("\t\t\t\t|4.  Find Maximum Salary         |\n\n");
	printf("\t\t\t\t|5.  Find Minimum Salary         |\n\n");
	printf("\t\t\t\t|6.  Print Sorted Employee Data  |\n\n");
	printf("\t\t\t\t|7.  Search Employee Data        |\n\n");
	printf("\t\t\t\t|8.  Delete Employee Data        |\n\n");
	printf("\t\t\t\t|9.  Exit                        |\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void updateEmpMenu()
{	
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|*********Update Menu************|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Update Employee Name        |\n\n");
	printf("\t\t\t\t|2.  Update Employee Salary      |\n\n");
	printf("\t\t\t\t|3.  Update Employee Designation |\n\n");
	printf("\t\t\t\t|4.  Update Employee Phone no    |\n\n");
	printf("\t\t\t\t|5.  Update Employee Email       |\n\n");
	printf("\t\t\t\t|6.  Update Employee account no  |\n\n");
	printf("\t\t\t\t|7.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void updateEmp()
{
	
	int choice;
	do
	{
		again:
		updateEmpMenu();
		printf("Enter choice from above menu : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				updateEmpName();
				break;
			case 2:
				updateEmpSalary();
				break;
			case 3:
				updateEmpDesignation();
				break;
			case 4:
				updateEmpPhoneno();
				break;
			case 5:
				updateEmpEmail();
				break;
			case 6:
				updateEmpAccno();
				break;
			case 7:
				printf("Exiting from update menu\nThank you visit again :)\n");
				break;
			default:
				printf("\nInvalid choice...\nTry again\n\n");
				goto again;
				break;
		}
		
	}while(choice != 7);
}
void updateEmpName()
{
	struct employee emp;
	char nname[20];
	int i=0,cnt=0,pos,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter emp id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
		{
			 printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nName not found...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	printf("Enter new name : ");
	scanf(" %[^\n]s",nname);
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
		{
				strcpy(emp.name,nname);
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateEmpSalary()
{
	struct employee emp;
	int empid;
	int nsalary,cnt=0,price;//nsalary = new salary
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter employee id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");	  
	while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
		{
			printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nInvalid employee id...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	again1:
	printf("Enter new salary : ");
	scanf("%d",&nsalary);
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
		{
				emp.salary = nsalary;
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");

}
void updateEmpDesignation()
{
	struct employee emp;
	char ndesignation[20];
	int i=0,cnt=0,pos,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter emp id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			 printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nInvalid employee id...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	printf("Enter new designation : ");
	scanf(" %[^\n]s",ndesignation);
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
				strcpy(emp.designation,ndesignation);
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateEmpPhoneno()
{
	struct employee emp;
	long long phoneno;
	int i=0,cnt=0,pos,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter emp id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			 printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nInvalid employee id...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	again2:
	printf("Enter new phone no : ");
	scanf("%lld",&phoneno);
	if(checkPhno(phoneno) == 1)
	{
		printf("Invalid phone no. \nTry again...\n\n");
		goto again2;
	}
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			emp.phoneno = phoneno;
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateEmpEmail()	
{
	struct employee emp;
	char nemail[20];
	int i=0,cnt=0,pos,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter emp id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			 printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nInvalid employee id...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	printf("Enter new email : ");
	scanf(" %[^\n]s",nemail);
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
				strcpy(emp.email,nemail);
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");
}
void updateEmpAccno()
{
	struct employee emp;
	long long accno;
	int i=0,cnt=0,pos,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter emp id : ");
	scanf("%d",&empid);
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			 printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
			cnt++;
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	if(cnt == 0)
	{
		printf("\nInvalid employee id...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	printf("Enter new account no : ");
	scanf("%lld",&accno);
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(empid == emp.empid)
		{
			emp.accno = accno;
		}
		fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord updated sucessfully...\n");
}
void findMaximumSalary()
{
	struct employee emp;
	int cnt = countRecords();
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
	int a[cnt],i=0;
	while((fread(&emp,sizeof(emp),1,fp)))
	{
		a[i] = emp.salary;
		i++;
	}
	int  max = a[0];
	for(i=0;i<cnt;i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}
	fseek(fp,0,SEEK_SET);
	printf("\n\n\t\t\t\t---------Maximum Salary---------\t\t\n");
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(max == emp.salary)
    	{
			printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
    	
  		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
}
void findMinimumSalary()
{
	struct employee emp;
	int cnt = countRecords();
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
	int a[cnt],i=0;
	while((fread(&emp,sizeof(emp),1,fp)))
	{
		a[i] = emp.salary;
		i++;
	}
	int  min = a[0];
	for(i=0;i<cnt;i++)
	{
		if(a[i] < min)
		{
			min = a[i];
		}
	}
	fseek(fp,0,SEEK_SET);
	printf("\n\n\t\t\t\t---------Minimum Salary---------\t\t\n");
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	
	while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(min == emp.salary)
    	{
			printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
               emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
               emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
    	
  		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
}
void sortEmpMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|********Sorting Menu************|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Sorted By Name              |\n\n");
	printf("\t\t\t\t|2.  Sorted By Salary            |\n\n");
	printf("\t\t\t\t|3.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void sortEmpDetails()
{
	int choice;
	do
	{
		again:
		sortEmpMenu();
		printf("Enter choice from above : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				sortEmpName();
				break;
			case 2:
				sortEmpSalary();
				break;
			case 3:
				printf("Exiting from soting menu\nThank you visit again :)\n");
				break;
			default:
				printf("Invalid choice\nTry again...\n\n");
				goto again;
				break;
		}
	}while(choice != 3);
}
int countEmpRecord()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
   	int cnt=0;
   	while((fread(&emp,sizeof(emp),1,fp)))
    {
		cnt++;
	}
	fclose(fp);
	return cnt;
}
void sortEmpName()
{
	int cnt = countEmpRecord();
	struct employee emp,emp1[cnt],temp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int i=0,j;
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	emp1[i] = emp;
    	i++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(strcmp(emp1[i].name,emp1[j].name) > 0)
			{
				temp = emp1[i];
				emp1[i] = emp1[j];
				emp1[j] = temp;
			}
		}
	}
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<cnt;i++)
	{
    	printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
            emp1[i].empid,emp1[i].name,emp1[i].jd.day,emp1[i].jd.month,emp1[i].jd.year,emp1[i].phoneno,
            emp1[i].qualification,emp1[i].designation,emp1[i].salary,emp1[i].accno,emp1[i].email);

	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
}
void sortEmpSalary()
{
	int cnt = countEmpRecord();
	struct employee emp,emp1[cnt],temp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int i=0,j;
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	emp1[i] = emp;
    	i++;
	}
	for(i=0;i<cnt;i++)
	{
		for(j=i+1;j<cnt;j++)
		{
			if(emp1[i].salary > emp1[j].salary)
			{
				temp = emp1[i];
				emp1[i] = emp1[j];
				emp1[j] = temp;
			}
		}
	}
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(i=0;i<cnt;i++)
	{
    	printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
            emp1[i].empid,emp1[i].name,emp1[i].jd.day,emp1[i].jd.month,emp1[i].jd.year,emp1[i].phoneno,
            emp1[i].qualification,emp1[i].designation,emp1[i].salary,emp1[i].accno,emp1[i].email);

	}
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
}
void searchEmpMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+---------------------------------------+\n");
	printf("\t\t\t\t|       TVS Management System           |\n");
	printf("\t\t\t\t|---------------------------------------|\n");
	printf("\t\t\t\t|******Search Employee Details Menu*****|\n");
	printf("\t\t\t\t+---------------------------------------+\n");
	printf("\t\t\t\t|1.  Search By Employee Id              |\n\n");
	printf("\t\t\t\t|2.  Search By Employee Name            |\n\n");
	printf("\t\t\t\t|3.  Search By Designation              |\n\n");
	printf("\t\t\t\t|4.  Search By Phone no                 |\n\n");
	printf("\t\t\t\t|5.  Search By Email                    |\n\n");
	printf("\t\t\t\t|6.  Search By Qualification            |\n\n");
	printf("\t\t\t\t|7.  Search By Particular Salary range  |\n\n");
	printf("\t\t\t\t|8.  Exit                               |\n");
	printf("\t\t\t\t+---------------------------------------+\n");
}
void searchEmp()
{
 	int choice;
 	do
 	{
 		again:
 		searchEmpMenu();
		 switch(choice)
		 {
		 	case 1:
		 		searchEmpId();
		 		break;
		 	case 2:
		 		searchEmpName();
		 		break;
		 	case 3:
		 		searchEmpDesignation();
		 		break;
		 	case 4:
		 		searchEmpPhoneno();
		 		break;
		 	case 5:
		 		searchEmpEmail();
		 		break;
		 	case 6:
		 		searchEmpQualification();
		 		break;
		 	case 7:
		 		searchEmpSalary();
		 		break;
		 	case 8:
		 		printf("Exiting from search menu\nThank you visit again :)\n");
		 		break;
		 	default:
		 		printf("Invalid choice\nTry again...\n\n");
				goto again;
		 		break;
		 }	
	}while(choice != 8);
}
void searchEmpId()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt,empid;
    again:
    cnt=0;
    printf("Enter employee id to search : ");
    scanf("%d",&empid);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(empid == emp.empid)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(empid == emp.empid)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				
			   cnt++;
			}
		}				
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
    }
	fclose(fp);
}
void searchEmpName()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    char name[20];
    again:
    cnt=0;
    printf("Enter name to search : ");
    scanf(" %[^\n]s",name);
    name[0] = toupper((char)name[0]);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(strcmp(name,emp.name) == 0)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(strcmp(name,emp.name) == 0)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				cnt++;
			}	
			
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
	}
    fclose(fp);
}
void searchEmpDesignation()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    char designation[20];
    again:
    cnt=0;
    printf("Enter employee designation to search : ");
    scanf(" %[^\n]s",designation);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(strcmp(designation,emp.designation) == 0)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(strcmp(designation,emp.designation) == 0)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				cnt++;
			}	
			
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
	}
    fclose(fp);
}
void searchEmpPhoneno()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    long long phno;
    again:
    cnt=0;
    printf("Enter employee phone no. to search : ");
    scanf("%lld",&phno);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(phno == emp.phoneno)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(phno == emp.phoneno)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				
			   cnt++;
			}
		}				
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
    }
	fclose(fp);
}
void searchEmpEmail()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    char email[20];
    again:
    cnt=0;
    printf("Enter employee email to search : ");
    scanf(" %[^\n]s",email);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(strcmp(email,emp.email) == 0)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(strcmp(email,emp.email) == 0)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				cnt++;
			}	
			
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
	}
    fclose(fp);
}
void searchEmpQualification()
{
	struct employee emp;
	FILE *fp;
    fp = fopen("employee_data","r");
    if(fp == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    int cnt;
    char qualification[20];
    again:
    cnt=0;
    printf("Enter employee qualification to search : ");
    scanf(" %[^\n]s",qualification);
    while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(strcmp(qualification,emp.qualification) == 0)
    		cnt++;
	}
	if(cnt == 0)
	{
		printf("No record found...\nTry again\n\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	else
	{
		cnt = 0;
		fseek(fp,0,SEEK_SET);
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    	printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	    printf("------------------------------------------------------------------------------------------------------------------------------------------\n");

		while((fread(&emp,sizeof(emp),1,fp)))
   		{
    		if(strcmp(qualification,emp.qualification) == 0)
    		{
   				printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
				cnt++;
			}	
			
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("\n\n%d records found...\n\n",cnt);
	}
    fclose(fp);
}
void searchEmpSalary()
{
	int lsalary,msalary;
	printf("Enter minimum salary : ");
	scanf("%d",&lsalary);
	printf("Enter maximum salary : ");
	scanf("%d",&msalary);
	struct employee emp;
	FILE *fp;
	fp = fopen("employee_data","r");
	if(fp == NULL)
	{
		printf("File is not created successfully....\n");
		exit(-1);
	}
	int cnt=0;
    printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-5s %-15s %-12s %-15s %-15s %-15s %-10s %-15s %-25s\n",
           "ID","Name","JoinDate","Phone","Qualification","Designation","Salary","AccountNo","Email");
	printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	while((fread(&emp,sizeof(emp),1,fp)))
    {
    	if(emp.salary > lsalary && emp.salary < msalary)
    	{
    		printf("%-5d %-15s %02d/%02d/%04d %-17lld %-15s %-15s %-10d %-15lld %-25s\n",
	   	        emp.empid,emp.name,emp.jd.day,emp.jd.month,emp.jd.year,emp.phoneno,
    	        emp.qualification,emp.designation,emp.salary,emp.accno,emp.email);
    		cnt++;
		}
	}
printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
	fclose(fp);
	printf("\n%d records found\n",cnt);
}
void deleteEmpMenu()
{
	printf("\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|     TVS Management System      |\n");
	printf("\t\t\t\t|--------------------------------|\n");
	printf("\t\t\t\t|*******Delete Employee Menu*****|\n");
	printf("\t\t\t\t+--------------------------------+\n");
	printf("\t\t\t\t|1.  Delete By Employee Id       |\n\n");
	printf("\t\t\t\t|2.  Delete By Employee Name     |\n\n");
	printf("\t\t\t\t|3.  Exit                        |\n\n");
	printf("\t\t\t\t+--------------------------------+\n");
}
void deleteEmp()
{
	int choice;
 	do
 	{
 		again:
 		deleteEmpMenu();
		 switch(choice)
		 {
		 	case 1:
		 		deleteEmpByEmpId();
		 		break;
		 	case 2:
		 		deleteEmpByName();
		 		break;
		 	case 3:
		 		printf("Exiting from soting menu\nThank you visit again :)\n");
				break;
			default:
				printf("Invalid choice\nTry again...\n\n");
				goto again;
		 		break;
		 }
	}while(choice != 3);
}
void deleteEmpByEmpId()
{
	struct employee emp;
	int i=0,cnt=0,empid;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter employee id to delete : ");
	scanf("%d",&empid);
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
			cnt++;	
	}
	if(cnt == 0)
	{
		printf("\nInvalid Sr no...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(emp.empid == empid)
			continue;
		else
			fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord deleted successfully...\n");

}
void deleteEmpByName()
{
	struct employee emp;
	char name[20];
	int i=0,cnt=0;
	FILE *fp,*fp1;
    fp = fopen("employee_data","r");
    fp1 = fopen("temp.txt","w");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    again:
    cnt = 0;
	printf("Enter name to delete : ");
	scanf("%s",name);
	name[0] = toupper((char)name[0]);
    while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(strcmp(emp.name,name) == 0)
			cnt++;	
	}
	if(cnt == 0)
	{
		printf("\nInvalid Sr no...\nTry again\n");
		fseek(fp,0,SEEK_SET);
		goto again;
	}
	fseek(fp,0,SEEK_SET);
	 while((fread(&emp,sizeof(emp),1,fp)))
	{
		if(strcmp(emp.name,name) == 0)
			continue;
		else
			fwrite(&emp,sizeof(emp),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	fp = fopen("employee_data","w");
    fp1 = fopen("temp.txt","r");
    if(fp == NULL || fp1 == NULL)
    {
        printf("File is not created successfully...");
        exit(-1);
    }
    while((fread(&emp,sizeof(emp),1,fp1)))
	{
		fwrite(&emp,sizeof(emp),1,fp);
	}
    fclose(fp);
	fclose(fp1);
	printf("\n\nRecord deleted successfully...\n");
}
void checkPass1()
{
	struct employee emp;
	FILE *f1;
	f1 = fopen("employee_data","r");
	if(f1 == NULL)
	{
		printf("File is not created sucessfully...\n");
		exit(-1);
	}
	int id;
	long long pass;
	again:
	printf("\t\t+---------------------------+\n");
	printf("\t\t Enter id : ");
	scanf("%d",&id);
	printf("\n\t\t+---------------------------+\n");
	printf("\t\tEnter password : ");
	scanf("%lld",&pass);
	printf("\n\t\t+---------------------------+\n");
	int flag = 0;
	while(fread(&emp,sizeof(emp),1,f1))
	{
		if(id == emp.empid && pass == emp.phoneno)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("Invalid id or password\nTry again...\n\n");
		fseek(f1,0,SEEK_SET);
		goto again;
	}
	else
	{
		greet(id);
	}
	fclose(f1);
}
void checkPass2()
{
	char id[10],pass[20];
	again:
	printf("\t\t+---------------------------+\n");
	printf("\t\t Enter id : ");
	scanf("%s",id);
	printf("\t\t+---------------------------+\n");
	printf("\t\t Enter password : ");
	scanf("%s",pass);
	printf("\t\t+---------------------------+\n");
	int flag = 0;	
	if(strcmp(id,"admin") == 0 && strcmp(pass,"Admin@123") == 0)
	{
		flag = 1;
	}
	if(flag == 0)
	{
		printf("Invalid id or password...\nTry again");
		goto again;
	}
	
}
void greet(int id)
{
	struct employee emp;
	FILE *f1;
	f1 = fopen("employee_data","r");
	if(f1 == NULL)
	{
		printf("File is not created sucessfully...\n");
		exit(-1);
	}
	while(fread(&emp,sizeof(emp),1,f1))
	{
		if(id == emp.empid)
		{
			printf("\nHello %s , Welcome back to TVS management system\nHave a nice day\n\n",emp.name);
		}
	}
	fclose(f1);
}
