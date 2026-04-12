
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define F(i,a,b) for(i=a;a<=b;i++)
#define arr(a,n) for( i=0;i<n;i++)cin>>a[i];
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define vi vector<ll>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define s() sort(a,a+n);
#define sr() sort(a,a+n,greater<ll>());
#define v()  sort(v.begin(),v.end());
#define vr() sort(v.begin(),v.end(),greater<ll>());
#define mod 1000000007
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
int main() {
   /* #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
        /* 
        Ofcourse it's Hard.
        It's supposed to be Hard.
        If it's easy everyone would do it.
        HARD IS WHAT MAKES IT GREAT

        YESTERDAY U SAID TOMORROW

        SLOWLY BECOMING THE PERSON I 
        SHOULD HAVE BEEN A LONG TIME AGO

        SAME TASK CAN'T BE FOUND DIFFICULT TWICE

        BTBHWSITW

        SPRH TU KAB P

        CP IS ALL ABOUT THINKING 
        YOU HAVE MUCH MORE POTENTIAL THAN U THINK

        AJIT SHIDDAT 10

        UR DAILY ROUTINE 


        */

fast();
//ll t;cin>>t;while(t--)
{
   ll n;
   cin>>n;
   int a[55][26];
   memset(a,0,sizeof(a));
   /*for(int i=0;i<n;i++)
   {
    for(int j=0;j<26;j++)
    {
      cout<<a[i][j];
    }
    cout<<endl;
   }*/
   
   for(int i=0;i<n;i++)
   {
     string s;
     cin>>s;
     for(int j=0;j<s.length();j++)
     {
      a[i][s[j]-'a']++;
     }
   }
  /*for(int i=0;i<n;i++)
   {
    for(int j=0;j<26;j++)
    {
      cerr<<a[i][j];
    }
    cerr<<endl;
   }*/
   /*for(int i=0;i<26;i++)
   {
    if(a[i]>=n)
    {
      int rep=a[i]/n;
      for(int p=0;p<rep;p++)
      {
          char temp='a'+i;
          cout<<temp;
    }
    }
   }*/

   for(int j=0;j<26;j++)
   {
    int temp=INT_MAX;
    for(int i=0;i<n;i++)
    {
      temp=min(temp,a[i][j]);
    }
    for(int p=0;p<temp;p++)
    {
      char cc='a'+j;
      cout<<cc;
    }
    //cerr<<endl;
   }
   cout<<endl;
   

}
return 0;
}