#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include <string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<bits/stdc++.h>
#include <set>
#define ll   long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f
#define pi 3.1415926535898
using namespace std;
const int N=2e5+10;
const int mod=1e9+7;
ll a,b,sum;
int main()
{
    int n,k;
    cin>>n>>k;
    for(ll i=k+1;i<=n;i++)
    {
        sum+=n/i*(i-k);
        sum+=max(0ll,n%i-k+1);
        if(k==0)
        {
            sum--;
        }
    }
    cout<<sum<<endl;
    return 0;
}
