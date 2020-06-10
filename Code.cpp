//-----------INVENTARY CONTROL ---------
#include<fstream.h>
#include<ctype.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
class chemshop
{	int code,mm,yy,mafm,mafy,units;
	char nm[20];
	float price;
	public:
	void bill();
	void stock();
	void password();
	void display();
	void addstock();
	void del();
	int ret_unit()
	{ return units;}
	char med[10];
	void saledetails();
}c;
void chemshop::password()
{
  char mypwd[10]="Chemist",str[10]=" ";
  char ch;
  int i=0,flag;
  cout<<"\nEnter your password(any case)=";
  while(ch!='\r')
  { ch=getch();
    cout<<'*';
    str[i]=tolower(ch);
    i++;
  }
  str[i-1]='\0';
  flag=strcmpi(mypwd,str);
  if(flag==0)
  cout<<"\nAuthentic";
  else
 { cout<<"\nNot Authentic";
  getch();
  exit(0);}
  getch();
}
void chemshop::stock()
{ ofstream cfile("CHEM.DAT",ios::app);
  for(int i=0;i<5;i++)
  { cout<<"\nEnter name of medicine= ";
    gets(med);
    cout<<"\nEnter code= ";
    cin>>code;
    cout<<"\nEnter price= ";
    cin>>price;
    cout<<"\nEnter Manufacturing date= ";
    cin>>mafm>>mafy;
    cout<<"\nEnter expiry date= ";
    cin>>mm>>yy;
    cout<<"\nEnter no.of units= ";
    cin>>units;
    for(int j=0;j<19;j++)
    cout<<'-';
    cfile.write((char*)&c,sizeof(c));
  }
}
void chemshop::display()
{   ifstream cfile("CHEM.DAT");
    cout<<"\n=============================STOCK INFORMATION=============================\n\n";
     for(int j=0;j<79;j++)
    cout<<'-';
    cout<<'\n'<<setw(10)<<"Medicine"<<setw(10)<<"Code"<<setw(10)<<"Price"<<setw(15)<<"Manu.date"<<setw(14)<<"Exp.date"<<setw(10)<<"Units"<<endl;
    for(j=0;j<79;j++)
    cout<<'-';
    while(cfile.read((char*)&c,sizeof(c)))
    {
    cout<<'\n'<<setw(10)<<med<<setw(10)<<code<<setw(10)<<price<<setw(10)<<mafm<<'/'<<mafy<<setw(10)<<mm<<'/'<<yy<<setw(10)<<units<<endl;
    }
    for(j=0;j<79;j++)
    cout<<'-';
}
void chemshop::bill()
{
remove("bill.dat");
int num[15],p,pos,cd,unt,u,total,sum,found;
  char ch,nm[50];

sum=0;
total=0;

do{
found=0;
fstream cfile("CHEM.DAT",ios::in|ios::out);
ofstream bfile("bill.DAT",ios::app);
ofstream file("temp.dat",ios::out);
b:cout<<"\nEnter code= ";
   cin>>cd;
      cfile.seekg(0,ios::beg);
  cout<<"\nEnter units= ";
   cin>>unt;
    while(cfile.read((char*)&c,sizeof(c)))
    {
      pos=cfile.tellg();
     if(cd==code){
    cout<<"\nMedicine= "<<med;
    cout<<"\nPrice= "<<price;
    cout<<"\nManufacturing date= "<<mafm<<' '<<mafy;
    cout<<"\nExpiry date= "<<mm<<' '<<yy;
    cout<<"\nUnits needed= "<<unt;
    u=units;
    units=unt;
    //sfile.write((char*)&c,sizeof(c));
    p=price;

    if(unt>u)
    { cout<<"\n";
      for(int k=0;k<27;k++)
      cout<<'*';
      cout<<"\nSorry units available is: "<<u;
      cout<<"\n\n";
      for(k=0;k<27;k++)
      cout<<"*";
    goto b;
    }
    else
    {
     bfile.write((char*)&c,sizeof(c));
     units=u-unt;
     cfile.seekg(pos);
     file.write((char*)&c,sizeof(c));
     sum=p*unt; }
    found=1;

    }
    else
     {

      file.write((char*)&c,sizeof(c));

     }


}
total=total+sum;

file.close();
cfile.close();
remove("CHEM.DAT");
rename("temp.dat","CHEM.dat");
 if(found==0)
 cout<<"\n\nCode chosen does not exist.......\n";
 cout<<"\n\n";
 cout<<"Do you want to enter more medicines?(y/n)= ";
     cin>>ch;
	sum=0;
}
while((ch=='Y')||(ch=='y'));

ifstream bfile("bill.DAT");
     cout<<"\n=============================BILL=============================\n\n";
     for(int j=0;j<79;j++)
    cout<<'-';
    cout<<'\n'<<setw(10)<<"Medicine"<<setw(10)<<"Code"<<setw(10)<<"Price"<<setw(15)<<"Manu.date"<<setw(14)<<"Exp.date"<<setw(10)<<"Units"<<setw(10)<<"Amount"<<endl;
    for(j=0;j<79;j++)
    cout<<'-';
    ofstream sfile("sales.dat",ios::binary|ios::app);
    while(bfile.read((char*)&c,sizeof(c)))
    {
    cout<<'\n'<<setw(10)<<med<<setw(10)<<code<<setw(10)<<price<<setw(10)<<mafm<<'/'<<mafy<<setw(10)<<mm<<'/'<<yy<<setw(10)<<units<<setw(10)<<price*units;endl;
    sfile.write((char*)&c,sizeof(c));}
    for(j=0;j<79;j++)
    cout<<'-';
   cout<<"\n\t\tTotal=\t"<<total;



}
void chemshop::addstock()
{  int num[15],p,pos,cd,unt;
  char ch;
  fstream cfile("CHEM.DAT",ios::in|ios::out);
  ofstream file("temp.dat",ios::out);

    do{

       cout<<"\nEnter code= ";
       cin>>cd;
       cfile.seekg(0,ios::beg);
      b: cout<<"\nEnter unit= ";
       cin>>unt;
       while(cfile.read((char*)&c,sizeof(c)))
    {
	pos=cfile.tellg();
	if(cd==code){
	 cout<<"\nPrice= "<<price;
	 cout<<"\nManufacturing date= "<<mafm<<' '<<mafy;
	 cout<<"\nExpiry date= "<<mm<<' '<<yy;
	 cout<<"\nUnits that were left= "<<units;
	 units=unt+units;
	 cfile.seekg(pos);
	 file.write((char*)&c,sizeof(c));
     }
     else
     {
	 file.write((char*)&c,sizeof(c));
     }


}cout<<"\n\n";
cout<<"Do you want to enter more medicines?(y/n)=";
     cin>>ch;

}while((ch=='Y')||(ch=='y'));
file.close();
cfile.close();
remove("CHEM.DAT");
rename("temp.dat","CHEM.dat");
}
void chemshop::saledetails()
{   ifstream sfile("sales.DAT");
    cout<<"\n=============================SALE DETAILS=============================\n\n";
     for(int j=0;j<79;j++)
    cout<<'-';
    cout<<'\n'<<setw(10)<<"Medicine"<<setw(10)<<"Code"<<setw(10)<<"Price"<<setw(15)<<"Manu.date"<<setw(14)<<"Exp.date"<<setw(10)<<"Units"<<setw(10)<<"Amount"<<endl;
    for(j=0;j<79;j++)
    cout<<'-';
    while(sfile.read((char*)&c,sizeof(c)))
    {
    cout<<'\n'<<setw(10)<<med<<setw(10)<<code<<setw(10)<<price<<setw(10)<<mafm<<'/'<<mafy<<setw(10)<<mm<<'/'<<yy<<setw(10)<<units<<setw(10)<<units*price<<endl;
    }
    for(j=0;j<79;j++)
    cout<<'-';
}
void chemshop::del()
{ ifstream cfile("chem.dat",ios::binary);
  ofstream ofile("tem.dat",ios::app|ios::binary);
  char ch;
  while(cfile.read((char*)&c,sizeof(c)))
  { cout<<"\nMedicine= "<<med
	<<"\nCode= "<<code
	<<"\nManufacturing date= "<<mafm<<'/'<<mafy
	<<"\nExpiry date= "<<mm<<'/'<<yy;
  cout<<"\nDo you really want to delete the medicine from stock?= ";
  cin>>ch;
  if((ch=='n')||(ch=='N'))
   ofile.write((char*)&c,sizeof(c));
   else
   cout<<"\n Chosen medicine is deleted...";
   } cfile.close();
     ofile.close();
     remove("chem.dat");
     rename("tem.dat","chem.dat");
}


void main()
{       int ch;
	clrscr();
	for(int j=0;j<80;j++)
	cout<<'-';
	for( j=0;j<80;j++)
	cout<<'-';
	cout<<"\n\t\t\t-----MEDLIFE PHARMACY-----\n";
	for( j=0;j<80;j++)
	cout<<'-';
	for( j=0;j<80;j++)
	cout<<'-';
	for( j=0;j<80;j++)
	cout<<'+';
	for( j=0;j<80;j++)
	cout<<'%';
	for( j=0;j<80;j++)
	cout<<'%';
	cout<<"\n\t\t\tSPECIALISATION IN MEDICAL SUPPLIES\n";
	for( j=0;j<80;j++)
	cout<<'%';
	for( j=0;j<80;j++)
	cout<<'%';
	for( j=0;j<80;j++)
	cout<<'+';
	for( j=0;j<80;j++)
	cout<<'-';
	for( j=0;j<80;j++)
	cout<<'-';
	getch();
	clrscr();
	c.password();

	getch();
	clrscr();
	ifstream cfile("CHEM.dat",ios::binary);
	while(cfile.read((char*)&c,sizeof(c)))
	{ if(c.ret_unit()<=2)
	   { cout<<"\n\n\n Your medicine "<<c.med<<" is going to get over..";
	     cout<<"\n Do you want to refill stock? ";
	     char a;
	     cin>>a;
	     if((a=='y')||(a=='Y'))
	       c.addstock();
	       else
	       break;
	     }
	   }

	do
	{ clrscr();
	  cout<<"\n=============MENU=============="
	      <<"\n1.To add fresh stock."
	      <<"\n2.To make bill."
	      <<"\n3.To display details."
	      <<"\n4.To refill stock."
	      <<"\n5.So  far sale details."
	      <<"\n6.Delete medicine."
	      <<"\n7.To exit.";
	 cout<<"\nEnter your choice= ";
	 cin>>ch;
	 switch(ch)
	 {	case 1:c.stock();
			break;
		case 2:c.bill();
			break;
		case 3:c.display();
			break;
		case 4:c.addstock();
			break;
		case 5:c.saledetails();
			break;
		case 6:c.del();
			break;
		case 7:cout<<"\nGood bye...."
			   <<"\nSee you later.....";
		       getch();
		       break;
		default:cout<<"\nYou have entered WRONG choice!!..";
			break;
	 }
	 getch();
	 } while(ch!=6);

}












