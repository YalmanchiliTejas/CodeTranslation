#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <random>
#include <math.h>
#include <stdio.h>
 
using namespace std;
 
#define ll long long
#define rep(i, n) for(ll i = 0; i < (n); i++)
ll MOD = 1e9 + 7;
int INF = 1 << 30;
ll INFL = 1LL << 60;
ll MODP = 998244353;

long long moduloMultiplication(long long a, 
                            long long b, 
                            long long c) 
{ 
    ll res=0;
   res = ( ( a % c ) * ( b % c ) ) % c;
  
    return res; 
} 
int main()
{
    ll sum=0,n,sum1=0;
    cin>>n;
    vector <int> v;
    rep(i,n)
    {
        int x;
        cin>>x;
        v.push_back(x);
        sum1+=x;
    }
    // cout<<sum1<<endl;
    for(ll i = 0; i < (n-1); i++)
    {
        sum1 = (sum1-v[i]);
         sum += moduloMultiplication(v[i],sum1,MOD);
        //  cout<<sum<<endl;
    }
    cout<<sum%MOD<<endl;


}