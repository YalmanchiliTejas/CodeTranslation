#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,ab,x,y,sum[4];
    cin>>a>>b>>ab>>x>>y;
    if(x>y)
    {
        sum[0]=ab*x*2;
        sum[1]=ab*y*2+a*(x-y);



    }
    else
    {
        sum[0]=ab*y*2;
        sum[1]=ab*x*2+b*(y-x);



    }
    sum[2]=a*x+b*y;
    sort(sum,sum+3);
    cout<<sum[0];//<<" "<<sum[1]<<" "<<sum[2];
}
