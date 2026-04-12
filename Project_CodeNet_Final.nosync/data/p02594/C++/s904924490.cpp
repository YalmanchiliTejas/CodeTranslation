#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <math.h>
#include <bits/stdc++.h>
#include <string>
#define pb          push_back
#define x           first
#define y           second
#define endl        '\n'
#define hell        998244353
#define PI          3.141592653589
#define allfo(s)    for(auto it=(s).begin();it!=(s).end();it++)
#define _init(b)     memset(b,-1,sizeof(b))
#define _init0(b)     memset(b,0,sizeof(b))
#define MOD         1000000007
#define MAX 1e18
#define MIN -1e9
#define ll long long
#define ull unsigned long long
#define ld long double
#define all(x) x.begin(),x.end()
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repb(i, r, l) for (ll i = (r); i > (l); i--)
#define sz(a) (int)a.size()
#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define cl(x) (int)ceil((double)x/2);
#define fl(x) (int)floor((double)x/2);
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
//cout << fixed << setprecision(13) << x;
bool cmp(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second < b.second);
}

bool mod(double a,double b)
{
    return a/b - floor(a/b);
}

int logb(int base, int x)
{
    return (log(x) / log(base));
}

void sortString(string &str)
{
    sort(str.begin(), str.end());
}

int lcm(int a,int b)
{
    return (a*b)/__gcd(a,b);
}

bool find(ll x,ll a[],ll n)
{
    rep(i,0,n)
    if(a[i]==x)
        return true;
    return false;
}

//floor(log10(N)) + 1;
//swap two no.		a ^= b; b ^= a; a ^= b;
// to_string(s)  to convert the string to int
//x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
//x&(-x) : Returns the rightmost 1 in binary representation of x.
//x | (1 << n) : Returns the number x with the nth bit set.
int btd(ll n)
{
    ull num = n,dec_value = 0,base = 1,temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}

bool isPowerOfTwo (int x) { return x && (!(x&(x-1))); }


int main()
{
    FLASH
   ll n;
   cin>>n;
   if(n>=30)
    cout<<"Yes"<<endl;
   else
    cout<<"No";
   return 0;
}
