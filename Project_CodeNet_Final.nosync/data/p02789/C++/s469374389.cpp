//#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const ll INF=1000000000000005;
const ll maxn=1e6+5;
const int mod=998244353;
ll n,m,p;
ll x,y;
ll in[maxn/100];
int work()
{
    for(int i=1;i<=n;i++) if(in[i]>4||in[i]<=1) return 0;
    int a=0,b=0,c=0;//2 3 4
    for(int i=1;i<=n;i++)
    {
        if(in[i]==4) c++;
        else if(in[i]==3) b++;
        else a++;
    }
    if(a!=4) return 0;
    for(int i=1;i*i<=c;i++)
    {
        if(c%i==0)
        {
            int temp=c/i;
            if((temp+i)*2==b) return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    if(m>=n) printf("Yes\n");
    else printf("No\n");
    return 0;
}
/***
***/
