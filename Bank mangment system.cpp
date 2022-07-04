// Header files used in project 

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;

// class used in project

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;

	public :
	   void create_account(); // function tp get data from user
	   void show_account();   // function to show data on screen 
	   void modify();         // function to add new data
	   void dep(int);         // function to accept amount and add to balance amount
	   void draw(int);        // function to accept amount and subtract from balance amount
	   void report() const;   // function to show data in tabular format
	   void retacno() const;  // function to return account number
	   void retdeposit()const;// function to return balance amount
	   char rettype() const;  // function to return type of account
};   

    //  class ends here //


 void account::create_account()
 {
 	cout<< "\nPlease Enter Your account No. : ";
 	cin>>acno;
 	cout<< "\nThank You Now Enter account Holder's Name : ";
 	cin.ignore();
 	cin.getline(name,50);
 	cout<< "\nEnter account's type (Saving/Current) : ";
 	cin>>type;
 	type = toupper(type);
 	cout<< "\nEnter The Initial amount (>=500 for saving and >= 1000 for current) : ";
 	cin>>deposit;
 	cout<<"\n\n\nAccount Created...";
 }  

 void account::show_account()
 {
 	cout<< "\nAccount No. : "<<acno;
 	cout<< "\nAccount Holder's Name : ";
 	cout<<name;
 	cout<< "\nType of Account : "<<type;
 	cout<< "\nBalance amount : "<<deposit;
 }

 void account::modify()
 {
 	cout<<"\nAccount NO. :"<<acno;
 	cout<<"\nModify Account Holder Name :";
 	cin.ignore();
 	cin.getline(name,50);
 	cout<<"\nModify Account Type : ";
 	cin>>type;
 	type = toupper(type);
 	cout<<"\nModify Balance amount : ";
 	cin>> deposit; 
 }
 void account::dep(int x)
 {
 	deposit += x;
 }
 void account::draw(int x)
 {
 	deposit -= x;
 }
 void account::report() const
 {
 	cout<<acno<<setw(10)<<" "<<name << setw(10)<< " "<<type<<setw(6)<<deposit<<endl;
 }
 void account::retacno()const
 {
 	return acno;
 }
 void account::retdeposit()const
 {
 	return deposit;
 }
 void account::rettype( )const
 {
 	return type;
 }

/*************************************************************/
     /// Function declaration ///

 void write_account();          // function to write record in binary file
 void display_sp(int);          // function to display account details given by user
 void modify_account(int);      // function to modify record of file
 void delete_account(int);      // function to delete record of file
 void display_all();            // function to display all account details
 void deposit_withdraw(int,int); // function to deposit/withdraw amount for given account
 void intro();                  // introductory screen function

 /****************************************************************/
  

    /// The main function of program ///


 int main()
 {
 	char ch;
 	int num;
 	intro();
 	do
 	{
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\n\t01.NEW ACCOUNT";
        cout<<"\n\n\n\t02.DEPOSIT AMOUNT";
        cout<<"\n\n\n\t03.WITHDRAW AMOUNT";
        cout<<"\n\n\n\t04.BALANCE ENQUIRY";
        cout<<"\n\n\n\t05.ALL ACCOUNT HOLDER LIST";
        cout<<"\n\n\n\t06.CLOSE AN ACCOUNT";
        cout<<"\n\n\n\t07.MODIFY AN ACCOUNT";
        cout<<"\n\n\n\t08. EXIT";
        cout<<"\n\n\t Select Your Option(1-8)";
        cin>>ch;
        system("cls");
        switch(ch)
        {
        	case '1':
        	    write_account();
        	    break;
        	case '2':
        	    cout<<"\n\n\tEnter The account No. :"; cin>>num;
        	    deposit_withdraw(num , 1);
        	    break;
        	case '3':
        	    cout<<"\n\n\tEnter The account No. :"; cin>>num;
        	    deposit_withdraw(num,2);
        	    break;
            case '4':
                cout<<"\n\n\tEnter The account No. :";cin>>num;
                display_sp(num);
                break;
            case '5':
               
                display_all();
                break;
            case '6':
                cout<<"\n\n\tEnter The account No. :";cin>>num;
                delete_account(num);
                break;
            case '7':
                cout<<"\n\n\tEnter The account No. :";cin>>num;
                modify_account(num);
                break;
            case '8':
                cout<<"\n\n\t Thanks for using bank managment system created by DHEERAJ GAHLOT "; 
                
                break;
            default:cout<<"\a";                                	            
        }
        cin.ignore();
        cin.get();
 	}while(ch!='8');

 	return 0;
 }

   /// end of main function///

 /*************************************************************************************************************/


   /// function to write in file///

 void write_account()
 {
 	account ac;
 	ofstream outFile;
 	outFile.open("account.dat", ios:: binary | ios::app);
 	ac.create_account();
 	outFile.write(reinterpret_cast<char*> (&ac),sizeof(account));
     outFile.close();
 }


  /// function to read  specific  record from file ///

 void display_sp(int n )
 {
 	account ac;
 	bool flag = false;
 	ifstream inFile;
 	inFile.open("account.dat",ios::binary);
 	if(!inFile)
 	{
 		cout<<"File could not be open  || press any key...";
 		return ;
 	}
 	cout<< " \nBalance Details\n";
 	while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(account)))
 	{
 		if(ac.retacno()==n)
 		{
 			ac.show_account();
 			flag = true;
 		}
 	}
 	inFile.close();
 	if(flag == false)
 	{
 		cout<<"\n Account Number does not exists";
 	}
 }



      //// function to modify record file ///

 void modify_account(int n )
 {
 	bool found = false;
 	account ac;
 	fstream File;
 	File.open("account.dat",ios::binary | ios::in | ios:: out);
 	if(!File)
 	{
 		cout<<"File could not be open || press any key...";
 		return;
 	}
 	while(!File.eof() && found == false)
 	{
 		File.read(reinterpret_cast<char*>(&ac),sizeof(account));
 		if(ac.retacno() == n)
 		{
 			ac.show_account();
 			cout<<"\n\nEnter The New Details of Account"<<endl;
 			ac.modify();
 			int pos = (-1)*static_cast<int>(sizeof(account));
 			File.seekp(pos, ios::cur);
 			File.write(reinterpret_cast<char*>(&ac),sizeof(account));
 			cout<<"\n\n\t Record Updated";
 			found = true ;
 		}
 	}
 	File.close();
 	if(found == false)
 		cout<<"\n\n Record not Found";
 }


      /// function to delete record of file 

 void delete_account(int n)
 {
 	account ac;
 	ifstream inFile;
 	ofstream outFile;
 	inFile.open("account.dat",ios::binary);
 	if(!inFile)
 	{
 		cout<<"File could not be open || press any key ...";
 		return ;
 	}
 	outFile.open("Temp.dat",ios::binary);
 	inFile.seekg(0,ios::beg);
 	while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(account)))
 	{
 		if(ac.retacno()!=n)
 		{
 			outFile.write(reinterpret_cast<char*>(&ac),sizeof(account));
 		}
 	}
 	inFile.close();
 	outFile.close();
 	remove("account.dat");
 	rename("Temp.dat","account.dat");
 	cout<<"\n\n\tRecord Deleted....";
 }


    //// function to display all accounts deposit list//


 void display_all()
 {
 	account ac;
 	ifstream inFile;
 	inFile.open("account.dat",ios::binary);
 	if(!inFile)
 	{
 		cout<<"File could not be open || pres any key ....";
 		return ;
 	}
 	cout<<"\n\n\tACCOUNT HOLDER LIST \n \n";
 	cout<<"*********************************\n";
 	cout<<"A/c no.     Name       Type      Balance\n";
 	cout<<"*********************************\n";
 	while(inFile.read(reinterpret_cast<char*>(&ac),sizeof(account)))
 	{
 		ac.report();
 	}
 	inFile.close();
 }


     //// Function to deposit and withdraw amounts////

 void deposit_withdraw(int n, int option)
 {
 	int amt;
 	bool found = false;
 	account ac;
 	fstream File;
 	File.open("account.dat",ios::binary|ios::in |ios::out);
 	if(!File)
 	{
 		cout<<"File could not be open || pres any key ....";
 		return ;
 	}
 	while(!File.eof() && found==false)
 	{
 		File.read(reinterpret_cast<char*>(&ac),sizeof(account));
 		if(ac.retacno() == n)
 		{
 			ac.show_account();
 			if(option ==1 )
 			{
 				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
 				cout<<"\n\n\tEnter the amount deposit";
 				cin>>amt;
 				ac.dep(amt);
 			}
 			if(option == 2 )
 			{
 				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
 				cout<<"\n\n\tEnter the amount withdraw ";
 				cin>>amt;
 			int bal = ac.retdeposit()- amt;
 			if((bal<500 && ac.rettype == 'S')||(bal<1000 && ac.rettype == 'C'))
 			{
 				cout<<"Insufficient balance";
 			}
 			else{
 				ac.draw(amt);

 			}

 			}
 			int pos = (-1)*static_cast<int>(sizeof(account));
 				File.seekp(pos,ios::cur);
 				File.write(reinterpret_cast<char*>(&ac),sizeof(account));
 				cout<<"\n\n\t Record updated";
 				found = true;


 		}
 	}
 	File.close();
 	if(found==false)
 	{
 		cout<<"\n\n Record not Found";
 	}
 }


 //// intro //

 void intro()
 {
 	cout<<"\n\n\n\t BANK";
 	cout<<"\n\n\t MANAGMENT";
 	cout<<"\n\n\t SYSTEM";
 	cout<<"\n\n\n\n MADE BY DHEERAJ GAHLOT";
 	cout<<"\n\nIIT KHARAGPUR";
 	cin.get();
 }