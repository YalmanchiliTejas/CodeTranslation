#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c;
    if(a<=b)
    {
    cout<<1<<endl;
    return 0;
    }
    if(b<=c)
    {
    cout<<-1;
    return 0;
	}
	if((a-b)%(b-c)>=1)
	{
    d=1;
    }
    else
    d=0;
    ans=((a-b)/(b-c)+d)*2+1;
	cout<<ans<<endl;
	return 0;
}