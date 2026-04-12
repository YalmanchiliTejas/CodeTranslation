#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
#define loop(i,a,b) for(int i = a; i < b; i++)
#define rep(i,a) loop(i,0,a)
#define shosu(x) fixed<<setprecision(x)
typedef long long ll;

int main()
{
	
	int h,w;
	cin>>h>>w;
	char a[9][9]={};
	rep(i,h)
		rep(j,w)
			cin>>a[i][j];
	
	int flg=1;
	rep(i,h-1)
		rep(j,w-1)
			if(a[i][j]=='#'&&a[i+1][j]=='#'&&a[i][j+1]=='#')
				flg=0;
	loop(i,1,h)
		loop(j,1,w)
			if(a[i][j]=='#'&&a[i-1][j]=='.'&&a[i][j-1]=='.')
				flg=0;
			
				
	if(flg)
		cout<<"Possible"<<endl;
	else
		cout<<"Impossible"<<endl;
		
	


        return 0;
}
