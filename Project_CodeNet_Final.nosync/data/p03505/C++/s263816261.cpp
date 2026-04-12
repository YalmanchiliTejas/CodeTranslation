#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c;
int main()
{
	scanf("%lld%lld%lld",&a,&b,&c);
	if(b>=a)puts("1");
    else if(c>=b)puts("-1");
    else cout<<((a-b)/(b-c)+((a-b)%(b-c)>=1))*2+1<<endl;
    return 0;
}