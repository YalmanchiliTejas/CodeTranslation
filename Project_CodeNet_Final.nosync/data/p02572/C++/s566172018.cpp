#include<bits/stdc++.h>
#include <fstream>
using namespace std;
typedef long long ll;
ll a[200003];
int main()
{
  /*  string s,s1;
    cin>>s>>s1;
    int Max=0;
    int len=s.size();
    int len1=s1.size();
    for(int i=0;i<len;i++)
        for(int j=len-i-1;j>=1;j--)
    {  int z=s1.find(s.substr(i,j));
        if(len1>=j&&z!=string::npos)
        {
            if(i>=z&&len-(i+j-1)>=len1-(z+j-1))
            Max=max(Max,j);
        }
    }
    cout<<len1-Max;*/
    int n;cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=a[i];
    }
    ll sum=0;
    for(int i=1;i<=n;i++)
    {  ans-=a[i];
        sum=(sum+ans%1000000007*a[i]%1000000007)%1000000007;
    } cout<<sum;
}
