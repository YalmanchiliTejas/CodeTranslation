#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
typedef long long ll;
const int INF=0x3f3f3f3f;
//const ll INF=1000000000000000000;

//priority_queue<int, vector<int>, greater<int> >p;
int main()
{
    ll n,k;
    ll sum=0;
    scanf("%lld%lld",&n,&k);
    if(k==0)
    {
        printf("%lld\n",n*n);
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=k)continue;
        ll t=i-k;
        sum+=(n/i)*t;
        if((n%i)-k>=0)sum+=(n%i)-k+1;
    }
    printf("%lld\n",sum);
    return 0;
}

