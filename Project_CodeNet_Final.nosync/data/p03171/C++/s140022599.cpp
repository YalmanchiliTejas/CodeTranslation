

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
    return x.first>y.first;
}
 
 
bool f3(ll &x,ll &y){
    return x>y; 
    }
vll b;

ll it=0;

// map<array<ll,2>,array<ll,2> >dp;
// array<ll,2> meow(ll l,ll r,ll pl){
//     // it++;
//     // if(it>1000){
//     //     cout<<"infinite";
//     // }
//     if(dp.find({l,r})!=dp.E){
//         return dp[{l,r}];
//     }
//     if(l==r){
//         dp[{l,r}][pl]+=b[l];
//         return dp[{l,r}];
//     }
// array<ll,2>x=meow(l+1,r,(pl+1)%2);
// array<ll,2>y=meow(l,r-1,(pl+1)%2);
// x[pl]+=b[l];
// y[pl]+=b[r];
// if(x[pl]-x[(pl+1)%2]>=y[pl]-y[(pl+1)%2]){
// dp[{l,r}]=x;    return x;
// }
// else {
// dp[{l,r}]=y;
//     return y;}

// }


int main()
{ fastio;
//freopen("test_input (1).txt", "r", stdin); 
//freopen("output.txt", "w", stdout);
ll n;cin>>n;
forl(i,0,n){ll x;cin>>x;b.pb(x);}

//array<ll,2>c=meow(0,n-1,0);
//cout<<c[0]-c[1];
// ll dp[n][n];
// forl(i,0,n){
//     dp[i][i]=b[i];
// }

array<ll,2>dp[n][n];
forl(i,0,n){
    forl(t,0,n){
            dp[i][t]={0,0};
    }
}

for(ll l=n-1;l>=0;l--){
    for(ll r=l;r<n;r++){
        ll pl=r-l+1;
        pl%=2;
if(l==r){
dp[l][r][pl%2]+=b[l];
continue;
    }
array<ll,2>x=dp[l+1][r];
array<ll,2>y=dp[l][r-1];
x[pl]+=b[l];
y[pl]+=b[r];

if(x[pl]-x[(pl+1)%2]>=y[pl]-y[(pl+1)%2]){
dp[l][r]=x;   
}
else {
dp[l][r]=y;
  }

}



}

ll st=n%2;
cout<<dp[0][n-1][st]-dp[0][n-1][(st+1)%2];







return 0;
}

 








