#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int j,n,m,po,no,flag,cnt=0,cnt2,ar[200001],x,y,i,co[200001],sum=0,k,ans=INT_MIN,sum1=0;
    string str[1000],ptr,sr,tr,rtr,rt;
    vector<long long int>v1,v2;
    set<string>s;
    queue<long long int>qu;
    set<string>::iterator it;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>ar[i];

    }
    co[0]=0;
    co[1]=0;
    x=ar[1];
   for(i=2;i<=n;i++)
   {
       if(i%2==0)
        co[i]=max((co[i-2]+ar[i]),x);
        else
       {
           co[i]=max((co[i-2]+ar[i]),co[i-1]);
           x+=ar[i];
       }
   }



    cout<<co[n]<<endl;



}
