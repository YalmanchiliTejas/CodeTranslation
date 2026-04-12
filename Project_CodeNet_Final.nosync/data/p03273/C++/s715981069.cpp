#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const double PI  =3.141592653589793238463;
long long mod = 1000000007;
int stringToInteger(string x){
    int gg=0;
    stringstream geek(x);
    geek >> gg;
    return gg;
}
ll powmod(ll a,ll b,ll m)
{
    ll ans=1;
    while(b>0){ if(b%2)
        {ans*=a; ans%=m;}
         b/=2; a=a*a; a=a%m;
        }
        return ans%m;
}
ll gcd(ll a,ll b)
{

    return __gcd(a,b);
}
ll mulmod(ll a,ll b,ll m)
{  ll ans=0;
    a %=m;
    while (b>0)
    {       if(b&1) ans = (ans + a) % m;
        a = (a * 2)%m;
        b /= 2;
    }
    return ans % m;
}
bool prime[1000000];
void seive()
{  memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=1000000;i++)
    {
         if(prime[i]==true) {
        for(int j=2*i;j<=(1000000);j+=i)
           { prime[j]=false;}

    }
    }

}

int main()
{
   int n,m;
   cin>>n>>m;
   vector<string>c(n);
   int flag1=0,flag2=0;
   for(int i=0;i<n;i++)
   {
    //   string s;
       cin>>c[i];

   }
   while(1)
   { //cout<<"Da";
       vector<int>v;
   int f=0;
   //cout<<c.size()<<" "<<c[0].size();
   for(int i=0;i<c.size();i++)
   {  f=0;
         for(int j=0;j<c[0].size();j++)
       {
           if(c[i][j]!='.') { f= 1; break;}

       }
       if(f==0)
       {
           v.push_back(i);
       }
   }
   if(v.empty()) flag1=1;
   vector<string>temp;
   for(int i=0;i<v.size();i++)
   {
       c[v[i]]="lol";

   }
   for(int i=0;i<c.size();i++)
   {
       if(c[i]=="lol") continue;
       else temp.push_back(c[i]);
   }
    c=temp;
    //cout<<endl;
     //for(int i=0;i<c.size();i++) cout<<c[i]<<endl;
    f=0;
    v.clear();
    for(int j=0;j<c[0].size();j++)
    { f=0;
        for(int i=0;i<c.size();i++)
        {

            if(c[i][j]!='.') { f=1; break;}
        }
        if(f==0) {v.push_back(j); }

    }

    if(v.empty()) flag2=1;
    if(flag1&&flag2) break;
    int s = c[0].size();
    for(int i=0;i<c.size();i++)
    {

        for(int j=0;j<v.size();j++)
            c[i][v[j]]='b';
        string output="";
        for(int j=0;j<s;j++)
        {
            if(c[i][j]!='b') output+=c[i][j];
        }
        c[i]=output;

    }
    f=0; v.clear(); flag1=0; flag2=0;
     //cout<<endl;
     //for(int i=0;i<c.size();i++) cout<<c[i]<<endl;
  // cout<<endl;
  
   }
  for(int i=0;i<c.size();i++) cout<<c[i]<<endl;
}

