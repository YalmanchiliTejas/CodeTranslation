#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int

ll max(ll a,ll b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}

ll min(ll a,ll b)
{
    if(a<b)
    {
        return a;
    }
    return b;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a, b);
}



int main() {

ll n,m;
cin>>n>>m;
if(n==m)
{
    cout<<"Yes";
} else{
    cout<<"No";
}
    return 0;
}