#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long k,a,b,c;
int main()
{
    cin>>k>>a>>b;
    if(a>=k)
    {
        cout<<1<<endl;
        return 0;
    }
    if(b>=a)
    {
        cout<<-1<<endl;
        return 0;
    }
    if((k-a)%(a-b)>=1)
	{
		c=1;
	}
    cout<<((k-a)/(a-b)+c)*2+1<<endl;
    return 0;
}