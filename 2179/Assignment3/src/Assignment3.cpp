//============================================================================
// Name        : Assignment3.cpp
// Author      : Divyajyoti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class term
{
	friend class sparse;
private:
	int r,c,v;
};
class sparse{
	term a[10];
	int n;
	int tr,tc,tv;
	public:
	void input();
	void display();
	void transpose(sparse);
	void add(sparse,sparse);
};
void sparse::input()
{
	cout<<"enter total no. of rows,cols,non zero values";
	cin>>tr>>tc>>tv;
	a[0].r=tr;
	a[0].c=tc;
	a[0].v=tv;
	cout<<"enter row, col, value for each term";
	for(int i=1;i<=tv;i++)
	{
		cin>>a[i].r;
		cin>>a[i].c;
		cin>>a[i].v;
	}
}
void sparse::display()
{
	for(int i=1;i<=tv;i++)
	{
		cout<<a[i].r<<"\t";
		cout<<a[i].c<<"\t";
		cout<<a[i].v<<"\n";
	}
}
void sparse::transpose(sparse p)
{
	int i,j,col,ter,m;
	int rt[10];
	int sp[10];
	col=p.a[0].c;
	ter=p.a[0].v;
	a[0].r=p.a[0].c;
	a[0].c=p.a[0].r;
	a[0].v=p.a[0].v;
	tv=a[0].v;
	if(ter>0)
	{
		for(i=0;i<col;i++)
		rt[i]=0;
		for(i=1;i<ter+1;i++)
			rt[p.a[i].c]++;
		sp[0]=1;
		for(i=1;i<col+1;i++)
				sp[i]=sp[i-1]+rt[i-1];
		for(i=1;i<=ter;i++)
		{
			j=sp[p.a[i].c]++;
			a[j].r=p.a[i].c;
			a[j].c=p.a[i].r;
			a[j].v=p.a[i].v;
		}
	}
}
void sparse::add(sparse p,sparse t)
{
	int t1,t2;
	int k1=1,k2=1,k3=1;
	if(p.a[0].r!=t.a[0].r||p.a[0].c!=t.a[0].c)
		cout<<"invalid matrix size";
	else
	{
		t1=p.a[0].v;
		t2=t.a[0].v;
		while(k1<=t1&&k2<=t2)
		{
			if(p.a[k1].r<t.a[k2].r)
			{
				a[k3].r=p.a[k1].r;
				a[k3].c=p.a[k1].c;
				a[k3].v=p.a[k1].v;
				k3++;k1++;
			}
			else if(p.a[k1].r>t.a[k2].r)
			{
				a[k3].r=t.a[k1].r;
				a[k3].c=t.a[k1].c;
				a[k3].v=t.a[k1].v;
				k3++;k2++;
			}
			else if(p.a[k1].r==t.a[k2].r)
			{
				if(p.a[k1].c<t.a[k2].c)
				{
					a[k3].r=p.a[k1].r;
					a[k3].c=p.a[k1].c;
					a[k3].v=p.a[k1].v;
					k3++;k1++;
				}
				else if(p.a[k1].c>t.a[k2].c)
				{
					a[k3].r=t.a[k2].r;
					a[k3].c=t.a[k2].c;
					a[k3].v=t.a[k2].v;
					k3++;k2++;
				}
				else
				{
					a[k3].r=t.a[k2].r;
					a[k3].c=t.a[k2].c;
					a[k3].v=p.a[k1].v+t.a[k2].v;
					k1++;k3++;k2++;
				}
			}

		}
		if(k2>t2)
		{
			for(;k1<=t1+1;k1++)
				{
						a[k3].r=p.a[k1].r;
					    a[k3].c=p.a[k1].c;
						a[k3].v=p.a[k1].v;
						k3++;k1++;
				}
						a[0].r=p.a[0].r;
						a[0].c=p.a[0].c;
						a[0].v=k3;
						tv=k3-1;
					}
		else if(k1<t1)
					{
			for(;k2<=t2+1;k2++)
				{
						a[k3].r=t.a[k2].r;
						a[k3].c=t.a[k2].c;
						a[k3].v=t.a[k2].v;
						k3++;k2++;
				}
						a[0].r=t.a[0].r;
						a[0].c=t.a[0].c;
						a[0].v=k3;
						tv=k3-1;
					}

	}
}
int main() {
	sparse p,q,s,t;
	cout<<"first matrix";
	p.input();
	cout<<"entered matrix is\n\n";
	p.display();
	q.transpose(p);
	cout<<"transpose matrix is\n\n";
	q.display();
	cout<<"second matrix\n\n";
	t.input();
	cout<<"second matrix is\n\n";
	t.display();
	cout<<"addition of matrices is\n\n";
	s.add(p,t);
	s.display();
	return 0;
}

