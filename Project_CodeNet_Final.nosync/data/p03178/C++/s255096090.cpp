#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <list> 
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<set>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define forl(i,a,n) for(int i=a;i<n;i++)
#define rfor(i,n,a) for(int i=n;i>=a;i--)
#define ll long long
#define ld long double
#define pb push_back
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pi pair<int,int>
#define pll pair<long long,long long>
#define mp make_pair
#define B begin()
#define E end()
#define S size()
#define m9 1000000007
using namespace std;
 
 
 
/*
string fs(string str1, string str2)
{    if (str1.length() > str2.length())
        swap(str1, str2);
      string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
      int carry = 0;
      for (int i=n1-1; i>=0; i--)
    {
 
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
      if (carry)
        str.push_back(carry+'0');
      reverse(str.begin(), str.end());
 
    return str;
}*/
 
ll gcd(ll x,ll y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
/*
ll gcdextended(ll a, ll b, ll *x, ll *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; 
    int gcd = gcdextended(b%a, a, &x1, &y1); 
   
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
}
 
 
///RELATIVE COPRIME
ll modinverse(ll a, ll m) 
{ 
    ll x, y; 
   ll g = gcdextended(a, m, &x, &y); 
    if (g != 1) 
return -1;
    else
    { 
        ll res = (x%m + m) % m; 
        return res;  
    } 
} 
  */
ll powmod(ll x, ll y, ll m) 
{ 
    if (y == 0) 
        return 1; 
    ll p = powmod(x, y/2, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
} 
///M IS PRIME
ll modif(ll x,ll m){
return(powmod(x,m-2,m));
 
}
 

 
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl
#define pin(a) for(auto x:a)cout<<x<<" ";cout<<endl
#define fck(a) cout<<a;exit(0)
#define vvll vector<vector<ll> >
#define A(b) b.begin(),b.end()
#define vpi std::vector<pll>
ll mxn=1e6;
#include <array>
//include<bits/stdc++.h>


bool fa(vll &x,vll &y){return x[0]<y[0];}
bool fa1(vll &x,vll &y){return x[1]<y[1];}
bool f1(pll &x,pll &y){return x.second>y.second;}
bool f2(pll &x,pll &y){
    return x.first<y.first;
}
 
 
bool f3(ll &x,ll &y){
    return abs(x)>abs(y); 
    }

// void meow(string f){
//  it++;
//  //if(it>100)exit(0);
//  cout<<f<<"\n";
//  //cout<<f.S;
//  if(f.S==s.S){
//      ll cnt=0;
//      ll h=0;
//      forl(i,0,f.S){
//          cnt+=f[i]-48;
//          if(f[i]>48)h++;
//      }
//      if(cnt%d==0&&h){
//          ans++;
//          cout<<f<<" ";
//      }
//      return;
//  }
// ll ch=0;
// forl(i,0,f.S){
//  if(f[i]<s[i]){ch++;break;}
// }
// if(ch==0){
//  //cout<<"meow";
//  ll x=s[f.S]-48;
//  //cout<<x;
//  for(ll i=0;i<=x;i++){
//      string temp=f;
//      temp+=(i+48);
//  //  cout<<"temp= "<<temp<<"\n";
//      // p1(temp);
//      meow(temp);
//  }

// }

// else {
//  //cout<<"moew";
//      for(ll i=0;i<=9;i++){
//      string temp=f;
//      temp+=(i+48);
//      meow(temp);
//  }
// }
// return;

// }



int main()
{ fastio;
//freopen("test_input (1).txt", "r", stdin); 
//freopen("output.txt", "w", stdout);
    string s;
ll d;
ll ans=0;
//9ll it=0;
cin>>s;
cin>>d;
// ll dp[90005][2];



// forl(i,0,90005){
//  forl(t,0,2)dp[i][t]=0;
// }
ll n=s.S;

vector<map<pll,ll> >dp(n+1);
dp[0][mp(0,1)]=1;
//ll ans=0;
forl(i,0,s.S){
ll nex=i+1;nex%=2;
//dp[nex].clear();
ll cur=i%2;
for(auto xx:dp[i]){

    ll x=xx.first.first,y=xx.first.second;
    ll va=xx.second;
    //p3(x,y,va);

    if(y==0){
        for(ll z=0;z<=9;z++){
            ll g=x+z;
            g%=d;
            dp[i+1][mp(g,0ll)]+=va;
            dp[i+1][mp(g,0ll)]%=m9;
        }
    }
    if(y==1){
        ll ma=s[i]-48;
        for(ll z=0;z<ma;z++){
            ll g=x+z;
            g%=d;
            dp[i+1][mp(g,0ll)]+=va;
            dp[i+1][mp(g,0ll)]%=m9;
        }
        ll g=x+ma;
        g%=d;
        dp[i+1][mp(g,1ll)]+=va;
        dp[i+1][mp(g,1ll)]%=m9;
    }

}
//cout<<"\n";


}
ll dd=s.S;
dd%=2;
// dp[n][mp(0,1)]=0;
// dp[n][mp(0,0)]=0;
for(auto xx:dp[n]){

    ll x=xx.first.first,y=xx.first.second;
    ll va=xx.second;
    //p3(x,y,va);

    if(x%d==0){
        ans+=va;
        ans%=m9;
    }   
}
    

//meow("");
ans--;
ans+=m9;
ans%=m9;
//ans=max(ans,0ll);

cout<<ans;


return 0;
}



 

 


 



 


 


