#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <queue>
#include <set>
#define ll long long
#define sf(a) scanf("%lld",&a)
#define pf(b) printf("%lld",b)
#define sp printf(" ")
#define nw printf("\n")
#define mp make_pair
#define pi pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(false)
using namespace std;


int main()
{ 
  ll n,ans=0,sum=0,m=1000000007ll;
  sf(n);
  ll ar[n+1];
  for(ll i=1;i<=n;i++)
  {
   sf(ar[i]);
   ans=(ans+(sum*ar[i])%m)%m;
   sum+=ar[i];
   sum%=m;
  }
  pf(ans);
}

