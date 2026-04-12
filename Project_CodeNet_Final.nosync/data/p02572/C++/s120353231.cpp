#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
int main()
{
    IOS;
    long long a,b,c,d,e,h,l,n,t,f,m,x,y,z,f1=0,flag=0,flag1=0,co=0,co1=0,co2=0,sum=0,sum1=0,ma=0,ma1=0,mi=1000000000000000001;
    long long g,co3=0,co4=0,co5=0,co6=0,co7=0,co8=0,mul=1,sum2=0,sum3=0,mu=1,mu1=1;
    double pi=2 * acos (0.0), dou;
    char ch,ch1,ch2;
    string str,str1,str2;
    cin>>n;
    m=1000000000+7;
    vector<long long>v(n),v1(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        v1[i]=v[i];
    }
    reverse(v1.begin(),v1.end());
    for(int i=1; i<n; i++)
    {
        v1[i]+=v1[i-1];
    }
    reverse(v1.begin(),v1.end());
    for(int i=0; i<n-1; i++)
    {
        sum=sum+((v[i]*(v1[i+1]%m))%m);
        sum=sum%m;
    }
    cout<<sum%m<<endl;
    return 0;
}
