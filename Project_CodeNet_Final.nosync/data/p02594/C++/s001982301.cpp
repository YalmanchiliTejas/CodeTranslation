#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#define ll long long
ll gcd(ll a,ll b){
    ll s=1,c;
    while(a&&b){
        if((~a&1)&&(~b&1))
            a>>=1,b>>=1,s<<=1;
        else if(~a&1)a>>=1;
        else if(~b&1)b>>=1;
        else if(a>b)a=a-b;
        else c=b-a,b=a,a=c;
    }
    if(!a)return b*s;
    if(!b)return a*s;
}
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else 
		cout<<"No";
	return 0;
}