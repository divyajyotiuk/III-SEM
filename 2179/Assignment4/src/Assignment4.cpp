#include<iostream>
#include<string.h>
using namespace std;

struct node
{
int prn;
string name;
char dsign;
node *next;
};

class linklist
{
node *s,*l;
public:
linklist()
{
s=NULL;
l=NULL;
}
node* start()
{
	return s;
}
void insertP();
void insertS();
void insertM();
void AddDel();
void count();
void reverse(node *c)
	{
		if (c==NULL)
		{
			return;
		}
		reverse(c->next);
		cout<<c->dsign<<" "<<c->prn<<" "<<c->name<<"==>";
	}
void catenate(linklist);
void sort();
void display();
};

void linklist :: insertP()
{
node *new1=NULL;
if(s==NULL)
{
new1=new node;
s=new1;
new1->dsign='P';
cout<<"P: Enter PRN";
cin>>new1->prn;
cout<<"Enter Name";
cin>>new1->name;
new1->next=NULL;
}
}
void linklist :: insertS()
{
node *end=NULL;
if(s->next==NULL)
{
end=new node;
l=end;
end->dsign='S';
cout<<"S: Enter PRN";
cin>>end->prn;
cout<<"Enter Name";
cin>>end->name;
end->next=NULL;
s->next=l;
}
}
void linklist :: insertM()
{
node *new2=NULL;
new2=new node;
new2->dsign='M';
cout<<"M: Enter PRN";
cin>>new2->prn;
cout<<"Enter Name";
cin>>new2->name;
if (s->next==l)
{
s->next=new2;
new2->next=l;
}
else
{
new2->next=s->next;
s->next=new2;
}
}
void linklist::AddDel()
	{
	int x,loc;
		do
		{
		cout<<"\n Enter choice";
		cout<<"1. Add member \n";
		cout<<"2. Delete member \n";
		cout<<"3. Exit \n";
		cin>>x;
		switch(x)
		{
		case 1:
			{
			node *new3=NULL;
			new3=new node;
			cout<<"Enter designation";
			cin>>new3->dsign;
			cout<<"Enter PRN";
			cin>>new3->prn;
			cout<<"Enter Name";
			cin>>new3->name;
			if(s->next!=NULL)
			{
			new3->next=s->next;
			s->next=new3;
			}
			}
		break;
		case 2:
			{
			}cout<<"Enter location";
			cin>>loc;
			node *c=NULL, *p=NULL; c=s;
			if(s==NULL)
			cout<<"Underflow";
			else if(loc==1)
			{
			s=s->next;
			c->next=NULL;
			delete(c);
			}
			else
			{
			for (int i=1;i<=loc-1;i++)
			{
			p=c;
			c=c->next;
			}
			p->next=c->next;
			c->next=NULL;
			delete(c);
			}
			break;
		    }
		}while(x!=3);
	}

void linklist :: count()
{
int count=0;
node *c=NULL;
c=s;
while(c!=NULL)
{
count++;
c=c->next;
}
cout<<"Count is: "<<count<<endl;
}

void linklist :: catenate(linklist n1)
{
	node *X=NULL,*Y=NULL;
	X=s;
	Y=n1.s;
	while(X->next!=NULL)
	{
	X=X->next;
	}
	X->next=Y;
}
void linklist::sort()
{
node *cs=NULL;
string tempname;
char tempdsign;
int counter = 0,temPRN;
cs=s;
while (cs!=NULL)
{
	cs = cs->next;
	counter++;
}
cout<<counter<<endl;
cs=s;
for (int i=0; i<counter; i++)
	{
	while (cs->next!=NULL)
		//for (int j=0; j<counter-i; j++)
			{
				if (cs->prn > cs->next->prn)
				{
					/*tempdsign = cs->dsign;
					cs->dsign = cs->next->dsign;
					cs->next->dsign = tempdsign;*/

					temPRN = cs->prn;
					cs->prn = cs->next->prn;
					cs->next->prn = temPRN;

					tempname = cs->name;
					cs->name = cs->next->name;
					cs->next->name = tempname;
				}
				else
					cs=cs->next;
		}
	cs=s;
}
s->dsign='P';
l->dsign='S';
/*while(cs->next!=NULL)
{

}*/
node *c=NULL;
c=s;
while(c!=NULL)
{
cout<<c->dsign<<" "<<c->prn<<" "<<c->name<<"==>";
c=c->next;
}
cout<<endl;
}
void linklist :: display()
{
node *c=NULL;
c=s;
while(c!=NULL)
{
cout<<c->dsign<<" "<<c->prn<<" "<<c->name<<"==>";
c=c->next;
}
cout<<endl;
}
int main()
{
int x;
linklist sl,dl,ssl;
cout<<"Division 1: Enter Choice: First enter President and Secretary details \n";
cout<<"1.Enter president details \n";
cout<<"2.Enter secretary details \n";
cout<<"3.Enter member details \n";
cout<<"4.Add or delete a member\n";
cout<<"5.To get count \n";
cout<<"6.To reverse list \n";
cout<<"7.Exit \n";
do
{
cin>>x;
switch(x)
{
case 1: sl.insertP();
break;
case 2: sl.insertS();
break;
case 3: sl.insertM();
break;
case 4: sl.AddDel();
break;
case 5: sl.count();
break;
case 6: sl.reverse(sl.start());
break;
}
}while(x!=7);
sl.display();

cout<<"\n Division 2: Enter Choice: First enter President and Secretary details \n";
cout<<"1.Enter president details \n";
cout<<"2.Enter secretary details \n";
cout<<"3.Enter member details \n";
cout<<"4.Add or delete a member\n";
cout<<"5.To get count \n";
cout<<"6.Exit \n";
do
{
cin>>x;
switch(x)
{
case 1: dl.insertP();
break;
case 2: dl.insertS();
break;
case 3: dl.insertM();
break;
case 4: dl.AddDel();
break;
case 5: dl.count();
break;
case 6: dl.reverse(dl.start());
break;
}
}while(x!=7);

dl.display();
cout<<"Concatenated list: \n";
    sl.catenate(dl);
    sl.display();
cout<<"Sorted List"<<endl;
   sl.sort();


return 0;
}
