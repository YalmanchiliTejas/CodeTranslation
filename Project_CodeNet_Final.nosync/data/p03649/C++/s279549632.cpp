#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#define ll long long
#define rep(i,a,b) for(ll i = a;i < b;i++)
#define N 55

using namespace std;

ll n,s,ar[N];

bool check(ll k)
{
    ll cur = 0;

    rep(i,0,n)
        cur = cur+(ar[i]+k+1)/(n+1);

    return (cur==k);
}

int main()
{
    cin >> n;

    rep(i,0,n)
    {
        cin >> ar[i];
        s+=ar[i];
    }

    for(ll test = max((ll)0,s-n*n);test <= s;test++)
    {
        if(check(test))
        {
            cout << test;
            return 0;
        }
    }

    return 0;
}

