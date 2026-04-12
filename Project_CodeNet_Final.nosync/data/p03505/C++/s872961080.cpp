#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,m,k,tian;
int main()
{
    cin>>n>>m>>k;
    if(m>=n)
    {
        cout<<1;
        return 0;
    }
    if(k>=m)
    {
        cout<<-1;
        return 0;
    }
    if((n-m)%(m-k)>=1)
	{
		tian=1;
	}
    cout<<((n-m)/(m-k)+tian)*2+1;
}