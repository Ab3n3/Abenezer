// PROGRAM TO CREATE STUDENT MANAGEMENT SYSTEM
// SUBMITED TO MR. DANIEL KAHSU
//PASSWORD => 1234

#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;

const int MAX_COURSES = 60;
const int MAX_CREDIT = 21;

// defination of STUDENT class.........
class student
{
 private:
 	float sub[MAX_COURSES];
 	string course[MAX_COURSES];
 	int credit[MAX_COURSES];
    string s_name,m_name,f_name,dpt,section,id_no,rgln,year,grade,result,phone;
    unsigned int dd,mm,yy;
    int numCourses, total; 
    int payment, paycredit, payservice;
    float per,sum;
    char sex;
 public:
    void menu(); //display menu
    void insert(); // insert record
        void personal_info(); //intake personal info
        void acadamy_info();  //intake accadamic info
    void display(); //display existing record from data
        void show(); // output all info
        void show(string s);
    void deleted(); // delete a single student info
    void deleteall(); // delate all dada record once
    void search(); // searching option
        void searcher(char cho); // perform general search from record
    void group(); //grouping option
        char groupdpt(); 
        char regulation(char &dptchoice);
        char entry(char &rglnchoice,char &dptchoice);
        void sectioner(); //char entryyear, char rglnchoice, char dptchoice
    void edit();
        void adder();
        void droper();   
	void display_payment();
};
//accept section as a parameter and display information in that section
void student::show(string s)
{
	system("cls");
	fstream file;
	string sho;
	sho=s;

    file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	    file.close();	
				
	}
	else
	{
		file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		while(!file.eof())
		{
			if(sho==section)
			{
				system("cls");
				show();
				system("pause");
			}else if(sho!=section)
			{
				cout<<"\n\n\n\n\n\n\t\t\t\t\t ---------------------------------------------------------------------------------------"<<endl;
				cout<<"\n\n\n\t\t\t\t\t\t\t THERE IS NO STUDENT IN THIS SECTION ..."<<endl;
				cout<<"\n\n\n\t\t\t\t\t ---------------------------------------------------------------------------------------"<<endl;
				system("pause");
			}
			  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		      for(int i=0; i<numCourses; i++)
		      {
		  	    file>>course[i]>>credit[i]>>sub[i];
		      }
		       file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		}
    }
    file.close();
}
			
//show/ dispaly record detail function defination
void student::show()
{
	         if(dpt=="CD")
	         {
	         	cout<<"\t Department  : "<<"COMPTER SCIENCE"<<endl;
			 }
	         else if(dpt=="MD")
	         {
	         	cout<<"\t Department  : "<<"MARKETING MANAGEMENT"<<endl;
			 }
	         else if(dpt=="AD")
	         {
	         	cout<<"\t Department  : "<<"ACCOUNTING AND FINANCE"<<endl;
			 }
	        
	   		 cout<<"\t Section     : "<<section<<endl;
	   		 
	   		 
	   		 cout<<"\n\n\t STUDENT'S NAME : "<<s_name;
	   		 cout<<"\t\t\t\t\t ID NO : "<<id_no<<endl;
	   		 cout<<"\n\t FATHER'S NAME : "<<f_name;
	   		 cout<<"\t\t\t\t\t DATE OF BIRTH : "<<dd<<" / "<<mm<<" / "<<yy<<endl;
	   		 cout<<"\n\t MOTHER'S NAME : "<<m_name;
	   		 if(rgln=="REG")
	         {
	         	cout<<"\t\t\t\t\t Regulation : "<<"REGULAR"<<endl;
			 }
	         else if(rgln=="EXT")
	         {
	         	cout<<"\t\t\t\t\t Regulation : "<<"EXTENSION"<<endl;
			 }
			 if(sex=='M')
	         {
	         	cout<<"\n\t GENDER : MALE";
			 }
	         else if(sex=='F')
	         {
	         	cout<<"\n\t GENDER : FEMALE";
			 }
	   		 
	   		 cout<<"\t\t\t\t\t\t ENTRY YEAR : "<<year<<endl;
	   		 cout<<"\n\t PHONE : "<<phone;
	   		 time_t now=time(0);
			 char * dt=ctime(&now);
			 tm *gmtm = gmtime(&now);
			 dt=asctime(gmtm);
			 cout<<"\t\t\t\t\t DATE AND TIME : "<<dt<<endl;
	   	cout<<"\n\t+--------------------------------------------------------------------------------------------------+";               
		cout<<"\n\t|  SUBJECT NAME \t|   CREDIT HOUR    |  MARK OBTAINED   |   OUT OF   |   AVERAGE   |  GRADE  |";
		cout<<"\n\t+--------------------------------------------------------------------------------------------------+"<<endl;
		for(int i=0; i<numCourses; i++)
	    {
	    	//if(course[i].size()<=12)
	    	if(i==numCourses/2)
			{
				if(course[i].size()<=12)
				{
					cout<<"\t|  "<< course[i]   <<"\t\t\t"<<credit[i]<<"\t\t  "<< sub[i] <<"\t\t  "<<100 <<"\t\t "<<fixed<<setprecision(2)<<per<<"%    \t"<<grade<<"  |"<<endl;
				}else
				if(course[i].size()>12)
				{
				    cout<<"\t|  "<< course[i]   <<"\t\t"<<credit[i]<<"\t\t  "<< sub[i] <<"\t\t  "<<100 <<"\t\t "<<fixed<<setprecision(2)<<per<<"%    \t"<<grade<<"  |"<<endl;
	
				}
			}else
			{
				if(course[i].size()<=12)
				{
					cout<<"\t|  "<< course[i]  <<"\t\t\t"<< credit[i]  <<"\t\t  "<<fixed<<setprecision(2)<< sub[i] <<"\t\t  "<<100 <<"  \t\t\t\t   |"<<endl;
				}else
				if(course[i].size()>12)
				{
					cout<<"\t|  "<< course[i]  <<"\t\t"<< credit[i]  <<"\t\t  "<<fixed<<setprecision(2)<< sub[i] <<"\t\t  "<<100 <<"  \t\t\t\t   |"<<endl;
				}
			}		
	    }
	    cout<<"\t+--------------------------------------------------------------------------------------------------+"<<endl;
	    cout<<"\n\t\t   TOTAL CREDIT HOUR : "<<total<<"\t TOTAL : "<<sum<<"\t\t\t RESULT - "<<result<<endl;
		   	
	    cout<<"\n\t Dated : ";
		cout<<"\t\t\t\t\t\t   Principle Signatures : "<<endl;
	    cout<<"\n\t-----------------------------------------------------------------------------------------------------"<<endl;
}

//defination personal info fill function...
void student::personal_info()
{
   cout<<"\t\t\t--> ENTER YOUR NAME : ";
   cin>>s_name;
   cout<<"\t\t\t--> ENTER MOTHER NAME : ";
   cin>>m_name;
   cout<<"\t\t\t--> ENTER FATHER NAME : ";
   cin>>f_name;
   cout<<"\t\t\t--> ENTER YOUR GENDER [M/F] : ";
   cin>>sex;
      if(sex!='M'&& sex!='F')
     {
	  do
	  {
	  	cout<<"\t\t\t\t...INVALID INPUT press [M] for male, [F] for female..."<<endl;
   	    cout<<"\t\t\t--> ENTER YOUR GENDER [M/F] : ";
        cin>>sex;
	  }while(sex!='M' && sex!='F');
     }
   cout<<"\t\t\t--> ENTER BIRTH DATE (DD/MM/YY) : \n";
   cout<<"\t\t\t\t--> ENTER DAY (DD) : ";
   cin>>dd;
     if(dd<=0 || dd>30)
     {
	  do
	  {
	  	cout<<"\t\t\t\tINVALID INPUT DAY SHOUD BE BETWEEN (1-30)..."<<endl;
   	    cout<<"\t\t\t\t--> ENTER DAY (DD) : ";
        cin>>dd;
	  }while(dd<=0 || dd>30);
     }
   cout<<"\t\t\t\t--> ENTER MONTH (MM) : ";
   cin>>mm;
     if(mm<=0 || mm>12)
     {
	  do{
	  	cout<<"\t\t\t\tINVALID INPUT MONTH SHOUD BE BETWEEN (1-12)..."<<endl;
   	    cout<<"\t\t\t\t--> ENTER MONTH (MM) : ";
        cin>>mm;
	  }while(mm<=0 || mm>12);
     }
   cout<<"\t\t\t\t--> ENTER YEAR (YY) : ";
   cin>>yy;
     if(yy<=1900 || yy>2005)
     {
	  do
	  {
	  	cout<<"\t\t\t\t..INVALID INPUT YEAR SHOUD BE BETWEEN (1900 - 2005)..."<<endl;
   	  	cout<<"\t\t\t\t--> ENTER YEAR (YY) : ";
      	cin>>yy;
	  }while(yy<=0 || yy>2005);
     }
     cout<<"\t\t\t--> ENTER PHONE NUMBER : ";
     cin>>phone;
}

//acadamic related info fill sunction
void student::acadamy_info()
{
  string tsection, tid_no;
  char choice = 'y', test;
  int testTotal=0;
  numCourses=0;
  sum=0;
  per=0;
  total=0;
  cout<<"\t\t\t--> ENTER DEPARTMENT [COMPUTER_SCIENCE - CD] [MARKETING - MD] [ACCOUNTING - AD] : ";
  cin>>dpt;
       if(dpt!="CD"&& dpt!="MD" && dpt!="AD")
		  {
		   do
			{
			  	cout<<"\t\t\t...INVALID INPUT insert [CD] for computer sc, [MD] for management, [AD] for accounting..."<<endl;
		   	    cout<<"\t\t\t--> ENTER DEPARTMENT [COMPUTER_SCIENCE - CD] [MARKETING - MD] [ACCOUNTING - AD] : ";
                 cin>>dpt;
			}while(dpt!="CD"&& dpt!="MD" && dpt!="AD");
		  }
	   cout<<"\t\t\t--> ENTER REGULATION [REGULAR - REG ] [EXTENSION - EXT] : ";
  	   cin>>rgln;
  	      if(rgln!="REG"&& rgln!="EXT")
		     {
			  do
			  {
			  	cout<<"\t\t\t\t...INVALID INPUT insert [REG] for regular, [EXT] for extension..."<<endl;
		   	    cout<<"\t\t\t--> ENTER REGULATION [REGULAR - REG ] [EXTENSION - EXT] : ";
  	   			cin>>rgln;
			  }while(rgln!="REG"&& rgln!="EXT");
		     }
       cout<<"\t\t\t--> ENTER YEAR OF ENTRY ONLY IN BETWEEN [2012 - 2015]: ";
       cin>>year;
            if(year!="2012"&& year!="2013" && year!="2014"&& year!="2015")
		     {
			  do
			  {
			  	cout<<"\t\t\t\t...INVALID INPUT..."<<endl;
		   	    cout<<"\t\t\t--> ENTER YEAR OF ENTRY ONLY IN BETWEEN [2012 - 2015]: ";
      			cin>>year;
			  }while(year!="2012"&& year!="2013" && year!="2014"&& year!="2015");
		     }
   	   cout<<"\t\t\t--> ENTER SECTION [ A / B / C] : ";
  	   cin>>tsection;
  	         if(tsection!="C" && tsection!="B" && tsection!="A")
		     {
			  do
			  {
			  	cout<<"\t\t\t\t...INVALID INPUT ..."<<endl;
		   	    cout<<"\t\t\t--> ENTER SECTION [ A / B / C] : ";
  	            cin>>tsection;
			  }while(tsection!="C" && tsection!="B" && tsection!="A");
		     }
   	   cout<<"\t\t\t--> ENTER ID NUMBER [USING COUNTING NUMBERS ONLY] : ";
   	   cin>>tid_no;
   	   cin.ignore();
  if(dpt=="CD")
   {
   	     if(rgln=="REG")
   	     {
   	     	id_no="RCD/"+tid_no+"/"+year;
   	     	section="RCD"+year+tsection;
		 }else
		 {
		 	section="ECD"+year+tsection;
		 	id_no="ECD/"+tid_no+"/"+year;
		 }   
   }else
   // TAKING marketing students detail
   if(dpt=="MD")
   {
   	     if(rgln=="REG")
   	     {
   	     	id_no="RMD/"+tid_no+"/"+year;
   	     	section="RMD"+year+tsection;
		 }else
		 {
		 	id_no="EMD/"+tid_no+"/"+year;
		 	section="EMD"+year+tsection;
		 }
   }
   
 //taking accounting students info... 
 if(dpt=="AD")
   {
   	     if(rgln=="REG")
   	     {
   	     	id_no="RAD/"+tid_no+"/"+year;
   	     	section="RAD"+year+tsection;
		 }else
		 {
		 	id_no="EAD/"+tid_no+"/"+year;
		 	section="EAD"+year+tsection;
		 }
   }  
       system("cls");
       cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t\t ENTER COURSE DETAIL "<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t REMARK: please don't use space to separate between words"<<endl;
	   cout<<"\t\t\t\t         instade you can useunderscore(_)"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
        while (choice == 'y' || choice == 'Y') {
	        if (numCourses >= MAX_COURSES) {
	            cout << "\t\t\t...Maximum number of courses reached [10 course max]..." << endl;
	            break;
	        }
			if(total>=MAX_CREDIT)
	        {
	        	cout << "\t\t\tMaximum number of credit hour reached [21hr max]..." << endl;
	            break;
			}
			cout << "\t\t\t--> ENTER COURSE NAME: ";
	        getline(cin,course[numCourses]);
	        
	        cout << "\t\t\t--> ENTER CREDIT HOUR OF COURSE: ";
	        cin>>credit[numCourses];
	           if(credit[numCourses]<=0 || credit[numCourses]>4)
			     {
				  do
				  {
				  	cout<<"\t\t\t\t...INVALID INPUT CREDIT HOUR SHOULD BE BETWEEN 1-4..."<<endl;
			   	  	cout << "\t\t\t--> ENTER CREDIT HOUR HOUR OF COURSE: ";
	        		cin>>credit[numCourses];
				  }while(credit[numCourses]<=0 || credit[numCourses]>4);
			     }
			     testTotal+=credit[numCourses];
			     if(testTotal>=MAX_CREDIT)
		         {
		        	cout << "\t\t\t...Maximum number of credit hour reached [21hr max]..." << endl;
		            break;
				 }
				 total+=credit[numCourses];
			     cin.ignore();
			     
			     sub[numCourses]=0;
	        cin.ignore();
	        
	        numCourses++;
	        cout << "\n--> DO YOU WANT TO ADD ANOTHER COURSE? [Y/N]: ";
	        cin >> choice;
	        cin.ignore();
       }
       sum=0;
       per=0;
       grade="-";
       result="-";
       ///////payment registration////////
        system("cls");
       cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t\t PAYMENT DETAIL "<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
	   cout<<"\t\t\t REMARK 1: PAYMENT PER 1 CREDI HOUR IS $250 (it might change)"<<endl;
	   cout<<"\t\t\t REMARK 2: PAYMENT FOR ANY SERVICE IS $500"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------\n"<<endl;	
	   cout<<"\n\t\t\t ENTER AMOUNT OF MONEY TO PAY PER CREDIT HOUR: ";
	   cin>>paycredit;
	   cout<<"\n\t\t\t ENTER AMOUNT OF SERVICE PAYMENT: ";
	   cin>>payservice;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   	  cout << "\n\t\t\t--> YOU HAVE APPLIED TO BE REGISTERED ON THE FOLLOWING COURSES : "<<endl;
	   	  cout<<"\n\t\t\t   COURSE --- CREDITHOUR"<<endl;
	   	  for(int i=0; i<numCourses; i++)
            {
            	cout<<"\n\t\t\t "<<i+1<<". "<<course[i]<<" --- "<<credit[i]<<endl;
			}
		  cout<<"\t\t\t---------------------------------------------------------\n"<<endl;
		  cout<<"\n\t\t\t FOR "<<total<<" CREDITHOUR AND INCLUDING THE SERVICE FEE YOU HAVE TO PAY: "<<endl;
		  cout<<"\n\t\t\t FOR CREDIT HOURS: "<<total<<"CREDITHOUR"<<" * "<<paycredit<<"$ = $"<<total*paycredit<<endl;
		  cout<<"\n\t\t\t FOR SERVICE FEE: $"<<payservice<<endl;
		  cout<<"\n\t\t\t TOTAL PAYMENT: $"<<(total*paycredit)+payservice<<endl;
		  cout<<"\t\t\t---------------------------------------------------------\n"<<endl;
		  cout<<"\t\t\t ARE YOU ABLE TO PAY $"<<(total*paycredit)+payservice<<" [Y/N]"<<endl;
		  cout<<"\t\t\t --> ENTER CHOICE: ";
		  cin>>test;
		  if(test=='Y'||test=='y')
		  {
		  	payment=(total*paycredit)+payservice;
		  }else if(test=='N'||test=='n')
		  {
		  	payment=0;
		  }
}
//course drop function defination
void student::droper()
{
  char choice = 'y';
  int index=-1;
  string tempcourse;
  sum=0;
  per=0;
  string tempcourses;
  int tempcredit;
  float tempsub;
  L:
       system("cls");
       cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t\t\t\t DROP COURSE DETAIL "<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t REMARK 1: please don't use space to separate between words"<<endl;
	   cout<<"\t\t\t\t         instade you can use underscore(_)"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
	   cout<<"\t\t\t REMARK 2: STUDENT MINIMUM CREDIT HOUR IS (4 Hr)."<<endl;
	   cout<<"\t\t\t REMARK 2: STUDENT MINIMUM COURSE NUMBER IS (2 courses.)"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
       while (choice == 'y' || choice == 'Y') {
	        if (numCourses <=2) {
	            cout << "\t\t\t...Minimun number of courses reached [2 course min]..." << endl;
	            getch();
	            break;
	        }
			if(total<=4)
	        {
	        	cout << "\t\t\t...Minimun number of credit hour reached [4hr min]..." << endl;
	        	getch();
	            break;
			}
            cout << "\n\t\t\t--> YOU HAVE BEEN REGISTERED FOR THE FOLLOWING COURSES: "<<endl;
            for(int i=0; i<numCourses; i++)
            {
            	cout<<"\n\t\t\t "<<i+1<<". "<<course[i]<<endl;
			}
			cout << "\n\t\t\t--> ENTER COURSE NAME YOU WANT TO DROP: ";
	        cin>>tempcourse;
	        
	        for(int i=0; i<numCourses;i++)
	        {
	        	if(course[i]==tempcourse)
	        	{
	        		index=i;
	        		break;
				}
			}
			
			if(index==-1)
			{
				cout<<"n\t\t\t ...SORRY COURSE NAME YOU HAVE INSERTED NOT FOUND press any key to continue... "<<endl;
				getch();
				goto L;
			}
			tempcredit=credit[index];
			total=total-credit[index];
			numCourses--;
			
			cout << "\n\t\t\t... YOU HAVE SUCCESSFULLY DROPED ["<<tempcourse<<"] COURSE..."<<endl;
			for(int i=index; i<numCourses; i++)
			{
				course[i]=course[i+1];
				credit[i]=credit[i+1];
				sub[i]=sub[i+1];
			}
	        cout << "\n\t\t\t... YOU WILL BE AUTOMATICALLY REFUNDED ["<<tempcourse<<"] COURSE MONEY..."<<endl;
	        cout << "\n\t\t\t... AMOUNT OF MONEY :  "<<tempcredit<<" HOUR * $"<<paycredit<<" = "<<tempcredit*paycredit<<endl;
	        cout << "\n--> DO YOU WANT TO DROP ANOTHER COURSE? [Y/N]: ";
	        cin >> choice;
	        cin.ignore();
       }
       sum=0;
       per=0;
       grade="-";
       result="-";
}

//defination of course add function
void student::adder()
{
  char choice = 'y';
  int testTotal=total;
  int testcredit;
  sum=0;
  per=0;
       system("cls");
       cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t\t\t\t   ADD COURSE DETAIL "<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t REMARK 1: please don't use space to separate between words"<<endl;
	   cout<<"\t\t\t\t         instade you can use underscore(_)"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
	   cout<<"\t\t\t REMARK 2: STUDENT MAXIMUM CREDIT HOUR IS (21 Hr)."<<endl;
	   cout<<"\t\t\t REMARK 2: STUDENT MAXIMUM COURSE NUMBER IS (60 courses.)"<<endl;
	   cout<<"\t\t\t---------------------------------------------------------"<<endl;
        while (choice == 'y' || choice == 'Y') {
	        if (numCourses >= MAX_COURSES) {
	            cout << "\t\t\t...Maximum number of courses reached [10 course max]..." << endl;
	            break;
	        }
			if(total>MAX_CREDIT)
	        {
	        	cout << "\t\t\tMaximum number of credit hour reached [21hr max]..." << endl;
	            break;
			}
			cout << "\t\t\t--> ENTER COURSE NAME: ";
	        getline(cin,course[numCourses]);
	        
	        cout << "\t\t\t--> ENTER CREDIT HOUR OF COURSE: ";
	        cin>>credit[numCourses];
	           if(credit[numCourses]<=0 || credit[numCourses]>4)
			     {
				  do
				  {
				  	cout<<"\t\t\t\t...INVALID INPUT CREDIT HOUR SHOULD BE BETWEEN 1-4..."<<endl;
			   	  	cout << "\t\t\t--> ENTER CREDIT HOUR HOUR OF COURSE: ";
	        		cin>>credit[numCourses];
				  }while(credit[numCourses]<=0 || credit[numCourses]>4);
			     }
			     testcredit=total;
			     testTotal+=credit[numCourses];
			     if(testTotal>MAX_CREDIT)
		         {
		        	cout << "\t\t\t...Maximum number of credit hour reached [21hr max]..." << endl;
		            break;
				 }
				 total+=credit[numCourses];
			     cin.ignore();
			     sub[numCourses]=0;
	        
	        cout << "\n\t\t\t... YOU HAVE TO PAY ["<<course[numCourses]<<"] COURSE MONEY..."<<endl;
	        cout << "\n\t\t\t... AMOUNT OF MONEY :  "<<total-testcredit<<" HOUR * $"<<paycredit<<" = "<<(total-testcredit)*paycredit<<endl;
	        numCourses++;
	        cout << "\n--> DO YOU WANT TO ADD ANOTHER COURSE? [Y/N]: ";
	        cin >> choice;
	        cin.ignore();
       }

   // calculate total marks, percentage and grade..........
       sum=0;
       per=0;
       grade="-";
       result="-";

}
// load and check password function defination
void start()
{
	system("Color F0");
	string pass;
	string password="1234";
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\tENTER PASSWORD PLEASE: ";
	cin>>pass;
	
	if(pass!= password)
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	    cout<<"\t\t\t\t\t\t\t\t   ...INVALID PASSWORD..."<<endl;
	    cout<<"\t\t\t\t\t\t\t\tPLEASE ENTER VALID PASSWORD : ";
	    cin>>pass;
	}while(pass!= password);
	
	system("cls");
	system("Color F9");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t\tLoading ";
	char x=219;
	
	for(int i=0; i<35; i++)
	{
		cout<<x;
		if(i<10)
		Sleep(300);
		if(i>=10 && i<20)
		Sleep(150);
		if(i>=10);
		Sleep(25);
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\tWELCOME TO EXELENCE STUDENT MANAGEMENT SYSTEM "<<endl;;
	cout<<"\t\t\t\t\t\t\t     press any key to continue please... "<<endl;
	getch();
	
}
//defination of color function...
void color()
{
	s:
    system("cls");
	char input, c;
	do
	{
		cout<<"\n\n\t\t\t\t-------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t|    COLOR MANAGEMENT SYSTEM                          |"<<endl;
    	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
    	cout<<"\t\t\t\t A. FOR GREEN TEXT"<<endl;
   		cout<<"\t\t\t\t B. FOR PURPLE TEXT"<<endl;
   		cout<<"\t\t\t\t C. FOR YELLOW TEXT"<<endl;
    	cout<<"\t\t\t\t D. FOR BLUE TEXT"<<endl;
    	cout<<"\t\t\t\t E. FOR AQUA TEXT"<<endl;
    	cout<<"\t\t\t\t F. FOR BLUE TEXT BY WHITE BACKGROUND "<<endl;
    	cout<<"\t\t\t\t G. FOR RED TEXT BY WHITE BACKGROUND "<<endl;
    	cout<<"\t\t\t\t H. FOR BLACK TEXT BY WHITE BACKGROUND "<<endl;
    	cout<<"\t\t\t\t I. BACK TO MAIN MENU "<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
        cout<<"\t\t\t\t  Choose Option : [ A / B / C / D / E / F / G / H / I ]"<<endl;
    	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
        cout<<"\n --> PLEASE ENTER YOUR CHOICE : ";
		cin>>c;
		
		input = toupper(c);
		switch(input)
		{
			case 'A':
				system("cls");
				system("Color 0A");
				break;
			case 'B':
				system("cls");
				system("Color 0D");
				break;
			case 'C':
				system("cls");
				system("Color 0E");
				break;
			case 'D':
				system("cls");
				system("Color 09");
				break;
			case 'E':
				system("cls");
				system("Color 0B");
				break;
			case 'F':
				system("cls");
				system("Color F9");
				break;
			case 'G':
				system("cls");
				system("Color FC");
				break;
			case 'H':
				system("cls");
				system("Color F0");
				break;
			case 'I':
				if(input=='I')
				{
					student s;
			    	s.menu();
				}
				break;
			default:
				cout<<"\n\t\t\t\t -->INVALID CHOICE PRESS ANY KEY TO CONTINUE... "<<endl;
				break;
		}
	}while(input=='A' || input=='B' || input=='C' || input=='D' || input=='E' || input=='F' || input=='G' || input=='H' || input=='I');
      getch();
      goto s;
}

//defination about programmers function
void about()
{
	system("cls");
	 string abt="\t\t\t\t\t\t ABOUT PROGRAMMERS";
	 string we="\t\t THIS STUDENT MANAGEMENT SYSTEM IS DEVELOPED BY THE FOLLOWING St.marry's UNIVERSITY STUDENTS: \n";
     string nam="\t\t NAME: FEYESEL SULTAN          SECTION: RCD2014C             ID: RAD/0321/2014\n\n\t\t NAME: ABENEZER BERHANU        SECTION: RCD2014C             ID: RCD/0748/2014\n\n\t\t NAME: KIRUBEL WASIHUN         SECTION: RCD2014C             ID: RCD/0780/2014\n\n\t\t NAME: SAMUEL HAYMANOT         SECTION: RCD2014C             ID: RCD/0600/2013";
     string thank="\t\t\t\t\t    THANK YOU FOR YOUR SUPPORT!";
   int inum = we.length();
   int fnum = nam.length();
	cout<<"\n\n\t\t ---------------------------------------------------------------------------------------------"<<endl;
	for(int i=0; i< abt.length(); i++)
	{
		cout<<abt.at(i);
		if(i<abt.length())
		Sleep(30);
	}
    cout<<"\n\n\t\t ---------------------------------------------------------------------------------------------"<<endl;
  
   
   for(int i=0; i<inum; i++)
   {
   	 cout<<we.at(i);
   	 if(i<inum)
   	 Sleep(25);
   	 
   }
   cout<<endl;
   for(int i=0; i<fnum; i++)
   {
   	 cout<<nam.at(i);
   	 if(i<fnum)
   	 Sleep(25);
   	 
   }
   
    cout<<endl;
   	cout<<"\n\n\t\t ---------------------------------------------------------------------------------------------"<<endl;
   	for(int i=0; i<thank.length(); i++)
   	{
   		cout<<thank.at(i);
   		if(i<thank.length())
   		Sleep(25);
	}cout<<endl;
   	cout<<"\n\t\t ---------------------------------------------------------------------------------------------"<<endl;
}

// defination of menu function.........
void student::menu()
{   start:
	system("cls");
	int choice;
	char x;
    system("Color F0");
	cout<<"\n\n\t\t\t\t------------------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t|                 STUDENT MANAGEMENT SYSTEM                      | "<<endl;
    cout<<"\t\t\t\t------------------------------------------------------------------"<<endl;	
    cout<<"\t\t\t\t 1. ENTER    NEW STUDENT RECORD "<<endl;
    cout<<"\t\t\t\t 2. LIST     ALL STUDENTS RECORD "<<endl;
    cout<<"\t\t\t\t 3. DELETE   SPECIFIC STUDENT RECORD "<<endl;
    cout<<"\t\t\t\t 4. DELETE   ALL STUDENT RECORD "<<endl; //**
    cout<<"\t\t\t\t 5. SEARCH   STUDENT RECORD "<<endl; //**by bdate
    cout<<"\t\t\t\t 6. UPDATE   STUDENT RECORD "<<endl;//**
    cout<<"\t\t\t\t 7. GROUP    STUDENT RECORD "<<endl;
    cout<<"\t\t\t\t 8. PAYMENT  DETAIL "<<endl;
    cout<<"\t\t\t\t 9. COLOR    CHANGE"<<endl;
    cout<<"\t\t\t\t 10.ABOUT    PROGRAMMERS "<<endl;
    cout<<"\t\t\t\t 0. EXIT "<<endl;
    cout<<"\t\t\t\t------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t  CHOICE OPTIONS : [ 0 / 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9 / 10 ]"<<endl;
    cout<<"\t\t\t\t------------------------------------------------------------------"<<endl;
    cout<<" --> Please Enter Your Choice : ";
    cin>>choice;
    
    switch(choice)
    {
    	case 1:
    	do
    	{
    		insert();
    		system("cls");
    		cout<<"\n--> DO YOU WANT TO ADD ANOTHER STUDENT RECORD [Y/N] ?";
    		cin>>x;
		}while(x=='Y'||x=='y');
    	break;
		
	    case 2:
	   		display();
	   		break;
	   	case 3:
	   		deleted();
	   		break;
	   	case 4:
	   		deleteall();
	   		break;
	   	case 5:
	   		search();
	   		break;
	   	case 6:
	   		edit();
	   		break;
	   	case 7:
	   		group();
	   		break;
	   	case 8:
	   		display_payment();
	   		break;
	   	case 9:
		    color();
			break;	
		case 10:
		    about();
			break;
		case 0:
			exit(0);
		default:
			cout<<"\n -->INVALID INPUT PRESS ANY KEY TO CONTINUE..."<<endl;
			//system("pause");
			
	}
	getch();
    goto start;
}

// defination of insert function... to add student records.......
void student::insert()
{
	   fstream file;
	   system("cls");
	   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
	   cout<<"\t\t\t\t\t | 	REGISTER STUDENT DETAIL |"<<endl;
	   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	   personal_info(); //student personal info name age..
	   acadamy_info(); //student acadamic related info section grade....
   
	 // creating a file STUDENTRESULT.TXT to store the records of stuednts........
	   file.open("student.txt",ios::out | ios::app);
	  file<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
	  for(int i=0; i<numCourses; i++)
	  {
	  	file<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
	  }
	  file<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
	   file.close();
}

// defination of display function........
void student::display()
{
	system("cls");
	fstream file;
	
   cout<<"\n\n-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t   | Student Result Table |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    
   file.open("student.txt",ios::in);
   if(!file)
   {
      cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
   
   }
   else
   {
	   	  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
   	   while(!file.eof())
   	   {
   	   	show();
   	   	
		  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;  
	   }	   
   }
     file.close();	
}

// defination of delete specific record function...........
void student::deleted()
{
	system("cls");
	fstream file,file1;
	string temp;
	int found=0;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | Delete Student Record |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   
    file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
				
	}
	else
	{
		cout<<"\n\t\t\t--> ENTER ID_NUMBER OR FIRST_NAME OF STUDENT TO BE DELETED : ";
		cin>>temp;
		file1.open("temp.txt",ios::out | ios::app);
		
		  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		while(!file.eof())
		{
			if(temp!=id_no && temp!=s_name)
			{
				 file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
				  for(int i=0; i<numCourses; i++)
				  {
				  	file1<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
				  }
				  file1<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
			}
			else
			{  
			   found++;  //DELEDT
			}	
			file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  	for(int i=0; i<numCourses; i++)
		  	{
		  	file>>course[i]>>credit[i]>>sub[i];
		  	}
		  	file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t THER IS NO STUDENT WITH THAT ID OR FIRST NAME...!!! ";
		}else
		if(found!=0)
		{
			  cout<<"\n\t\t\t RECORD IS SUCCESSFULLY DELETED...";
		}
		file.close();
		file1.close();
		
		remove("student.txt");
		rename("temp.txt","student.txt");
	}		
}

//delete all record function
void student::deleteall()
{
	system("cls");
	fstream file; //, file1;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
    cout<<"\t\t\t\t\t\t | DELETE ALL STUDENT RECORD |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   
        file.open("student.txt",ios::out);
        file.clear();
		file.close();
	cout<<"\n\t\t\t ALL STUDENTS FILE DELETED SUCCESSFULLY ......";
		
}

//general searcher function defination
void student::searcher(char cho)
{
	system("cls");
	fstream file;
	string Sname,idno,tyear, Result,tphone;
	char ch , choice, Sex;
	int found=0;
	unsigned int tdd, tmm, tyy;
	 choice=cho;

    file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	    file.close();	
				
	}
	else
	{
		if(choice=='A')
		{
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   			cout<<"\t\t\t\t\t | SEARCH STUDENT BY ID NUMBER |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t--> ENTER ID NUMBER OF STUDENT YOU WANT TO SEARCH : ";
		    cin>>idno;
		}
		else if(choice=='B')
		{
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   			cout<<"\t\t\t\t\t | SEARCH STUDENT BY NAME |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t--> ENTER FIRST NAME OF STUDENT YOU WANT TO SEARCH : ";
		    cin>>Sname;
		}
		else if(choice=='C')
		{
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   			cout<<"\t\t\t\t\t | SEARCH STUDENT BY ENTRY YEAR |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t--> ENTER ENTRY YEAR OF STUDENT YOU WANT TO SEARCH : ";
	    	cin>>tyear;
		}
		else if(choice=='D')
		{
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   			cout<<"\t\t\t\t\t | SEARCH STUDENT BY BIRTH DATE |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t--> ENTER BIRTH DATE OF STUDENT YOU WANT TO SEARCH [DD/MM/YY]: "<<endl;
			cout<<"\t\t\t\t\t\t\t --> ENTER BIRTH DAY [DD] : ";
			cin>>tdd;
			cout<<"\t\t\t\t\t\t\t --> ENTER BIRTH MONTH [MM] : ";
			cin>>tmm;
			cout<<"\t\t\t\t\t\t\t --> ENTER BIRTH YEAR [YY] : ";
		    cin>>tyy;
		}else if(choice=='E')
		{
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   			cout<<"\t\t\t\t\t | SEARCH STUDENT BY PHONE NUMBER |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\n\t\t\t--> ENTER PHONE NUMBER OF STUDENT YOU WANT TO SEARCH : ";
	    	cin>>tphone;
		}
		else if(choice=='M')
		{
			    system("cls");
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   				cout<<"\t\t\t\t\t | MALE STUDENTS RECORD |"<<endl;
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
				Sex='M';
		}
		else if(choice=='F')
		{
			    system("cls");
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   				cout<<"\t\t\t\t\t | FEMALE STUDENTS RECORD |"<<endl;
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
				Sex='F';
		}
		else if(choice=='P')
		{
			    system("cls");
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   				cout<<"\t\t\t\t\t | PASSED STUDENTS RECORD |"<<endl;
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
				Result="PASS";
		}
		else if(choice=='N')
		{
			    system("cls");
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
   				cout<<"\t\t\t\t\t | FAILED STUDENTS RECORD |"<<endl;
				cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
				Result="FAIL";
		}
		file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		for(int i=0; i<numCourses; i++)
		{
		  	file>>course[i]>>credit[i]>>sub[i];
		}
		file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		
		while(!file.eof())
		{	
			if(Result==result)
			{	
				  show();
				  found++;
			}
			if(Sex==sex)
			{
				  show();
				  found++;
			}
			if(Sname==s_name)
			{
				cout<<"\n\n\t\t\tTHERE IS STUDENT WITH THAT FIRST NAME DO YOU WANT TO SEE HIS/HER RECORD (Y/N):";
				cin>>ch;
				if(ch=='y' || ch=='Y')
				{
				  system("cls");
				  show();	
				}
				found++;
			}
			if(idno==id_no)
			{
				cout<<"\n\n\t\t\tTHERE IS STUDENT WITH THAT ID NUMBER DO YOU WANT TO SEE HIS/HER RECORD (Y/N):";
				cin>>ch;
			   if(ch=='y'|| ch=='Y')
			   {
			   	system("cls");
			   	show();
			   }
			   found++;
			}
			if(tyear==year)
			{
				cout<<"\n\n\t\t\tTHERE IS STUDENT RECORD WITH THAT ENTRY YEAR DO YOU WANT TO SEE THE RECORD (Y/N):";
				cin>>ch;
			   if(ch=='y'|| ch=='Y')
			   {
			   	system("cls");
			   	show();
			   }
			   found++;
			}
			if(tdd==dd && tmm==mm && tyy==yy)
			{
				cout<<"\n\n\t\t\tTHERE IS STUDENT WITH THAT BIRTH DATE DO YOU WANT TO SEE RECORD (Y/N):";
				cin>>ch;
			   if(ch=='y'|| ch=='Y')
			   {
			   	system("cls");
			   	show();
			   }
			   found++;
			}
			if(tphone==phone)
			{
				cout<<"\n\n\t\t\tTHERE IS STUDENT RECORD WITH THAT PHONE NUMBER DO YOU WANT TO SEE THE RECORD (Y/N):";
				cin>>ch;
			   if(ch=='y'|| ch=='Y')
			   {
			   	system("cls");
			   	show();
			   }
			   found++;
			}
			file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
			for(int i=0; i<numCourses; i++)
			{
			  	file>>course[i]>>credit[i]>>sub[i];
			}
			file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		}
		
		if(found==0)
		{
			cout<<"\n\t\t\t THERE IS NO STUDENT WITH THAT INFORMATION...!!! ";
		}
		file.close();
	}
	
	getch();
	system("cls");
}
		
//just searchining option
void student::search()
{
	l:
	system("cls");
	char c, input;
   do
   {
   	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
      cout<<"\t\t\t\t|            STUDENT SEARCH OPTION                    |"<<endl;
	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;      
	  cout<<"\t\t\t\t A. SEARCH BY ID NUMBER"<<endl;
      cout<<"\t\t\t\t B. SEARCH BY NAME"<<endl;
      cout<<"\t\t\t\t C. SEARCH BY ENTRY YEAR"<<endl;
      cout<<"\t\t\t\t D. SEARCH BY BIRTH DATE"<<endl;
      cout<<"\t\t\t\t E. SEARCH BY PHONE NUMBER"<<endl;
      cout<<"\t\t\t\t F. BACK TO MAIN MENU"<<endl;
      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
      cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D / E / F]"<<endl;
      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
      cout<<" --> PLEASE ENTER YOUR CHOICE : ";
      cin>>c;
      
      input=toupper(c);
      switch(input)
      {
      	 case 'A':
      	 	searcher(input);
      	 	break;
      	 case 'B':
      	 	searcher(input);
      	 	break;
      	 case 'C':
      	    searcher(input);
      	    break;
      	 case 'D':
      	    searcher(input);
      	    break;
      	case 'E':
      	    searcher(input);
      	    break;
      	 case 'F':
      		menu();
      		break;
      	default:
      		cout<<"\n\t\t\t\tINAVLID CHOICE PRESS ANY KEY TO CONTINUE...."<<endl;
	  }
   }while(input=='A' || input=='B' || input=='C' || input=='D' || input=='E');
   getch();
   goto l;
}

//Edit or update student record..
void student::edit()
{
	system("cls");
	fstream file,file1;
	string temp, tsection,tid_no;
	string ttsection, ttid_no;
	string success;
	int found=0;
	char input;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
   cout<<"\t\t\t\t\t\t | EDIT STUDENT RECORD |"<<endl;
   cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
   
   
    file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	  file.close();	
				
	}
	else
	{
		cout<<"\n\t\t\t--> ENTER ID_NUMBER OR FIRST_NAME OF STUDENT YOU WANT TO UPDATE : ";
		cin>>temp;
		file1.open("temp.txt",ios::out | ios::app);
		
		  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		while(!file.eof())
		{
			if(temp==id_no || temp==s_name)
			{
				do
			   {
			   	  system("cls");
			   	  cout<<"\t\t\t\t-----------------------------------------------------------------------"<<endl;	
			      cout<<"\t\t\t\t\t\t|    STUDENT RECORD UPDATE OPTION            |"<<endl;
				  cout<<"\t\t\t\t-----------------------------------------------------------------------"<<endl;      
			      cout<<"\t\t\t\t A. UPDATE STUDENT NAME"<<endl;
			      cout<<"\t\t\t\t B. UPDATE STUDENT BIRTH DATE"<<endl;
			      cout<<"\t\t\t\t C. UPDATE STUDENT GENDER"<<endl;
			      cout<<"\t\t\t\t D. UPDATE STUDENT PHONE NUMBER"<<endl;
			      cout<<"\t\t\t\t E. UPDATE STUDENT SECTION"<<endl;
			      cout<<"\t\t\t\t F. UPDATE STUDENT REGULATION"<<endl;  
			      cout<<"\t\t\t\t G. UPDATE STUDENT ID NUMBER"<<endl;
			      cout<<"\t\t\t\t H. UPDATE STUDENT DEPARTMENT"<<endl;
			      cout<<"\t\t\t\t I. ADD  COURSE"<<endl;
			      cout<<"\t\t\t\t J. DROP COURSE"<<endl;
			      cout<<"\t\t\t\t K. FILL MARKS OBTAINED"<<endl;
			      cout<<"\t\t\t\t L. DISPLAY UPDTAE"<<endl;
			      cout<<"\t\t\t\t M. BACK TO MAIN MENU"<<endl;    
			      cout<<"\t\t\t\t------------------------------------------------------------------------"<<endl;
			      cout<<"\t\t\t\t  Choose Option : [ A / B / C / D / E / F / G / H / I / J / K / L / M ]"<<endl;
			      cout<<"\t\t\t\t------------------------------------------------------------------------"<<endl;
			      cout<<" --> Please Enter Your Choice : ";
			      cin>>input;
			      input=toupper(input);
			      	 if(input=='A')
			      	 {
			      	 	system("cls");
			      	 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT FULL NAME |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
			      	 	cout<<"\t\t\t--> ENTER YOUR NAME : ";
					    cin>>s_name;
					    cout<<"\t\t\t--> ENTER MOTHER NAME : ";
					    cin>>m_name;
					    cout<<"\t\t\t--> ENTER FATHER NAME : ";
					    cin>>f_name;
			         }else if(input=='B')
			      	 {
			      	 	system("cls");
			      	 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT BIRTH DATE |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
			      	 	cout<<"\t\t\t--> ENTER BIRTH DATE (DD/MM/YY) : \n";
						cout<<"\t\t\t\t--> ENTER DAY (DD) : ";
						cin>>dd;
						     if(dd<=0 || dd>30)
						     {
							  do
							  {
							  	cout<<"\t\t\t\tINVALID INPUT DAY SHOUD BE BETWEEN (1-30)..."<<endl;
						   	    cout<<"\t\t\t\t--> ENTER DAY (DD) : ";
						        cin>>dd;
							  }while(dd<=0 || dd>30);
						     }
						 cout<<"\t\t\t\t--> ENTER MONTH (MM) : ";
						 cin>>mm;
						     if(mm<=0 || mm>12)
						     {
							  do{
							  	cout<<"\t\t\t\tINVALID INPUT MONTH SHOUD BE BETWEEN (1-12)..."<<endl;
						   	    cout<<"\t\t\t\t--> ENTER MONTH (MM) : ";
						        cin>>mm;
							  }while(mm<=0 || mm>12);
						     }
						 cout<<"\t\t\t\t--> ENTER YEAR (YY) : ";
						 cin>>yy;
						     if(yy<=1900 || yy>2005)
						     {
							  do
							  {
							  	cout<<"\t\t\t\t..INVALID INPUT YEAR SHOUD BE BETWEEN (1900 - 2005)..."<<endl;
						   	  	cout<<"\t\t\t\t--> ENTER YEAR (YY) : ";
						      	cin>>yy;
							  }while(yy<=0 || yy>2005);
						     }
			         }else if(input=='C')
			         {
			         	 system("cls");
			         	 cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT GENDER |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
			         	 cout<<"\t\t\t--> ENTER YOUR GENDER [M/F] : ";
					     cin>>sex;
					      if(sex!='M'&& sex!='F')
						     {
							  do
							  {
							  	cout<<"\t\t\t\t...INVALID INPUT press [M] for male, [F] for female..."<<endl;
						   	    cout<<"\t\t\t--> ENTER YOUR GENDER [M/F] : ";
						        cin>>sex;
							  }while(sex!='M' && sex!='F');
						     }
					 }else if(input=='D')
					 {
					 	system("cls");
					 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT PHONE NUMBER |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
					 	cout<<"\t\t\t--> ENTER PHONE NUMBER : ";
     					cin>>phone;
					 }else if(input=='E')
					 {
					 	system("cls");
					 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT SECTION |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
					 	cout<<"\t\t\t--> ENTER SECTION [ A / B / C] : ";
				  	    cin>>tsection;
				  	         if(tsection!="C" && tsection!="B" && tsection!="A")
						     {
							  do
							  {
							  	cout<<"\t\t\t\t... INVALID INPUT currently we have 3 sections in each department ..."<<endl;
						   	    cout<<"\t\t\t--> ENTER SECTION [ A / B / C] : ";
				  	            cin>>tsection;
							  }while(tsection!="C" && tsection!="B" && tsection!="A");
							 }
						     if(dpt=="CD")
							   {
							   	     if(rgln=="REG")
							   	     {
							   	     	section="RCD"+year+tsection;
									 }else
									 {
									 	section="ECD"+year+tsection;
									 }   
							   }else
							   if(dpt=="MD")
							   {
							   	     if(rgln=="REG")
							   	     {
							   	     	section="RMD"+year+tsection;
									 }else
									 {
									 	section="EMD"+year+tsection;
									 }
							   } 
							 if(dpt=="AD")
							   {
							   	     if(rgln=="REG")
							   	     {
							   	     	section="RAD"+year+tsection;
									 }else
									 {
									 	section="EAD"+year+tsection;
									 }
							   } 
					 }
					 else if(input=='F')
					 {
					 	system("cls");
					 	cout<<"\t\t\t------------------------------------------------------------------"<<endl;		
						cout<<"\t\t\t\t \t\t| UPDATE STUDENT REGULATION |  "<<endl;
						cout<<"\t\t\t------------------------------------------------------------------"<<endl;	
					 	cout<<"\t\t\t--> ENTER REGULATION [REGULAR - REG ] [EXTENSION - EXT] : ";
				  	    cin>>rgln;
				  	      if(rgln!="REG"&& rgln!="EXT")
						     {
							  do
							  {
							  	cout<<"\t\t\t\t...INVALID INPUT insert [REG] for regular, [EXT] for extension..."<<endl;
						   	    cout<<"\t\t\t--> ENTER REGULATION [REGULAR - REG ] [EXTENSION - EXT] : ";
				  	   			cin>>rgln;
							  }while(rgln!="REG"&& rgln!="EXT");
						     }
						        cout<<"\t\t\t------------------------------------------------------------------"<<endl;	
								cout<<"\t\t\t\t REMARK: after changing student's regulation you have to  "<<endl;
								cout<<"\t\t\t\t           change students section and id_number "<<endl;
								cout<<"\t\t\t------------------------------------------------------------------"<<endl;	
								system("pause");
					 }else if(input=='G')
					 {
					 	system("cls");
					 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT ID NUMBER |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
					 	 cout<<"\t\t\t--> ENTER ID NUMBER [USING COUNTING NUMBERS ONLY] : ";
						 cin>>tid_no;
						 if(dpt=="CD")
						   {
						   	     if(rgln=="REG")
						   	     {
						   	     	id_no="RCD/"+tid_no+"/"+year;
								 }else
								 {
								 	section="ECD"+year+tsection;
								 }   
						   }else
						   if(dpt=="MD")
						   {
						   	     if(rgln=="REG")
						   	     {
						   	     	id_no="RMD/"+tid_no+"/"+year;
						   	     	
								 }else
								 {
								 	id_no="EMD/"+tid_no+"/"+year;
								 	
								 }
						   }
						 if(dpt=="AD")
						   {
						   	     if(rgln=="REG")
						   	     {
						   	     	id_no="RAD/"+tid_no+"/"+year;
								 }else
								 {
								 	id_no="EAD/"+tid_no+"/"+year;
								 }
						   }  
					 }else if(input=='H')
					 {
					 	   system("cls");
					 	   cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						   cout<<"\t\t\t\t REMARK: DEPARTMENT CHANGE WOULD CHANGE STUDENT'S  "<<endl;
						   cout<<"\t\t\t\t          SEVERAL ACCADAMIC RELATED RECORDs.  "<<endl;
						   cout<<"\t\t\t---------------------------------------------------------"<<endl;
						   acadamy_info();	
					 }else if(input=='I')
			         {
			         	system("cls");
			         	cin.ignore();
			         	adder();
					 }else if(input=='J')
					 {
					 	system("cls");
					 	droper();
					 }else if(input=='K')
					 {
					 	system("cls");
					 	cout<<"\t\t\t---------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| FILL OBTAINED MARKS IN EACH COURSE |  "<<endl;
						cout<<"\t\t\t---------------------------------------------------------"<<endl;
					 	 cout<<"\t\t\t--> STUDENT HAS BEEN ATTAINDING THE FOLLOWING COURSES:"<<endl;
					 	 for(int i=0; i<numCourses; i++)
					 	 {
					 	 	cout<<"\t\t\t "<<i+1<<". "<<course[i]<<endl;
						 }
					 	 cout<<"\t\t\t---------------------------------------------------------"<<endl;
					 	 cout<<"\t\t\tFILL MARKS OBTAINED COURSE WISE PLEASE: "<<endl;
					 	 for(int i=0; i<numCourses; i++)
					 	 {
					 	 	cout << "\t\t\t--> ENTER MARK OBTAINED BY "<<course[i]<<" COURSE: ";
	                        cin >> sub[i];
				            if(sub[i]<=0 || sub[i]>100)
						     {
							  do
							  {
							  	cout<<"\t\t\t\t...INVALID INPUT MARK SHOULD BE BETWEEN 1-100..."<<endl;
						   	  	cout << "\t\t\t--> ENTER MARK ON GIVEN SUBJECT: ";
				       			 cin >> sub[i];
							  }while(sub[i]<=0 || sub[i]>100);
						     }
						 }
						 	   for(int i=0; i<numCourses; i++)
							   {
							   	sum+=sub[i];
							   }
							   per=sum/numCourses;
							   if(per>=80)
							   {
							   	 grade="A";
							   	 result="PASS";
							   }
							   else if(per>=60)
							   {
							   	grade="B";
							   	result="PASS";
							   }
							   else if(per>=35)
							   {
							   	grade="C";
							   	result="PASS";
							   }
							   else
							   {
							   	grade="-";
							   	result="FAIL";
							   }
					 }else if(input=='L')
					 {
					 	system("cls");
					 	show();
					 	getch();
					 }else
			         {
			         	break;
					 }
				  
			   }while(input!='M');
			      file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
				  for(int i=0; i<numCourses; i++)
				  {
				  	file1<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
				  }
				  file1<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
				found++;
			}else
			{
				  file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
				  for(int i=0; i<numCourses; i++)
				  {
				  	file1<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
				  }
				  file1<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
			}
			
			  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
			  for(int i=0; i<numCourses; i++)
			  {
			  	file>>course[i]>>credit[i]>>sub[i];
			  }
			  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t THER IS NO STUDENT WITH THAT ID_NUMBER OR FIRST NAME...!!! ";
		}else
		if(found!=0)
		{
			success="\n\n\t\t\t\t\t\t   STUDENT RECORD IS EDITED SUCCESSFULLY... \n\n\t\t\t\t\t\t\t PRESS ANY KEY TO CONTINUE...";
			system("cls");
			cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t------------------------------------------------------------------------------------------------"<<endl;
			for(int i=0; i< success.length(); i++)
			{
				cout<<success.at(i);
				if(i<success.length())
				Sleep(20);
			}
			cout<<"\n\n\t\t\t------------------------------------------------------------------------------------------------"<<endl;
			
			getch();
		}
		file.close();
		file1.close();
		
		remove("student.txt");
		rename("temp.txt","student.txt");
	}		
}

//just groping option
void student::group()
{
	A:
	system("cls");
	char c, input, CH;
   do
   {
   	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
      cout<<"\t\t\t\t|            STUDENT GROUP OPTION                     |"<<endl;
	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;      
	  cout<<"\t\t\t\t A. GROUP BY DEPARTMENT"<<endl;
      cout<<"\t\t\t\t B. GROUP BY GENDER"<<endl;
      cout<<"\t\t\t\t C. GORUP BY PASS AND FAIL"<<endl;
      cout<<"\t\t\t\t D. BACK TO MAIN MENU"<<endl;
      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
      cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
      cout<<" --> PLEASE ENTER YOUR CHOICE : ";
      cin>>c;
      
      input=toupper(c);
      switch(input)
      {
      	 case 'A':
      	 	sectioner();
      	 	break;
      	 case 'B':
      	 	  V:
      	    do{
      	    	  system("cls");
      	    	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
      			  cout<<"\t\t\t\t|            GROUP STUDENTS BY GENDER                 |"<<endl;
	  			  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;  
	  			  cout<<"\t\t\t\t F. FOR FEMLAE"<<endl;
      			  cout<<"\t\t\t\t M. FOR MALE"<<endl;
      			  cout<<"\t\t\t\t B. BACK TO PREVIOUS MENU"<<endl;
      			  cout<<"\t\t\t\t C. BACK TO MAIN MENU"<<endl;
      			  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			      cout<<"\t\t\t\t  CHOOSE OPTION : [ F / M / C / B ]"<<endl;
			      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			      cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			      cin>>CH;
			      CH=toupper(CH);
			      switch(CH)
			      {
			      	case'M':
			      		searcher(CH);
			      		break;
			      	case 'F':
			      		searcher(CH);
			      		break;
			      	case 'B':
			      	    group();
			      	    break;
			      	case 'C':
			      	    menu();
			      	    break;
			      	default:
			      		cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE ---";		
				  } 
			  }while(CH=='M'||CH=='F' ||CH=='B' ||CH=='C');
			   getch();
			   goto V;
      	    break;
      	 case 'C':
      	     Z:
      	    do{
      	    	  system("cls");
      	    	  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
      			  cout<<"\t\t\t\t|            GROUP STUDENTS BY PASS AND FAIL          |"<<endl;
	  			  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;  
	  			  cout<<"\t\t\t\t P. FOR PASSED STUDENTS"<<endl;
      			  cout<<"\t\t\t\t N. FOR NOT PASED / FAILED / STUDENTS"<<endl;
      			  cout<<"\t\t\t\t B. BACK TO PREVIOUS MENU"<<endl;
      			  cout<<"\t\t\t\t C. BACK TO MAIN MENU"<<endl;
      			  cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			      cout<<"\t\t\t\t  CHOOSE OPTION : [ P / N / C / B ]"<<endl;
			      cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			      cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			      cin>>CH;
			      CH=toupper(CH);
			      switch(CH)
			      {
			      	case 'P':
			      		searcher(CH);
			      		break;
			      	case 'N':
			      		searcher(CH);
			      		break;
			      	case 'B':
			      	    group();
			      	    break;
			      	case 'C':
			      	    menu();
			      	    break;
			      	default:
			      		cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE ---";		
				  } 
			  }while(CH=='P'||CH=='N' || CH=='B'||CH=='C');
			   getch();
			   goto Z;
      	    break;
      	 case 'D':
      		menu();
      		break;
      	default:
      		cout<<"\n\t\t\t\tINAVLID CHOICE PRESS ANY KEY TO CONTINUE...."<<endl;
	  }
   }while(input=='A' || input=='B' || input=='C' || input=='D');
   getch();
   goto A;
}

//group by department
char student::groupdpt()
{
	A:
	char dptchoice, ch;
	do
	{
	system("cls");
	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;	
	cout<<"\t\t\t\t\t| GROUP STUDENT BY DEPARTMENT            |"<<endl;
	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;      
	cout<<"\t\t\t\t A. FOR COMPUTER SCIENCE"<<endl;
	cout<<"\t\t\t\t B. FOR MARKETING MANAGEMENT"<<endl;
	cout<<"\t\t\t\t C. FOR ACCOUNTING AND FINANCE"<<endl;
	cout<<"\t\t\t\t D. BACK TO PREVIOUS MENU"<<endl;
	cout<<"\t\t\t\t E. BACK TO MAIN MENU"<<endl;
	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D / E ]"<<endl;
	cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
	cout<<" --> PLEASE ENTER YOUR CHOICE : ";
	cin>>ch;
	
	dptchoice=toupper(ch);
	
      switch(dptchoice)
      {
      	 case 'A':
      	 	return dptchoice;
      	 	break;
      	 case 'B':
      	    return dptchoice;
      	    break;
      	 case 'C':
      	    return dptchoice;
      	 case 'D':
      		group();
      		break;
      	case 'E':
      		menu();
      		break;
      	default:
      		cout<<"\n\t\t\t\tINAVLID CHOICE PRESS ANY KEY TO CONTINUE...."<<endl;
	  } 
	}while(dptchoice=='A' || dptchoice=='B' || dptchoice=='C' || dptchoice=='D' || dptchoice=='E');		 
    getch();
	goto A;
}
    
//group by regulation
char student::regulation(char &dptchoice)
{
	A:
	char locdptchoice, rglnchoice, ch;
	locdptchoice = dptchoice;
	
	do{
		system("cls");
		if(locdptchoice=='A')
		{
			cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
		    cout<<"\t\t\t\t|     GROUP COMPUTER SCIENCE STUDENT BY REGULATION    |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
		}else
		if(locdptchoice=='B')
		{
			cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
		    cout<<"\t\t\t\t|  GROUP MARKETING MANAGEMENT STUDENT BY REGULATION   |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
		}else
		if(locdptchoice=='C')
		{
			cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
		    cout<<"\t\t\t\t| GROUP ACCOUNTING AND FINANACE STUDENT BY REGULATION |"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
		}	
			cout<<"\t\t\t\t A. FOR REGULAR"<<endl;
			cout<<"\t\t\t\t B. FOR EXTENSION"<<endl;
			cout<<"\t\t\t\t C. BACK TO GROUP MENU"<<endl;
			cout<<"\t\t\t\t D. BACK TO MAIN MENU"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<"\t\t\t\t  Choose Option : [ A / B / C / D ]"<<endl;
			cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
			cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			cin>>ch;
			
			rglnchoice = toupper(ch);
			switch(rglnchoice)
			{
				case 'A':
					return rglnchoice;
					break;
				case 'B':
					return rglnchoice;
					break;
				case 'C':
					group();
					break;
				case 'D':
					menu();
					break;
				default:
					cout<<"INVALID CHOICE PRESS ANY KEY TO CONTINUE";
			}
		  }while(rglnchoice=='A' || rglnchoice=='B' || rglnchoice=='C' || rglnchoice=='D');
	  getch();
	  goto A;
}

// group by entry year
char student::entry(char &rglnchoice, char &dptchoice)
{
	A:
	char locrglnchoice, locdptchoice, entryyear, ch;
	locrglnchoice=rglnchoice;
	locdptchoice=dptchoice;
	
	do{
		system("cls");
		if(locdptchoice=='A' && locrglnchoice=='A')
	    {
		cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t|     REGULAR COMPUTER SCIENCE STUDENT ENTRY YEAR     |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
     	}else
     	if(locdptchoice=='A' && locrglnchoice=='B')
	    {
		cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t|     EXTENSION COMPUTER SCIENCE STUDENT ENTRY YEAR   |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
     	}else
	    if(locdptchoice=='B' && locrglnchoice=='A')
	   {
		cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t|  REGULAR MARKETING MANAGEMENT STUDENT ENTRY YEAR    |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
	   }else
	   if(locdptchoice=='B' && locrglnchoice=='B')
	   {
		cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t|  EXTENSION MARKETING MANAGEMENT STUDENT ENTRY YEAR  |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
	   }else
	   if(locdptchoice=='C' && locrglnchoice=='A')
       {
		cout<<"\n\t\t\t\t-------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t| REGULAR ACCOUNTING AND FINANACE STUDENT ENTRY YEAR  |"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl; 
     	}else
	   if(locdptchoice=='C' && locrglnchoice=='B')
       {
		cout<<"\n\t\t\t\t--------------------------------------------------------"<<endl;	
	    cout<<"\t\t\t\t| EXTENSION ACCOUNTING AND FINANACE STUDENT ENTRY YEAR |"<<endl;
		cout<<"\t\t\t\t--------------------------------------------------------"<<endl; 
     	}
		     
		cout<<"\t\t\t\t A. 2012"<<endl;
		cout<<"\t\t\t\t B. 2013"<<endl;
		cout<<"\t\t\t\t C. 2014"<<endl;
		cout<<"\t\t\t\t D. 2015"<<endl;
		cout<<"\t\t\t\t E. BACK TO GROUP MENU"<<endl;
		cout<<"\t\t\t\t F. BACK TO MAIN MENU"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
		cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D / E / F ]"<<endl;
		cout<<"\t\t\t\t-------------------------------------------------------"<<endl;
		cout<<" --> PLEASE ENTER YOUR CHOICE : ";
		cin>>ch;
		
		entryyear = toupper(ch);
		switch(entryyear)
		{
			case 'A':
				return entryyear;
				break;
			case 'B':
				return entryyear;
				break;
			case 'C':
				return entryyear;
				break;
			case 'D':
				return entryyear;
				break;
			case 'E':
				group();
				break;
			case 'F':
				menu();
				break;
			default:
				cout<<" ---INVALID CHOICE PRESS ANY KEY TO CONTINUE---"<<endl;
		}
      }while(entryyear=='A' || entryyear=='B' || entryyear=='E' || entryyear=='D' || entryyear=='E' || entryyear=='F');
      getch();
      goto A;
}

//gorup by section 
void student::sectioner()  
{   
    system("cls");
	fstream file;
	char test, t;
	char locentryyear, locrglnchoice, locdptchoice;
	
	locdptchoice=groupdpt();
	locrglnchoice=	regulation(locdptchoice);
	locentryyear=entry(locrglnchoice,locdptchoice);
	
	
	
	file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	    file.close();	
				
	}
	else
	{
		A:
	      file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
	while(!file.eof())
	{
	 do{
	 	   	
		   if(locentryyear=='A' && locrglnchoice=='A' && locdptchoice=='A')
		   {
		   	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2012 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RCD2012A"<<endl;
				cout<<"\t\t\t\t B. RCD2012B"<<endl;
				cout<<"\t\t\t\t C. RCD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RCD2012A");
					    break;
					case 'B':
						show("RCD2012B");
					    break;
					case 'C':
						show("RCD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
			}
    
	       else if(locentryyear=='B' && locrglnchoice=='A' && locdptchoice=='A')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2013 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RCD2013A"<<endl;
				cout<<"\t\t\t\t B. RCD2013B"<<endl;
				cout<<"\t\t\t\t C. RCD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    		show("RCD2013A");
					    break;
					case 'B':
						show("RCD2013B");
					    break;
					case 'C':
						show("RCD2013C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	        else if(locentryyear=='C' && locrglnchoice=='A' && locdptchoice=='A')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2014 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RCD2014A"<<endl;
				cout<<"\t\t\t\t B. RCD2014B"<<endl;
				cout<<"\t\t\t\t C. RCD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  Choose Option : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> Please Enter Your Choice : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RCD2014A");
					    break;
					case 'B':
						show("RCD2014B");
					    break;
					case 'C':
						show("RCD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
			   
	        }
	    
	        else if(locentryyear=='D' && locrglnchoice=='A' && locdptchoice=='A')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2015 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RCD2015A"<<endl;
				cout<<"\t\t\t\t B. RCD2015B"<<endl;
				cout<<"\t\t\t\t C. RCD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> Please Enter Your Choice : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	    show("RCD2015A");
					    break;
					case 'B':
						show("RCD2015B");
					    break;
					case 'C':
						show("RCD2015C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}   
	        }
	    
	       else if(locentryyear=='A' && locrglnchoice=='B' && locdptchoice=='A')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2012 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. ECD2012A"<<endl;
				cout<<"\t\t\t\t B. ECD2012B"<<endl;
				cout<<"\t\t\t\t C. ECD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("ECD2012A");
					    break;
					case 'B':
						show("ECD2012B");
					    break;
					case 'C':
						show("ECD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
			    
	        }
	    
	       else if(locentryyear=='B' && locrglnchoice=='B' && locdptchoice=='A')
	       {
	       		system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2013 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. ECD2013A"<<endl;
				cout<<"\t\t\t\t B. ECD2013B"<<endl;
				cout<<"\t\t\t\t C. ECD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("ECD2013A");
					    break;
					case 'B':
						show("ECD2013B");
					    break;
					case 'C':
						show("ECD2013C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	       else if(locentryyear=='C' && locrglnchoice=='B' && locdptchoice=='A')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2014 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. ECD2014A"<<endl;
				cout<<"\t\t\t\t B. ECD2014B"<<endl;
				cout<<"\t\t\t\t C. ECD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE: ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("ECD2014A");
					    break;
					case 'B':
						show("ECD2014B");
					    break;
					case 'C':
						show("ECD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
		   else if(locentryyear=='D' && locrglnchoice=='B' && locdptchoice=='A')
	       {
	       		system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2015 ENTRY COMPUTER SCIENECE STUDENTS  SECTION   |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. ECD2015A"<<endl;
				cout<<"\t\t\t\t B. ECD2015B"<<endl;
				cout<<"\t\t\t\t C. ECD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOCE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("ECD2015A");
					    break;
					case 'B':
						show("ECD2015B");
					    break;
					case 'C':
						show("ECD2015C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	       else if(locentryyear=='A' && locrglnchoice=='A' && locdptchoice=='B')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2012 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RMD2012A"<<endl;
				cout<<"\t\t\t\t B. RMD2012B"<<endl;
				cout<<"\t\t\t\t C. RMD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICEe : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	    show("RMD2012A");
					    break;
					case 'B':
						show("RMD2012B");
					    break;
					case 'C':
						show("RMD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	       else if(locentryyear=='B' && locrglnchoice=='A' && locdptchoice=='B')
	       {
	       		system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2013 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RMD2013A"<<endl;
				cout<<"\t\t\t\t B. RMD2013B"<<endl;
				cout<<"\t\t\t\t C. RMD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RMD2013A");
					    break;
					case 'B':
						show("RMD2013B");
					    break;
					case 'C':
						show("RMD2013D");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
		    else if(locentryyear=='C' && locrglnchoice=='A' && locdptchoice=='B')
		    {
		       	system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2014 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RMD2014A"<<endl;
				cout<<"\t\t\t\t B. RMD2014B"<<endl;
				cout<<"\t\t\t\t C. RMD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RMD2014A");
					    break;
					case 'B':
						show("RMD2014B");
					    break;
					case 'C':
						show("RMD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	       else if(locentryyear=='D' && locrglnchoice=='A' && locdptchoice=='B')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2015 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RMD2015A"<<endl;
				cout<<"\t\t\t\t B. RMD2015B"<<endl;
				cout<<"\t\t\t\t C. RMD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
			    cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	    show("RMD2015A");
					    break;
					case 'B':
						show("RMD2015B");
					    break;
					case 'C':
						show("RMD2015C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	   	    }
	   
	       else if(locentryyear=='A' && locrglnchoice=='B' && locdptchoice=='B')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2012 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EMD2012A"<<endl;
				cout<<"\t\t\t\t B. EMD2012B"<<endl;
				cout<<"\t\t\t\t C. EMD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EMD2012A");
					    break;
					case 'B':
						show("EMD2012B");
					    break;
					case 'C':
						show("EMD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
			}
		
	        else if(locentryyear=='B' && locrglnchoice=='B' && locdptchoice=='B')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2013 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EMD2013A"<<endl;
				cout<<"\t\t\t\t B. EMD2013B"<<endl;
				cout<<"\t\t\t\t C. EMD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";	 
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EMD2013A");
					    break;
					case 'B':
						show("EMD2013B");
					    break;
					case 'C':
						show("EMD2013C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}   
	        }
	   
	       else if(locentryyear=='C' && locrglnchoice=='B' && locdptchoice=='B')
	       {
	       	    system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2014 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EMD2014A"<<endl;
				cout<<"\t\t\t\t B. EMD2014B"<<endl;
				cout<<"\t\t\t\t C. EMD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EMD2014A");
					    break;
					case 'B':
			    	   show("EMD2014B");
					    break;
					case 'C':
			    	   show("EMD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}  
	        }

	        else if(locentryyear=='D' && locrglnchoice=='B' && locdptchoice=='B') 
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2012 ENTRY MARKETING MANAGEMNET STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EMD2015A"<<endl;
				cout<<"\t\t\t\t B. EMD2015B"<<endl;
				cout<<"\t\t\t\t C. EMD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t---------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EMD2015A");
					    break;
					case 'B':
						show("EMD2015B");
					    break;
					case 'C':
						show("EMD2015C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	        else if(locentryyear=='A' && locrglnchoice=='A' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2012 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RAD2012A"<<endl;
				cout<<"\t\t\t\t B. RAD2012B"<<endl;
				cout<<"\t\t\t\t C. RAD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RAD2012A");
					    break;
					case 'B':
						show("RAD2012B");
					    break;
					case 'C':
						show("RAD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
		    else if(locentryyear=='B' && locrglnchoice=='A' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2013 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RAD2013A"<<endl;
				cout<<"\t\t\t\t B. RAD2013B"<<endl;
				cout<<"\t\t\t\t C. RAD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RAD2013A");
					    break;
					case 'B':
						show("RAD2013B");
					    break;
					case 'C':
						show("RAD2013C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	    
	        else if(locentryyear=='C' && locrglnchoice=='A' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2014 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RAD2014A"<<endl;
				cout<<"\t\t\t\t B. RAD2014B"<<endl;
				cout<<"\t\t\t\t C. RAD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RAD2014A");
					    break;
					case 'B':
						show("RAD2014B");
					    break;
					case 'C':
						show("RAD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	        
	        else if(locentryyear=='D' && locrglnchoice=='A' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| REGULAR 2015 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. RAD2015A"<<endl;
				cout<<"\t\t\t\t B. RAD2015B"<<endl;
				cout<<"\t\t\t\t C. RAD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("RAD2015A");
					    break;
					case 'B':
						show("RAD2015B");
					    break;
					case 'C':
						if(section=="RAD2015C")
			    	   	{
			    	   	show();	
			    	   	system("pause");
					    }
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	       }

	       else if(locentryyear=='A' && locrglnchoice=='B' && locdptchoice=='C')
	       {
	       		system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2012 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EAD2012A"<<endl;
				cout<<"\t\t\t\t B. EAD2012B"<<endl;
				cout<<"\t\t\t\t C. EAD2012C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EAD2012A");
					    break;
					case 'B':
						show("EAD2012B");
					    break;
					case 'C':
						show("EAD2012C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	 	    
	        else if(locentryyear=='B' && locrglnchoice=='B' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2013 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EAD2013A"<<endl;
				cout<<"\t\t\t\t B. EAD2013B"<<endl;
				cout<<"\t\t\t\t C. EAD2013C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EAD2013A");
					    break;
					case 'B':
						show("EAD2013B");
					    break;
					case 'C':
						show("EAD2013C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	        
	        else if(locentryyear=='C' && locrglnchoice=='B' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2014 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EAD2014A"<<endl;
				cout<<"\t\t\t\t B. EAD2014B"<<endl;
				cout<<"\t\t\t\t C. EAD2014C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EAD2014A");
					    break;
					case 'B':
						show("EAD2014B");
					    break;
					case 'C':
						show("EAD2014C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}
	        }
	 	    
	        else if(locentryyear=='D' && locrglnchoice=='B' && locdptchoice=='C')
	        {
	        	system("cls");
		   	    cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;	
				cout<<"\t\t\t\t| EXTENSION 2015 ENTRY ACCOUNTING AND FINANCE STUDENTS  SECTION |"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;      
				cout<<"\t\t\t\t A. EAD2015A"<<endl;
				cout<<"\t\t\t\t B. EAD2015B"<<endl;
				cout<<"\t\t\t\t C. EAD2015C"<<endl;
				cout<<"\t\t\t\t D. EXIT"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<"\t\t\t\t  CHOOSE OPTION : [ A / B / C / D ]"<<endl;
				cout<<"\t\t\t\t----------------------------------------------------------------"<<endl;
				cout<<" --> PLEASE ENTER YOUR CHOICE : ";
				cin>>t;
			    
			    test=toupper(t);
			    switch(test)
			    {
			    	case 'A':
			    	   show("EAD2015A");
					    break;
					case 'B':
						show("EAD2015B");
					    break;
					case 'C':
						show("EAD2015C");
					    break;
					case 'D':
						menu();
						break;
					default:
						cout<<" --- INVALID CHOICE PRESS ANY KEY TO CONTINUE --- ";	    
				}	    
	        }
	    }while(test=='A' || test=='B' || test=='C' || test=='D'); getch(); goto A;
	
	      file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
	}
	file.close();
	getch();
	system("cls");
}
}

//payment function
void student::display_payment()
{
	system("cls");
	fstream file,file1;
	string temp;
	char ch;
	int pay;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;	
    cout<<"\t\t\t\t\t\t | STUDENT PAYMENT STATUS |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
    file.open("student.txt",ios::in);
    if(!file)
    {
        cout<<"\n\t\t\t No Data Is Found ......";
	    file.close();	
				
	}
	else
	{
		cout<<"\n\t\t\t--> ENTER ID_NUMBER OR FIRST_NAME OF STUDENT TO TO CHECK PAYMENT STATUS : ";
		cin>>temp;
		file1.open("temp.txt",ios::out | ios::app);
		file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
		  for(int i=0; i<numCourses; i++)
		  {
		  	file>>course[i]>>credit[i]>>sub[i];
		  }
		  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		while(!file.eof())
		{
			if(temp==id_no || temp==s_name)
			{
				do{
					system("cls");
			   	  cout<<"\t\t\t\t-------------------------------------------------------------------"<<endl;	
			      cout<<"\t\t\t\t\t\t|    STUDENT PAYMENT OPTION            |"<<endl;
				  cout<<"\t\t\t\t-------------------------------------------------------------------"<<endl;      
			      cout<<"\t\t\t\t A. UPDATE STUDENT PAYMENT INFORMATION"<<endl;
			      cout<<"\t\t\t\t B. DISPLAY STUDENT PAYMENT INFORMATION"<<endl;
			      cout<<"\t\t\t\t C. BACK TO MAIN MENU"<<endl;
			      cout<<" --> Please Enter Your Choice : ";
			      cin>>ch;
			      ch=toupper(ch);
			      if(ch=='A')
			      {
			         	system("cls");
			      	 	cout<<"\t\t\t--------------------------------------------------------------"<<endl;	
						cout<<"\t\t\t\t \t| UPDATE STUDENT PAYMENT RECORD |  "<<endl;
						cout<<"\t\t\t--------------------------------------------------------------"<<endl;
						cout<<"\t\t\t ENTER THE UPDATED AMOUNT OF MONEY TO PAY PER CREDIT HOUR: ";
						cin>>paycredit;
						cout<<"\t\t\t ENTER THE UPDATED AMOUNT OF SERVICE FEE: ";
						cin>>payservice;
						payment=(total*paycredit)+payservice;
					//	payment=(pay*total)+500;
						
				  }else if(ch=='B')
				  {
				  	   system("cls");
				       cout<<"\t\t\t--------------------------------------------------------------"<<endl;	
					   cout<<"\t\t\t\t\t PAYMENT DETAIL "<<endl;
					   cout<<"\t\t\t--------------------------------------------------------------"<<endl;
					   cout<<"\n\t\t\t STUDENT'S NAME : "<<s_name;
					   cout<<"\t\t ID NO : "<<id_no<<endl;
	   		           cout<<"\n\t\t\t FATHER'S NAME : "<<f_name;
	   		             if(dpt=="CD")
				         {
				         	cout<<"\t\t Department  : "<<"COMPTER SCIENCE"<<endl;
						 }
				         else if(dpt=="MD")
				         {
				         	cout<<"\t\t Department  : "<<"MARKETING MANAGEMENT"<<endl;
						 }
				         else if(dpt=="AD")
				         {
				         	cout<<"\t\t Department  : "<<"ACCOUNTING AND FINANCE"<<endl;
						 }
						 if(sex=='M')
				         {
				         	cout<<"\n\t\t\t GENDER : MALE";
						 }
				         else if(sex=='F')
				         {
				         	cout<<"\n\t\t\t GENDER : FEMALE";
						 }
						 cout<<"\t\t\t Section     : "<<section<<endl;
						 cout<<"\t\t\t--------------------------------------------------------------\n"<<endl;	
					   	  cout << "\t\t\t-->YOU ARE REGISTERED ON THE FOLLOWING COURSES : "<<endl;
					   	  cout<<"\n\t\t\t    COURSE ----  CREDITHOUR  ---- PAYMENT"<<endl;
					   	  for(int i=0; i<numCourses; i++)
				            {
				            	cout<<"\n\t\t\t "<<i+1<<". "<<course[i]<<"         "<<credit[i]<<"              "<<paycredit*credit[i]<<endl;
							}
						  cout<<"\n\t\t\t "<<"   TOTAL "<<"          "<<total<<"              "<<paycredit*total<<endl;
						  cout<<"\t\t\t--------------------------------------------------------------\n"<<endl;
						  cout<<"\n\t\t\t FOR "<<total<<" CREDITHOUR AND INCLUDING THE SERVICE FEE STUDENT PAID : "<<endl;
						  cout<<"\n\t\t\t FOR CREDIT HOUR: "<<total<<"CREDITHOUR"<<" * "<<paycredit<<"$ = $"<<paycredit*total<<endl;
						  cout<<"\n\t\t\t FOR SERVICE FEE: $"<<payservice<<endl;
						  cout<<"\n\t\t\t TOTAL PAYMENT: $"<<(total*paycredit)+payservice<<endl;
						  cout<<"\t\t\t--------------------------------------------------------------\n"<<endl;
						  getch();
				  }else{
				  	break;
				  }
				}while(ch!='C');
				file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
				  for(int i=0; i<numCourses; i++)
				  {
				  	file1<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
				  }
				  file1<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
			}else
			{
				  file1<<" "<<s_name<<" "<<f_name<<" "<<m_name<<" "<<sex<<" "<<year<<" "<<dpt<<" "<<section<<" "<<id_no<<" "<<rgln<<" "<<dd<<" "<<mm<<" "<<yy<<" "<<numCourses<<" "<<total;
				  for(int i=0; i<numCourses; i++)
				  {
				  	file1<<" "<<course[i]<<" "<<credit[i]<<" "<<sub[i];
				  }
				  file1<<" "<<sum<<" "<<per<<" "<<grade<<" "<<result<<" "<<phone<<" "<<payment<<" "<<paycredit<<" "<<payservice<<"\n";
				  system("cls");
				cout<<"\n\n\n\n\n\n\t\t\t\t\t ---------------------------------------------------------------------------------------"<<endl;
				cout<<"\n\n\n\t\t\t\t\t\t\t THERE IS NO PAYMENT RECORD WITH THAT ID_NUMBER OR NAME ..."<<endl;
				cout<<"\n\n\n\t\t\t\t\t ---------------------------------------------------------------------------------------"<<endl;
				system("pause");
			}
			  file>>s_name>>f_name>>m_name>>sex>>year>>dpt>>section>>id_no>>rgln>>dd>>mm>>yy>>numCourses>>total;
			  for(int i=0; i<numCourses; i++)
			  {
			  	file>>course[i]>>credit[i]>>sub[i];
			  }
			  file>>sum>>per>>grade>>result>>phone>>payment>>paycredit>>payservice;
		}
		file.close();
		file1.close();
		
		remove("student.txt");
		rename("temp.txt","student.txt");
    }
}
// defination of main function..........
int main()
{
    start();    
    student s;              
    s.menu();                
    
	getch();
	return (0);
}

