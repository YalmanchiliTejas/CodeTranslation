#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid ((l+r) >> 1)
#define ll long long
using namespace std;

int main()
{
     char s[10];
     int f1=0,f2=0;
     cin>>s;
     for(int i=0;i<3;i++) 
       {
       	  if(s[i]=='A') f1=1;
       	  if(s[i]=='B') f2=1;
	   }
	 if(f1==1&&f2==1) cout<<"Yes"<<endl;
	   else cout<<"No"<<endl;  
}
