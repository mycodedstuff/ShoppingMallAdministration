#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include<string>
#include<unistd.h>
#include<fstream>
#include<ctime>
using namespace std;

char opt;
void shops();
void mainmenu();
void pvrmenu();
void shopdetail();
void events();
void park();
void securitymenu();
void showpark();
void secshow(int);
void eventdetails();
void pvrdetails();
void setting();
COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int datetest(string d){
	if(d.find('/')>=1&&d.rfind('/')>=3&&d.find('/')<=2&&d.rfind('/')<=6){
		string a=d.substr(0,2);
		string b=d.substr(d.find('/')+1,2);
		string c=d.substr(d.length()-2,2);
		int a1=atoi(a.c_str());	
		int b1=atoi(b.c_str());
		int c1=atoi(c.c_str());
		if(a1>=1&&a1<=31){
			if(b1>=1&&b1<=12){
				return 0;
			}
			else{
				cout<<"Invalid Month."<<endl;
				getch();
			}
		}
		else{
				cout<<"Invalid Date."<<endl;
				getch();
			}
	}
	else {
		cout<<"Invalid Format."<<endl;
		getch();
	}
}

int checkemail(string s){
	int a=s.find('.');
	int b=s.find('@');
	if(b<a){
		cout<<"Invalid Email"<<endl;
		return 1;
	}
	int c=s.rfind('.');
	if(c<b){
		cout<<"Invalid Email"<<endl;
		return 1;
	}
	string d=s.substr(0,1);
	if(d<="9"&&d>="0"){
		cout<<"Invaild Email"<<endl;
		return 1;
	}
	return 0;
}

int checkno(string s){
	if(s.length()!=10){
		return 1;
	}
	return 0;
}

class shop{
	int id;
	char name[30];
	char owner[30];
	char type[30];
	int rent;
	char dateofopen[20];
	public:
		void input(int i){
			id=i;
			cout<<"Enter Shop Name :- ";
			fflush(stdin);
			cin.getline(name,30);
			cout<<"Enter Owner's Name :- ";
			fflush(stdin);
			cin.getline(owner,30);
			cout<<"Enter type of Shop :- ";
			fflush(stdin);
			cin.getline(type,30);
			cout<<"Enter Rent per month to be paid for the Shop :- ";
			cin>>rent;
			do{
			cout<<"Enter date of Opening in (dd/mm/yy) :- ";
			fflush(stdin);
			cin.getline(dateofopen,20);
			}while(datetest(dateofopen));
		}
			void update(){
			cout<<"Enter Shop Name :- ";
			fflush(stdin);
			cin.getline(name,30);
			cout<<"Enter Owner's Name :- ";
			fflush(stdin);
			cin.getline(owner,30);
			cout<<"Enter type of Shop :- ";
			fflush(stdin);
			cin.getline(type,30);
			cout<<"Enter Rent per month to be paid for the Shop :- ";
			cin>>rent;
			do{
			cout<<"Enter date of Opening in (dd/mm/yy) :- ";
			fflush(stdin);
			cin.getline(dateofopen,20);
			}while(datetest(dateofopen));
		}
		
		void output(){
			cout<<"Shop ID :- "<<id<<endl<<"Name of Shop :- "<<name<<endl<<"Name of Owner :- "<<owner<<endl<<"Type :- "<<type<<endl<<"Rent per month :- "<<rent<<endl<<"Date of Opening :- "<<dateofopen<<endl<<endl;
		}
		int search(int l,int i,int n){
			if(id==l){
				return 1;
			}
			i++;
			if(i==n){
			cout<<"Shop ID not found.";
			getch();
			}
			return 0;
		}
		void del(shop s){
			id=s.id;
			strcpy(name,s.name);
			strcpy(owner,s.owner);
			strcpy(type,s.type);
			rent=s.rent;
			strcpy(dateofopen,s.dateofopen);
		}
		int checkid(int l){
			if(id==l){
				return 1;
			}			
			return 0;
		}
		void showrent(int dd,int &i){
			string d=dateofopen;
			string a=d.substr(0,2);
			string b=d.substr(d.find('/')+1,2);
			string c=d.substr(d.length()-2,2);
			int a1=atoi(a.c_str());	
			int b1=atoi(b.c_str());
			int c1=atoi(c.c_str());
			if(dd==a1){
				gotoxy(3,4+i);
				cout<<name;
				gotoxy(22,4+i);
				cout<<rent;
				i++;
			}
		}
};

class event{
	int id;
	char name[30];
	char organisername[30];
	char dateofevent[20];
	int amount;
	public:
		void input(int i){
				id=i;
				cout<<"Enter name of event :- ";
				fflush(stdin);
				cin.getline(name,30);
				cout<<"Enter name of Organiser :-";
				fflush(stdin);
				cin.getline(organisername,30);
				do{
				cout<<"Enter event to be held on (dd/mm/yy) :- ";
				fflush(stdin);
				cin.getline(dateofevent,20);
				}while(datetest(dateofevent));
				cout<<"Enter Budget for Event :- ";
				cin>>amount;
		}
		
		void output(){
			cout<<"Event ID :- "<<id<<endl<<"Name of Event :- "<<name<<endl<<"Organiser Name :- "<<organisername<<endl<<"Date to be held on :- "<<dateofevent<<endl<<"Budget for the event :- "<<amount<<endl<<endl;
		}
		
		int checkid(int l){
			if(id==l){
				return 1;
			}			
			return 0;
		}
		
		void eventout(int dd,int mm,int yy,int i){
			string d=dateofevent;
			string a=d.substr(0,2);
			string b=d.substr(d.find('/')+1,2);
			string c=d.substr(d.length()-2,2);
			int a1=atoi(a.c_str());	
			int b1=atoi(b.c_str());
			int c1=atoi(c.c_str());
			a1=a1-i;
			if(dd==a1){
				if(mm==b1){
					if(yy==c1){
						cout<<"                 "<<name;
					}
				}
			}
		}
		void eventoutmain(int dd,int mm,int yy,int &i){
			string d=dateofevent;
			string a=d.substr(0,2);
			string b=d.substr(d.find('/')+1,2);
			string c=d.substr(d.length()-2,2);
			int a1=atoi(a.c_str());	
			int b1=atoi(b.c_str());
			int c1=atoi(c.c_str());
			if(dd==a1){
				if(mm==b1){
					if(yy==c1){
						gotoxy(103,4+i);
						cout<<name;
						i++;
					}
				}
			}
		}
		
		int search(int l,int i,int n){
			if(id==l){
				return 1;
			}
			i++;
			if(i==n){
			cout<<"Shop ID not found.";
			getch();
			}
			return 0;
		}
		void update(){
				cout<<"Enter name of event :- ";
				fflush(stdin);
				cin.getline(name,30);
				cout<<"Enter name of Organiser :-";
				fflush(stdin);
				cin.getline(organisername,30);
				do{
				cout<<"Enter event to be held on (dd/mm/yy) :- ";
				fflush(stdin);
				cin.getline(dateofevent,20);
				}while(datetest(dateofevent));
				cout<<"Enter Budget for Event :- ";
				cin>>amount;
		}
		void del(event s){
			id=s.id;
			strcpy(name,s.name);
			strcpy(organisername,s.organisername);
			strcpy(dateofevent,s.dateofevent);
			amount=s.amount;
		}
};

class pvr{
	char movie[30];
	char type[20];
	char lang[20];
	char hero[30];
	char heroin[30];
	char dateofrelease[20];
	int ticket;
	int slots[3];
	int audi;
	public:
		pvr(){
			slots[0]=0;
			slots[1]=0;
			slots[2]=0;
		}
		void timeslots(){
			int i=0,k=0;
			pvr p;
			ifstream in("pvr.bin",ios::binary);
			in.seekg(0,ios::end);
			int len=in.tellg();
			int n=len/sizeof(p);
			in.seekg(0,ios::beg);
			pvr e[n];
			while(in.read((char *)&e[i],sizeof(e[i]))){
				i++;
			}
			int m=i;
			for(i=0;i<4;i++){
				system("cls");
				cout<<"Title of movie :- "<<movie<<endl<<"Type of movie :- "<<type<<endl<<"Language :- "<<lang<<endl<<"Name of Actor :- "<<hero<<endl<<"Name of Actress :- "<<heroin<<endl<<"Date of release of Movie :- "<<dateofrelease<<endl<<"Audi no :- "<<audi<<endl<<"Time slots :- ";
				cout<<endl<<"Enter any 3 time slots for the movie :- "<<endl;
				cout<<"Entered time Slots :- "<<slots[0]<<" "<<slots[1]<<" "<<slots[2]<<endl;
				cout<<"Available Time Slots for audi "<<audi<<" are :- "<<endl;
				cout<<endl<<"0. N.A."<<endl;
				if(m==0){
					cout<<"1. 06:00 A.M. to 09:00 A.M."<<endl;
					cout<<"2. 09:00 A.M. to 12:00 P.M."<<endl;
					cout<<"3. 12:00 P.M. to 03:00 P.M."<<endl;
					cout<<"4. 03:00 P.M. to 06:00 P.M."<<endl;
					cout<<"5. 06:00 P.M. to 09:00 P.M."<<endl;
					cout<<"6. 09:00 P.M. to 12:00 A.M."<<endl;
				}
				else{
					for(int j=0;j<n;j++){
						if((e[j].audi==audi)){
							if(!(e[j].slots[0]==1||e[j].slots[1]==1||e[j].slots[2]==1)){
								cout<<"1. 06:00 A.M. to 09:00 A.M."<<endl;
								k++;
							}
							if(!(e[j].slots[0]==2||e[j].slots[1]==2||e[j].slots[2]==2)){
								cout<<"2. 09:00 A.M. to 12:00 P.M."<<endl;
								k++;
							}
							if(!(e[j].slots[0]==3||e[j].slots[1]==3||e[j].slots[2]==3)){
								cout<<"3. 12:00 P.M. to 03:00 P.M."<<endl;
								k++;
							}
							if(!(e[j].slots[0]==4||e[j].slots[1]==4||e[j].slots[2]==4)){
								cout<<"4. 03:00 P.M. to 06:00 P.M."<<endl;
								k++;
							}
							if(!(e[j].slots[0]==5||e[j].slots[1]==5||e[j].slots[2]==5)){
								cout<<"5. 06:00 P.M. to 09:00 P.M."<<endl;
								k++;
							}
							if(!(e[j].slots[0]==6||e[j].slots[1]==6||e[j].slots[2]==6)){
								cout<<"6. 09:00 P.M. to 12:00 A.M."<<endl;
								k++;
							}
						}
					}
					if(k==0){
						cout<<"1. 06:00 A.M. to 09:00 A.M."<<endl;
						cout<<"2. 09:00 A.M. to 12:00 P.M."<<endl;
						cout<<"3. 12:00 P.M. to 03:00 P.M."<<endl;
						cout<<"4. 03:00 P.M. to 06:00 P.M."<<endl;
						cout<<"5. 06:00 P.M. to 09:00 P.M."<<endl;
						cout<<"6. 09:00 P.M. to 12:00 A.M."<<endl;
					}
				}
				if(i<3){
					cin>>slots[i];
					if(slots[i]>6||slots[i]<0){
						cout<<"You have entered wrong slot no."<<endl<<"Press any key to continue and re-enter the slot...";
						getch();
						slots[i]=0;
						i--;
					}
					if(slots[i]){
						if(i==1||i==2){
							if(slots[i]==slots[i-1]){
								cout<<"Slot is already taken."<<endl;
								slots[i]=0;
								i--;
							}
						}
					
					}
				}
			}
		}
		
		void showslots(){
			for(int i=0;i<3;i++){
				switch(slots[i]){
					case 0:cout<<"              Not Alloted."<<endl;
							break;
					case 1:cout<<"              06:00 A.M. to 09:00 A.M."<<endl;
							break;
					case 2:cout<<"              09:00 A.M. to 12:00 P.M."<<endl;
							break;
					case 3:cout<<"              12:00 P.M. to 03:00 P.M."<<endl;
							break;
					case 4:cout<<"              03:00 P.M. to 06:00 P.M."<<endl;
							break;
					case 5:cout<<"              06:00 P.M. to 09:00 P.M."<<endl;
							break;
					case 6:cout<<"              09:00 P.M. to 12:00 A.M."<<endl;
							break;
				}
			}
		}
		void input(char title[30]){
			strcpy(movie,title);
			cout<<"Type of movie :- ";
			fflush(stdin);
			cin.getline(type,20);
			cout<<"Enter language of movie :- ";
			fflush(stdin);
			cin.getline(lang,20);
			cout<<"Name of actor :- ";
			fflush(stdin);
			cin.getline(hero,30);
			cout<<"Name of actress :- ";
			fflush(stdin);
			cin.getline(heroin,30);
			do{
			cout<<"Enter date of release (dd/mm/yy):- ";
			fflush(stdin);
			cin.getline(dateofrelease,20);
			}
			while(datetest(dateofrelease));
			cout<<"Enter Audi no :- ";
			cin>>audi;
			cout<<"Enter ticket's price :- ";
			cin>>ticket;
			timeslots();
		}
		void output(){
			cout<<endl<<"Title of movie :- "<<movie<<endl<<"Type of movie :- "<<type<<endl<<"Language :- "<<lang<<endl<<"Name of Actor :- "<<hero<<endl<<"Name of Actress :- "<<heroin<<endl<<"Date of release of Movie :- "<<dateofrelease<<endl<<"Audi no :- "<<audi<<endl<<"Time slots :- "<<endl;
			showslots();
			cout<<"Price of ticket :- "<<ticket<<endl;
		}
		int checktime(pvr p){
			for(int i=0;i<3;i++){
				if(audi==p.audi){
					if(slots[i]==p.slots[i]){
						cout<<"Time slot is overlapping with show :- "<<movie<<endl<<"Error occured in slot :- "<<i+1;
						cout<<endl<<"Press any key to re-enter time slot.";
						getch();
						return 0;
					}
				}
			}
		}
		int cmpname(string name){
			string mname=movie;
			for(int i = 0; i < name.length(); ++i) {
                	name[i] = tolower(name[i]);
                }
        	for(int i = 0; i < mname.length(); ++i) {
            	    mname[i] = tolower(mname[i]);
                }
                if(mname==name){
                	return 1;
				}
				else return 0;
		}
		void del(pvr p){
			audi=p.audi;
			strcpy(dateofrelease,p.dateofrelease);
			strcpy(lang,p.lang);
			strcpy(hero,p.hero);
			strcpy(heroin,p.heroin);
			strcpy(movie,p.movie);
			ticket=p.ticket;
			strcpy(type,p.type);
			for(int i=0;i<3;i++){
				slots[i]=p.slots[i];
			}
		}
		int updatepvr(){
			system("cls");
			cout<<"Update details of movie :- "<<movie<<endl;
			char a;
			cout<<"Select the field which you want to update :- "<<endl<<"1. Title"<<endl<<"2. Type of movie"<<endl<<"3. Language"<<endl<<"4. Name of Actor"<<endl<<"5. Name of Actress"<<endl<<"6. Date of Release"<<endl<<"7. Price of Ticket"<<endl<<"8. Audi no"<<endl<<"9. Timeslots"<<endl<<"0. Back"<<endl;
			a=getch();
			switch(a){
				case '0':{
					return 0;
					break;
				}
				case '1': {
					int k=0,i=0;
					int a;
					pvr p;
					ifstream in("pvr.bin",ios::binary);
					in.seekg(0,ios::end);
					int len=in.tellg();
					int n=len/sizeof(p);
					in.seekg(0,ios::beg);
					pvr e[n];
					while(in.read((char *)&e[i],sizeof(e[i]))){
						i++;
					}
					cout<<"Title of Movie :- "<<movie;
					cout<<endl<<"Enter title of the movie to update :- ";
					do{
						fflush(stdin);
						cin.getline(movie,30);
						a=e[k].cmpname(movie);
						if(a){
							cout<<"Movie title already exist."<<endl<<"Press any key to re-enter...";
							getch();
							k++;
							cout<<endl<<"Enter title of movie again :- ";
						}
					}while(a);
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '2': {
					cout<<"Type of Movie :- "<<type;
					cout<<endl<<"Enter type of the movie to update :- ";
					fflush(stdin);
					cin.getline(type,20);
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '3': {
					cout<<"Language of Movie :- "<<lang;
					cout<<endl<<"Enter language of the movie to update :- ";
					fflush(stdin);
					cin.getline(lang,20);
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '4': {
					cout<<"Name of Actor :- "<<movie;
					cout<<endl<<"Enter name of actor to update :- ";
					fflush(stdin);
					cin.getline(hero,30);
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '5': {
					cout<<"Name of Actress :- "<<movie;
					cout<<endl<<"Enter name of actress to update :- ";
					fflush(stdin);
					cin.getline(heroin,30);
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '6': {
					cout<<"Date of Release of Movie :- "<<dateofrelease;
					cout<<endl<<"Enter date of release of the movie to update :- ";
					do{
						fflush(stdin);
						cin.getline(dateofrelease,20);
					}
					while(datetest(dateofrelease));
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '7': {
					cout<<"Price of ticket :- "<<ticket;
					cout<<endl<<"Enter price of ticket to update :- ";
					cin>>ticket;
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '8': {
					int temp=audi;
					cout<<"Audi no :- "<<audi;
					cout<<endl<<"Enter audi no to update :- ";
					cin>>audi;
					if(!(audi==temp)){
					cout<<"Please select the timeslots for audi"<<audi<<" :- "<<endl;
					this->timeslots();
					}
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				case '9': {
					int i,temp1=slots[0],temp2=slots[1],temp3=slots[2];
					slots[0]=slots[1]=slots[2]=0;
					pvr p;
					ifstream in("pvr.bin",ios::binary);
					in.seekg(0,ios::end);
					int len=in.tellg();
					int n=len/sizeof(p);
					in.seekg(0,ios::beg);
					pvr e[n];
					while(in.read((char *)&e[i],sizeof(e[i]))){
						i++;
					}	
					for(i=0;i<4;i++){
						system("cls");
						cout<<endl<<"Enter any 3 time slots for the movie :- "<<endl;
						cout<<"Previously Entered time Slots :- "<<temp1<<" "<<temp2<<" "<<temp3<<endl;
						cout<<"Newly Entered time Slots :- "<<slots[0]<<" "<<slots[1]<<" "<<slots[2]<<endl;
						cout<<"Available Time Slots for audi "<<audi<<" are :- "<<endl;
						cout<<endl<<"0. N.A."<<endl;
						for(int j=0;j<n;j++){
							if(!e[j].cmpname(movie)){
							if((e[j].audi==audi)){
								if(!(e[j].slots[0]==1||e[j].slots[1]==1||e[j].slots[2]==1)){
										cout<<"1. 06:00 A.M. to 09:00 A.M."<<endl;
									}
									if(!(e[j].slots[0]==2||e[j].slots[1]==2||e[j].slots[2]==2)){
										cout<<"2. 09:00 A.M. to 12:00 P.M."<<endl;
									}
									if(!(e[j].slots[0]==3||e[j].slots[1]==3||e[j].slots[2]==3)){
										cout<<"3. 12:00 P.M. to 03:00 P.M."<<endl;
									}
									if(!(e[j].slots[0]==4||e[j].slots[1]==4||e[j].slots[2]==4)){
										cout<<"4. 03:00 P.M. to 06:00 P.M."<<endl;
									}
									if(!(e[j].slots[0]==5||e[j].slots[1]==5||e[j].slots[2]==5)){
										cout<<"5. 06:00 P.M. to 09:00 P.M."<<endl;
									}
									if(!(e[j].slots[0]==6||e[j].slots[1]==6||e[j].slots[2]==6)){
										cout<<"6. 09:00 P.M. to 12:00 A.M."<<endl;
									}
								}
							}
						}
						if(i<3){
							cin>>slots[i];
							if(slots[i]>6||slots[i]<0){
								cout<<"You have entered wrong slot no."<<endl<<"Press any key to continue and re-enter the slot...";
								getch();
								slots[i]=0;
								i--;
							}
							if(slots[i]){
								if(i==1||i==2){
									if(slots[i]==slots[i-1]){
										cout<<"Slot is already taken."<<endl;
										slots[i]=0;
										i--;
									}
								}
							}
						}
					}
					cout<<endl<<"Succesfully Updated.";
					cout<<endl<<"Press any key to continue...";
					getch();
					this->updatepvr();
					break;
				}
				default: this->updatepvr();
			}
		}
		void showpvr(int n,int &i){
			if(slots[0]==n||slots[1]==n||slots[2]==n){
				gotoxy(49,4+i);
				cout<<movie;
				gotoxy(73,4+i);
				cout<<audi;
				i++;
			}
		}
};

class parking{
	int id;
	char desc[100];
	char date[20];
	char doneby[30];
	char remarks[100];
	public:
		void input(int n){
			id=n;
			do{
			cout<<"Maintenance performed on (dd/mm/yy):- ";
			fflush(stdin);
			cin.getline(date,20);
			}while(datetest(date));
			cout<<"Maintenance done by :- ";
			fflush(stdin);
			cin.getline(doneby,30);
			cout<<"Description of maintenance :- ";
			fflush(stdin);
			cin.getline(desc,100);
			cout<<"Remarks :- ";
			fflush(stdin);
			cin.getline(remarks,100);
		}
		void output(){
			system("cls");
			cout<<"Maintenance ID :- "<<id<<endl<<"Date of maintenance :- "<<date<<endl<<"Maintenance done by :- "<<doneby<<endl<<"Description of maintenance :- "<<desc<<endl<<"Remarks :- "<<remarks<<endl;
		}
		int checkid(int l){
			if(id==l){
				return 1;
			}			
			return 0;
		}
		int search(int l,int i,int n){
			if(id==l){
				return 1;
			}
			i++;
			if(i==n){
			cout<<"Maintenance ID not found.";
			getch();
			}
			return 0;
		}
		void update(){
			do{
			cout<<"Maintenance performed on (dd/mm/yy):- ";
			fflush(stdin);
			cin.getline(date,20);
			}while(datetest(date));
			cout<<"Maintenance done by :- ";
			fflush(stdin);
			cin.getline(doneby,30);
			cout<<"Description of maintenance :- ";
			fflush(stdin);
			cin.getline(desc,100);
			cout<<"Remarks :- ";
			fflush(stdin);
			cin.getline(remarks,100);
		}
		void del(parking p){
			id=p.id;
			strcpy(date,p.date);
			strcpy(doneby,p.doneby);
			strcpy(desc,p.desc);
			strcpy(remarks,p.remarks);
		}
};

class security{
	int id;
	char name[30];
	int desig[2];
	int salary;
	char no[20];
	char email[30];
		public:
			void input(int n){
				id=n;
				int a=0;
				cout<<"Enter Name :- ";
				fflush(stdin);
				cin.getline(name,30);
				cout<<"Designation :- "<<endl<<"1. Incharge"<<endl<<"2. Guard"<<endl;
				do{
					a=0;
					cin>>desig[0];
					if(desig[0]==2){
						do{
							a=0;
							cout<<"Duty area of guard :- "<<endl<<"1. Inside Mall"<<endl<<"2. Parking Lot"<<endl<<"3. Entry/Exit Gate"<<endl;
							cin>>desig[1];
							if(desig[1]>3&&desig[1]<1){
								a=1;
								cout<<"Incorrect Input... Please re-enter :- ";
							}
						}while(a);
					}
					else {
						desig[1]=0;
					}
					if(desig[0]>2&&desig[0]<1){
						a=1;
						cout<<"Incorrect Input... Please re-enter :- ";
					}
				}while(a);
				do{
					a=0;
					cout<<"Contact Details :- "<<endl<<"Enter 10 digit contact no. :- ";
					fflush(stdin);
					cin.getline(no,20);
					if(checkno(no)){
						a=1;
						cout<<"Invalid contact no. Please re-enter :- ";
					}
				}while(a);
				do{
					cout<<"Enter email id :- ";
					fflush(stdin);
					cin.getline(email,30);
					a=checkemail(email);
				}while(a);
				cout<<"Enter Salary :- ";
				cin>>salary;
			}
			
		void output(int n){
			if(desig[0]==n){
				cout<<"Security ID :- "<<id<<endl<<"Name :- "<<name<<endl<<"Designation :- ";
				if(desig[0]==1){
					cout<<"Incharge"<<endl;
				}
				else{
					cout<<"Guard"<<endl;
					cout<<"Duty Area :- ";
					if(desig[1]==1){
						cout<<"Inside Mall"<<endl;
					}
					if(desig[1]==2){
						cout<<"Parking Lot"<<endl;
					}
					if(desig[1]==3){
						cout<<"Entry/Exit Gate"<<endl;
					}
				}
				cout<<"Salary :- "<<salary<<endl;
				cout<<"Contact Details :- "<<endl<<"Contact no :- "<<no<<endl<<"Email ID :- "<<email<<endl;
			}
		}
		int checkid(int l){
			if(id==l){
				return 1;
			}			
			return 0;
		}
		int search(int l,int i,int n){
			if(id==l){
				return 1;
			}
			i++;
			if(i==n){
			cout<<"Security ID not found.";
			getch();
			}
			return 0;
		}
		void update(){
				int a=0;
				cout<<"Enter Name :- ";
				fflush(stdin);
				cin.getline(name,30);
				cout<<"Designation :- "<<endl<<"1. Incharge"<<endl<<"2. Guard"<<endl;
				do{
					a=0;
					cin>>desig[0];
					if(desig[0]==2){
						do{
							a=0;
							cout<<"Duty area of guard :- "<<endl<<"1. Inside Mall"<<endl<<"2. Parking Lot"<<endl<<"3. Entry/Exit Gate"<<endl;
							cin>>desig[1];
							if(desig[1]>3&&desig[1]<1){
								a=1;
								cout<<"Incorrect Input... Please re-enter :- ";
							}
						}while(a);
					}
					else {
						desig[1]=0;
					}
					if(desig[0]>2&&desig[0]<1){
						a=1;
						cout<<"Incorrect Input... Please re-enter :- ";
					}
				}while(a);
				cout<<"Contact Details :- "<<endl<<"Enter 10 digit contact no. :- ";
				fflush(stdin);
				cin.getline(no,20);
				do{
					cout<<"Enter email id :- ";
					fflush(stdin);
					cin.getline(email,30);
					a=checkemail(email);
				}while(a);
				cout<<"Enter Salary :- ";
				cin>>salary;
		}
		void del(security s){
			id=s.id;
			strcpy(name,s.name);
			desig[0]=s.desig[0];
			desig[1]=s.desig[1];
			salary=s.salary;
			strcpy(no,s.no);
			strcpy(email,s.email);
		}
};

class set{
	public:
	int pass;
	int show[3];
		set(){
			pass=1234;
			show[0]=1;
			show[1]=1;
			show[2]=1;
		}
		void passinput(){
			int i=0;
			string value;
			char key;
			do{
				key = getch();
		 		switch (key){
					case '\b':{
						if(value.length() > 0)
					  	{
							value.erase(value.length() - 1, 1);
							cout << '\b' << " " << '\b';
					 	}
						break;
					}
					default:
					if(key > 31 && key < 127)
					{
						value.push_back(key);
						cout << "*";
					}
		 		}
			} while(value.length()!=4);
			pass=atoi(value.c_str());
		}
 		int check(int password){
  			if(password==pass)
  			{
  				return 1;	
			}
		  else return 0;
	    }
	    
		
}s;

void addshop(){
	system("cls");
	char y;
	shop d;
	int id,i,a,len,n;
	ifstream in("shop.bin",ios::binary);
	in.seekg(0,ios::end);
	len=in.tellg();
	n=len/sizeof(d);
	in.seekg(0,ios::beg);
	shop s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
	}
	in.close();
	do{
		cout<<"Enter Shop ID :- ";
		cin>>id;
		for(i=0;i<n;i++){
			a=s[i].checkid(id);
			if(a==1){
				cout<<"Entered ID already exist."<<endl<<"Press any key to continue...";
				getch();
				addshop();
			}
		}
		d.input(id);
		ofstream out("shop.bin",ios::app|ios::binary);
		out.write((char *)&d,sizeof(d));
		out.close();
		cout<<endl<<"Add more shops ? (y/n) :- ";
		fflush(stdin);
		y=getch();
	}
	while(i=='y'||i=='Y');
	shopdetail();
}

void updateshop(){
	ifstream in("shop.bin",ios::binary);
	int id,i,a;
	shop d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	shop s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Shop ID to update :- ";
	cin>>id;
	for(i=0;i<n;i++){
		a=s[i].search(id,i,n);
		if(a==1){
		s[i].update();
		break;
		}
	}
	ofstream out("shop.bin",ios::binary);
	for(i=0;i<n;i++){
		out.write((char *)&s[i],sizeof(s[i]));
	}
	out.close();
	shopdetail();
}

void deleteshop(){
	ifstream in("shop.bin",ios::binary);
	int id,a,i;
	shop d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	shop s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Shop ID to delete :- ";
	cin>>id;
	for(i=0;i<n;i++){
			a=s[i].search(id,i,n);
			if(a==1){
			for(int j=i;j<n;j++){
				s[j].del(s[j+1]);
			}
			ofstream out("shop.bin",ios::binary);
			for(i=0;i<n-1;i++){
				out.write((char *)&s[i],sizeof(s[i]));
			}
			out.close();	
			break;
		}
	}

	shopdetail();
}

void shoprent(int d){
	int i=0,j=0;
	ifstream in("shop.bin",ios::binary);
	shop e;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(e);
	shop s[n];
	in.seekg(0,ios::beg);
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			s[i].showrent(d,j);
			i++;
		}
		in.close();
	}
}

void shopdetail(){
	char i;
	ifstream in("shop.bin",ios::binary);
	shop d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	shop s[n];
	in.seekg(0,ios::beg);
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			s[i].output();
			i++;
		}
		in.close();
		cout<<endl<<"1. Add    2. Update    3. Delete    4. Back"<<endl;
		fflush(stdin);
		i=getch();
		switch(i){
			case '1': addshop();
					break;
			case '2': updateshop();
					break;
			case '3': deleteshop();
					break;
			case '4': mainmenu();
					break;
			default : shops();
		}
	}
	else {
		cout<<"Nothing to show... Database doesn't exist."<<endl<<"Creating Database...."<<endl<<"Press any key to continue.";
		ofstream out("shop.bin",ios::binary);
		out.close();
		getch();
		shops();
	}
}

void shops(){
	int i;
	system("cls");
	ifstream in("shop.bin",ios::binary);
	shop d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.close();
	cout<<"Total no. of Shops :- 50"<<endl;
	cout<<"Shops Occupied :- "<<n<<endl;
	cout<<"Shops Vacant :- "<<50-n<<endl<<endl;
	shopdetail();
	}
	
void addevent(){
	int i,id,a;
	char y;
	system("cls");
	ifstream in("event.bin",ios::binary);
	if(in){
		event d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		event e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		do{
			cout<<"Enter Event ID :- ";
			cin>>id;
			for(i=0;i<n;i++){
				a=e[i].checkid(id);
				if(a==1){
					cout<<"Entered ID already exist."<<endl<<"Press any key to continue...";
					getch();
					addevent();
				}
			}
		d.input(id);
		ofstream out("event.bin",ios::app|ios::binary);
		out.write((char *)&d,sizeof(d));
		out.close();
		cout<<endl<<"Add more events ? (y/n) :- ";
		cin>>y;
	}
	while(y=='y'||y=='Y');
	events();
	}
	else {
		ofstream out("event.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		addevent();
	}
}

void updateevent(){
	ifstream in("event.bin",ios::binary);
	int id,i,a;
	event d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	event s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Event ID to update :- ";
	cin>>id;
	for(i=0;i<n;i++){
		a=s[i].search(id,i,n);
		if(a==1){
		s[i].update();
		break;
		}
	}
	
	ofstream out("event.bin",ios::binary);
	for(i=0;i<n;i++){
		out.write((char *)&s[i],sizeof(s[i]));
	}
	out.close();
	eventdetails();
}

void deleteevent(){
	ifstream in("event.bin",ios::binary);
	int id,a,i;
	event d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	event s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Event ID to delete :- ";
	cin>>id;
	for(i=0;i<n;i++){
			a=s[i].search(id,i,n);
			if(a==1){
			for(int j=i;j<n;j++){
				s[j].del(s[j+1]);
			}
			ofstream out("event.bin",ios::binary);
			for(i=0;i<n-1;i++){
				out.write((char *)&s[i],sizeof(s[i]));
			}
			out.close();	
			break;
		}
	}

	eventdetails();
}

void eventdetails(){
	int i;
	char y,n;
	system("cls");
	ifstream in("event.bin",ios::binary);
	if(in){
		event d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		event e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			e[i].output();
			i++;
		}
		in.close();
	}
	cout<<endl<<"1. Add    2. Update    3. Delete    4. Back"<<endl;
	    fflush(stdin);
		n=getch();
		switch(n){
			case '1': addevent();
					break;
			case '2': updateevent();
					break;
			case '3': deleteevent();
					break;
			case '4': events();
					break;
			default : eventdetails();
		}
}

void teventmain(int dd,int mm,int yy){
	ifstream in("event.bin",ios::binary);
	int i=0,j=0;
	if(in){
		event d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		event e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
    	for(i=0;i<n;i++){
    		e[i].eventoutmain(dd,mm,yy,j);
		}
}
}

void tevent(int dd,int mm,int yy){
	ifstream in("event.bin",ios::binary);
	int i;
	if(in){
		event d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		event e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
    	for(i=0;i<n;i++){
    		e[i].eventout(dd,mm,yy,0);
		}
}
}


void upevent(int dd,int mm,int yy){
	ifstream in("event.bin",ios::binary);
	int i;
	if(in){
		event d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		event e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
    	for(i=0;i<n;i++){
    		e[i].eventout(dd,mm,yy,1);
		}
}
}

void events(){
	system("cls");
 	int d1, m1, y1 ;
 	time_t td = time(0);
 	struct tm * now = localtime( & td );
	d1 = now->tm_mday ;
 	m1 = (now->tm_mon +1 ) ;
 	y1 = (now->tm_year +1900 );
 	gotoxy(45,4) ;
 	cout <<"Date: " <<d1 <<"/" <<m1 <<"/" <<y1 ;
	char i;
	cout<<endl<<"Today's Event :- ";
	tevent(d1,m1,y1-2000);
	cout<<endl<<"Upcoming Event :- ";
	upevent(d1,m1,y1-2000);
	cout<<endl<<endl<<"1. Add Event"<<endl;
	cout<<"2. Details of Event"<<endl;
	cout<<"3. Back"<<endl;
	fflush(stdin);
	i=getch();
	switch(i){
		case '1': addevent();
				break;
		case '2': eventdetails();
				break;
		case '3': mainmenu();
				break;
		default: events();
	}
}

void curshow(int t){
	ifstream in("pvr.bin",ios::binary);
	int i=0,slot,j=0;
	if(t>=6&&t<9){
		slot=1;
	}
	else if(t>=9&&t<12){
		slot=2;
	}
	else if(t>=12&&t<15){
		slot=3;
	}
	else if(t>=15&&t<18){
		slot=4;
	}
	else if(t>=18&&t<21){
		slot=5;
	} 
	else if(t>=21&&t<24){
		slot=6;
	}
	else slot=-1;
	if(slot!=-1){
		if(in){
			pvr d;
			in.seekg(0,ios::end);
			int len=in.tellg();
			int n=len/sizeof(d);
			in.seekg(0,ios::beg);
			pvr e[n];
			while(in.read((char *)&e[i],sizeof(e[i]))){
				e[i].showpvr(slot,j);
				i++;
			}
			in.close();
		}
	}
	else {
		gotoxy(45,4);
		cout<<"-------No shows currently------";
	}
}

void addmovie(){
	int i,k=0,a;
	char y,movie[30];
	system("cls");
	ifstream in("pvr.bin",ios::binary);
	if(in){
		pvr d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		pvr e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		do{
		do{
		cout<<"Enter title of movie :- ";
		fflush(stdin);
		cin.getline(movie,30);
		a=e[k].cmpname(movie);
		if(a){
			cout<<"Movie title already exist."<<endl<<"Press any key to re-enter...";
			getch();
			cout<<endl;
			k++;
		}
		}while(a);
		d.input(movie);
			for(i=0;i<n;i++){
				for(int j=0;j<3;j++){
					if(!e[i].checktime(d)){
						d.timeslots();
					}
				}
			}
			for(i=0;i<n;i++){
				for(int j=0;j<3;j++){
					if(!e[i].checktime(d)){
						d.timeslots();
					}
				}
			}
			for(i=0;i<n;i++){
				for(int j=0;j<3;j++){
					if(!e[i].checktime(d)){
						d.timeslots();
					}
				}
			}
		ofstream out("pvr.bin",ios::app|ios::binary);
		out.write((char *)&d,sizeof(d));
		out.close();
		cout<<endl<<"Add more movie details ? (y/n) :- ";
		y=getch();
	}
	while(y=='y'||y=='Y');
	}
	else {
		ofstream out("pvr.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		addmovie();
	}
	pvrdetails();
}

void uppvr(){
	int i=0;
	ifstream in("pvr.bin",ios::binary);
	if(in){
		pvr d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		pvr e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		string name;
		cout<<endl<<endl<<"Enter the title of movie to update :- ";
		fflush(stdin);
		getline(cin,name);
		for(i=0;i<n;i++){
			if(e[i].cmpname(name)){
				e[i].updatepvr();
				ofstream out("pvr.bin",ios::binary);
				for(i=0;i<n;i++){
					out.write((char *)&e[i],sizeof(e[i]));
				}
				out.close();
				break;
			}
		}
	}
	pvrdetails();
}

void delpvr(){
	int i=0;
	ifstream in("pvr.bin",ios::binary);
	if(in){
		pvr d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		pvr e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		string name;
		cout<<endl<<endl<<"Enter the title of movie to delete :- ";
		fflush(stdin);
		getline(cin,name);
		for(i=0;i<n;i++){
			if(e[i].cmpname(name)){
				for(int j=i;j<n;j++){
					e[j].del(e[j+1]);
				}
				ofstream out("pvr.bin",ios::binary);
				for(i=0;i<n-1;i++){
				out.write((char *)&e[i],sizeof(e[i]));
			}
			out.close();
			break;
			}
		}
	}
	pvrdetails();
}

void pvrdetails(){
	char i;
	system("cls");
	ifstream in("pvr.bin",ios::binary);
	if(in){
		pvr d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		if(len==0){
			cout<<"No details to show.";
			cout<<endl<<"Press any key to continue...";
			getch();
			pvrmenu();
		}
		in.seekg(0,ios::beg);
		pvr e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			e[i].output();
			i++;
		}
		in.close();
		cout<<endl<<endl<<"1. Update Details          2. Delete Details        3. Back"<<endl;
		i=getch();
		switch(i){
			case '1':uppvr();
					break;
			case '2':delpvr();
					break;
			case '3':pvrmenu();
					break;
			default: pvrdetails();
		}
}
else {
	cout<<"Database not found."<<endl<<"Creating new database..."<<endl<<"Press any key to continue :- ";
	ofstream out("pvr.bin",ios::binary);
	out.close();
	getch();
	pvrdetails();
}
}

void pvrmenu(){
	system("cls");
	char n;
	cout<<"1. Add Movie Details";
	cout<<endl<<"2. Show Movie Details";
	cout<<endl<<"3. Back"<<endl;
	fflush(stdin);
	n=getch();
	switch(n){
		case '1': addmovie();
				break;
		case '2': pvrdetails();
				break;
		case '3': mainmenu();
				break;
		default: pvrmenu();
	}
}

void uppark(){
	int id,i=0,a;
	ifstream in("park.bin",ios::binary);
	if(in){
		parking d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		parking e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		cout<<endl<<endl<<"Enter Maintenance ID to update :- ";
		cin>>id;
		for(i=0;i<n;i++){
			a=e[i].search(id,i,n);
			if(a==1){
				e[i].update();
				ofstream out("park.bin",ios::binary);
				for(int j=0;j<n;j++){
					out.write((char *)&e[j],sizeof(e[j]));
				}
				out.close();
				break;
			}
		}
	}
	showpark();
}

void delpark(){
	ifstream in("park.bin",ios::binary);
	int id,a,i;
	parking d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	parking s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Maintenance ID to delete :- ";
	cin>>id;
	for(i=0;i<n;i++){
			a=s[i].search(id,i,n);
			if(a==1){
			for(int j=i;j<n;j++){
				s[j].del(s[j+1]);
			}
			ofstream out("park.bin",ios::binary);
			for(i=0;i<n-1;i++){
				out.write((char *)&s[i],sizeof(s[i]));
			}
			out.close();	
			break;
		}
	}

	showpark();
}

void showpark(){
	char a;
	int i;
	system("cls");
	ifstream in("park.bin",ios::binary);
	if(in){
		parking d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		if(len==0){
			cout<<"No details to show.";
			cout<<endl<<"Press any key to continue...";
			getch();
			park();
		}
		in.seekg(0,ios::beg);
		parking e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			e[i].output();
			i++;
		}
		in.close();
		cout<<endl<<"1. Update Log              2. Delete Log               3. Back"<<endl;
		a=getch();
		switch(a){
			case '1':{
				uppark();
				break;
			}
			case '2':{
				delpark();
				break;
			}
			case '3':{
				park();
				break;
			}
			default:{
				showpark();
				break;
			}
		}
	}
	else {
		ofstream out("park.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		showpark();
	}
}
void addpark(){
	system("cls");
	int id,i=0,a;
	char y;
	ifstream in("park.bin",ios::binary);
	if(in){
		parking d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		parking e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		do{
			cout<<"Enter Maintenance ID :- ";
			cin>>id;
			for(i=0;i<n;i++){
				a=e[i].checkid(id);
				if(a==1){
					cout<<"Entered ID already exist."<<endl<<"Press any key to continue...";
					getch();
					addpark();
				}
			}
		d.input(id);
		ofstream out("park.bin",ios::app|ios::binary);
		out.write((char *)&d,sizeof(d));
		out.close();
		cout<<endl<<"Add more logs ? (y/n) :- ";
		cin>>y;
	}
	while(y=='y'||y=='Y');
	}
	else {
		ofstream out("park.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		addpark();
	}
	showpark();
}

void park(){
	system("cls");
	char a;
	cout<<"1. Add Maintenance Log"<<endl<<"2. Show Maintenance Log"<<endl<<"3. Back"<<endl;
	a=getch();
	switch(a){
		case '1':{
			addpark();
			break;
		}
		case '2':{
			showpark();
			break;
		}
		case '3':{
			mainmenu();
			break;
		}
		default:{
			park();
			break;
		}
	}
}


void upsec(){
	int id,i=0,a;
	ifstream in("security.bin",ios::binary);
	if(in){
		security d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		security e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		cout<<endl<<endl<<"Enter Security ID to update :- ";
		cin>>id;
		for(i=0;i<n;i++){
			a=e[i].search(id,i,n);
			if(a==1){
				e[i].update();
				ofstream out("security.bin",ios::binary);
				for(int j=0;j<n;j++){
					out.write((char *)&e[j],sizeof(e[j]));
				}
				out.close();
				break;
			}
		}
	}
	securitymenu();
}

void delsec(){
	ifstream in("security.bin",ios::binary);
	int id,a,i;
	security d;
	in.seekg(0,ios::end);
	int len=in.tellg();
	int n=len/sizeof(d);
	in.seekg(0,ios::beg);
	security s[n];
	if(in){
		while(in.read((char *)&s[i],sizeof(s[i]))){
			i++;
		}
		in.close();
		}
	cout<<endl<<"Enter Security ID to delete :- ";
	cin>>id;
	for(i=0;i<n;i++){
			a=s[i].search(id,i,n);
			if(a==1){
			for(int j=i;j<n;j++){
				s[j].del(s[j+1]);
			}
			ofstream out("security.bin",ios::binary);
			for(i=0;i<n-1;i++){
				out.write((char *)&s[i],sizeof(s[i]));
			}
			out.close();	
			break;
		}
	}

	securitymenu();
}

void addsec(){
	system("cls");
	int id,i=0,a;
	char y;
	ifstream in("security.bin",ios::binary);
	if(in){
		security d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		in.seekg(0,ios::beg);
		security e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			i++;
		}
		in.close();
		do{
			cout<<"Enter Security ID :- ";
			cin>>id;
			for(i=0;i<n;i++){
				a=e[i].checkid(id);
				if(a==1){
					cout<<"Entered ID already exist."<<endl<<"Press any key to continue...";
					getch();
					addsec();
				}
			}
		d.input(id);
		ofstream out("security.bin",ios::app|ios::binary);
		out.write((char *)&d,sizeof(d));
		out.close();
		cout<<endl<<"Add more details ? (y/n) :- ";
		cin>>y;
	}
	while(y=='y'||y=='Y');
	}
	else {
		ofstream out("security.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		addsec();
	}
	securitymenu();
}

void secshow(int s){
	char a;
	int i;
	system("cls");
	ifstream in("security.bin",ios::binary);
	if(in){
		security d;
		in.seekg(0,ios::end);
		int len=in.tellg();
		int n=len/sizeof(d);
		if(s==1){
			cout<<"Details of Security Incharges :- "<<endl<<endl;
		}
		else cout<<"Details of Security Guards :- "<<endl<<endl;
		if(len==0){
			cout<<"No details to show.";
		}
		in.seekg(0,ios::beg);
		security e[n];
		while(in.read((char *)&e[i],sizeof(e[i]))){
			e[i].output(s);
			i++;
		}
		in.close();
		cout<<endl<<"1. Add Details          2. Update Details              3. Delete Details               4. Back"<<endl;
		a=getch();
		switch(a){
			case '1':{
				addsec();
				break;
			}
			case '2':{
				upsec();
				break;
			}
			case '3':{
				delsec();
				break;
			}
			case '4':{
				securitymenu();
				break;
			}
			default:{
				secshow(s);
				break;
			}
		}
	}
	else {
		ofstream out("security.bin",ios::binary);
		out.close();
		cout<<"Database Doesn't Exist."<<endl<<"Creating Database..."<<endl<<"Press any key to continue.";
		getch();
		secshow(s);
	}
}


void securitymenu(){
	system("cls");
	char a;
	cout<<"1. Security Guards Details"<<endl<<"2. Security Incharges Details"<<endl<<"3. Back"<<endl;
	a=getch();
	switch(a){
		case '1':{
			secshow(2);
			break;
		}
		case '2':{
			secshow(1);
			break;
		}
		case '3':{
			mainmenu();
			break;
		}
		default:{
			securitymenu();
			break;
		}
	}
}

void changepin(){
	int pass;
	system("cls");
	cout<<"Enter old 4-Digit Pin :- ";
	cin>>pass;
	if(s.check(pass)){
		cout<<"Enter New 4-Digit Pin :- ";
		s.passinput();
		cout<<endl<<"Changed Succesfully.";
		ofstream out("setting.bin",ios::binary);
		out.write((char *)&s,sizeof(s));
		out.close();
		getch();
		setting();
	}
	else{
		cout<<"Incorrect Pin..."<<endl<<"Press any key & re-enter :- ";
		getch();
		changepin();
	}
}


void delrecord(){
	char c;
	cout<<endl<<"Are you sure you want to delete all records :- (y/n) :- ";
	cin>>c;
	if(c=='y'||c=='Y'){
		ofstream out("shop.bin",ios::binary);
		ofstream out1("event.bin",ios::binary);
		ofstream out2("pvr.bin",ios::binary);
		ofstream out3("park.bin",ios::binary);
		out3.close();
		out2.close();
		out1.close();
		out.close();
		cout<<"All records Deleted Succesfully."<<endl<<"Press any key to continue...";
		getch();
	}
	else setting();
}

void showhide(){
	system("cls");
	char a,b;
	cout<<"Show/Hide Items from Home Screen :- "<<endl;
	cout<<"1. Show/Hide todays events"<<endl<<"2. Show/Hide Shops Rent"<<endl<<"3. Show/Hide PVR Shows"<<endl<<"4. Back"<<endl;
	a=getch();
	switch(a){
		case '1':{
			cout<<endl<<"Events :- ";
			cout<<endl<<"1. Show      2. Hide"<<endl;
			b=getch();
			if(b=='1'){
				s.show[0]=1;
			}
			else if(b=='2'){
				s.show[0]=0;
			}
			else {
				cout<<"Invalid Input....";
				getch();
			}
			ofstream out("setting.bin",ios::binary);
			out.write((char *)&s,sizeof(s));
			out.close();
			showhide();
			break;
		}
		case '2':{
			cout<<endl<<"Shops Rent :- ";
			cout<<endl<<"1. Show      2. Hide"<<endl;
			b=getch();
			if(b=='1'){
				s.show[1]=1;
			}
			else if(b=='2'){
				s.show[1]=0;
			}
			else{
				cout<<"Invalid Input....";
				getch();
			}
			ofstream out("setting.bin",ios::binary);
			out.write((char *)&s,sizeof(s));
			out.close();
			showhide();
			break;
		}
		case '3':{
			cout<<endl<<"PVR Shows :- ";
			cout<<endl<<"1. Show      2. Hide"<<endl;
			b=getch();
			if(b=='1'){
				s.show[2]=1;
			}
			else if(b=='2'){
				s.show[2]=0;
			}
			else {
				cout<<"Invalid Input....";
				getch();
			}
			ofstream out("setting.bin",ios::binary);
			out.write((char *)&s,sizeof(s));
			out.close();
			showhide();
			break;
		}
		case '4':{
			setting();
		}
		default:{
			showhide();
			break;
		}
	}
}

void setting(){
	system("cls");
	char a;
	cout<<"1. Change Pin"<<endl<<"2. Delete All Records"<<endl<<"3. Show/Hide ELemets on mainscreen"<<endl<<"4. Back"<<endl;
	a=getch();
	switch(a){
		case '1':{
			changepin();
			break;
		}
		case '2':{
			delrecord();
			break;
		}
		case '3':{
			showhide();
			break;
		}
		case '4':{
			mainmenu();
			break;
		}
		default:{
			setting();
			break;
		}
	}
}

void mainmenu(){
	system("color 1f");
	system("cls");
	int d,m,y,t,j=0,i=0;
 	time_t td = time(0);
 	struct tm * now = localtime( & td );
	d = now->tm_mday ;
 	m = (now->tm_mon +1 ) ;
 	y = (now->tm_year +1900 );
 	t=now->tm_hour;
 	if(s.show[0]==1){
		gotoxy(97,2);
		cout<<"|===============|";
		gotoxy(97,3);
		cout<<"| Today's Event |";
		teventmain(d,m,y-2000);
		cout<<endl<<"                                                                                                 |===============|"<<endl;
	}
	if(s.show[1]==1){
		gotoxy(1,2);
		cout<<"Shops to pay rent :- ";
		gotoxy(1,3);
		cout<<"Shops Name         Rent to be paid";
		shoprent(d);
	}
	if(s.show[2]==1){
		gotoxy(48,2);
		cout<<"Currently running movies";
		gotoxy(45,3);
		cout<<"Title of Movie             Audi"<<endl;
		curshow(t);
	}
	if(s.show[2]==0){
		j=8;
	}
 	gotoxy(97,28);
 	cout <<"Date: " <<d <<"/" <<m <<"/" <<y ;
	gotoxy(44-i,13-j);
	cout<<"||========================||";
	gotoxy(44-i,14-j);
	cout<<"||                        ||";
	gotoxy(44-i,15-j);
	cout<<"||         1. Shops       ||";
	gotoxy(44-i,16-j);
	cout<<"||                        ||";
	gotoxy(44-i,17-j);
	cout<<"||          2. PVR        ||";
	gotoxy(44-i,18-j);
	cout<<"||                        ||";
	gotoxy(44-i,19-j);
	cout<<"||         3. Events      ||";
	gotoxy(44-i,20-j);
	cout<<"||                        ||";
	gotoxy(44-i,21-j);
	cout<<"|| 4. Parking Maintenance ||";
	gotoxy(44-i,22-j);
	cout<<"||                        ||";
	gotoxy(44-i,23-j);
	cout<<"||       5. Security      ||";
	gotoxy(44-i,24-j);
	cout<<"||                        ||";
	gotoxy(44-i,25-j);
	cout<<"||       6. Settings      ||";
	gotoxy(44-i,26-j);
	cout<<"||                        ||";
	gotoxy(44-i,27-j);
	cout<<"||         7. Exit        ||";
	gotoxy(44-i,28-j);
	cout<<"||                        ||";
	gotoxy(44-i,29-j);
	cout<<"||========================||"<<endl;
	fflush(stdin);
	opt=getch();
	switch(opt){
		case '1': shops();
				break;
		case '2': pvrmenu();
				break;
		case '3': events();
				break;
		case '4': park();
				break;
		case '5': securitymenu();
				break;
		case '6': setting();
				break;
		case '7': exit(0);
		default: mainmenu();
	}
}

void loaddata(){
	ifstream in("setting.bin",ios::binary);
	if(in){
		in.read((char *)&s,sizeof(s));
	}
	else {
		in.close();
		ofstream out("setting.bin",ios::binary);
		out.close();
		
	}
}

void loginscreen(){
	system("cls");
	int check,pass;
	cout<<endl<<endl<<"======================================================================================================================== |                                               Administrator Login                                                  |"<<endl;
	cout<<"========================================================================================================================";
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<"                                         |===================================|";
	cout<<endl<<"                                         |         Enter 4-Digit Pin         |"<<endl;
	cout<<"                                         |===================================|"<<endl;
	int i=0;
	string value;
	char key;
	for(int j=0;j<4;j++){
		gotoxy(57+j,15);
		cout<<"_";
	}
	gotoxy(57,15);
	do{
		key = getch();
		switch (key){
			case '\b':{
				if(value.length() > 0)
			 	{
					value.erase(value.length() - 1, 1);
					std::cout << '\b' << "_" << '\b';
				}
				break;
			}
			default:
				if(key > 31 && key < 127)
				{
					value.push_back(key);
					std::cout << "*";
				}
			}
	} while(value.length()!=4);
	pass=atoi(value.c_str());
	check=s.check(pass);
	if(check==1)
	{
		cout<<endl<<endl<<endl<<endl<<endl<<"                                                 Login Succesfull...";
		sleep(1);
		cout<<endl<<"                                               Press any key to continue.";
		getch();
		mainmenu();
	}
	else 
	{
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                 Login Unsuccesfull..."<<endl;
		cout<<"                                               Please check your credentials."<<endl;
		cout<<"                                               Press any key to try again.";
		getch();
		loginscreen();
	}
}


int main(){
	system("color 0a");
	cout<<endl<<endl<<endl<<endl<<endl<<"                                       Welcome to Shopping Mall Administrator"<<endl<<endl<<"                                                     Loading....";
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                                                         Made By Aman Singh.";
	sleep(4);
	loaddata();
	loginscreen();
	mainmenu();
	getch();
}
