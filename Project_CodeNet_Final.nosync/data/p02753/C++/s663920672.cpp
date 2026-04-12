#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<math.h>
#include<map>
typedef long long int ll;
using namespace std;
#define maxn 0x3f3f3f3f
const int mm=1e6;
ll d[mm];
ll dd[mm];
map<string,ll>name; 
int main()
{
	ll n,i,j,m,t,a,b,c;
	string s;
	cin>>s;
	ll k=0,kk=0;
	for(i=0;i<3;i++)
	{
		if(s[i]=='A')
		k++;
		else
		kk++;
	}
	if(k==0||kk==0)
	printf("No\n");
	else
	printf("Yes\n");
	
	
	
    
}
