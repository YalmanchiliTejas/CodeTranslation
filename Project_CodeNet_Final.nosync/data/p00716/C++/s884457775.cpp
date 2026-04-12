#include<stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int hukuri(double r , int a,int n ,int t){
	 int i;
	for(i = 0;i < n;i++){
		int s=0;
		s = s + floor(r*a);
		a = a + s - t;
	}
	return a ;
}

int tanri(double r,int a, int n,int t)
	{
		int s = 0; int i;
		for(i = 0; i < n;i++)
					{ s = s + (int)(r*a);
					a-=t;
					}
		return a+s;
	}
		
	
int main(void)
{ 
	//int m ,a ,n;
	int set;
	cin >> set;
	for(int i=0;i<set;i++){
		int money,year;
		cin >> money >> year;
		int nowmax=0;
		int dn;
		cin >> dn;
		for(int k=0;k<dn;k++){
			int which;
			double m;
			int t;
			cin >> which >> m >> t;
			int ret ;
			if(which){
				 ret=hukuri(m,money,year,t);
			}else{
				ret=tanri(m,money,year,t);
			}
			nowmax=max(nowmax,ret);
		}
		cout << nowmax << endl;
	
	}
}			