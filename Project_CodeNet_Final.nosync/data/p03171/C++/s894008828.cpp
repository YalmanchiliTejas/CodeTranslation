#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>
#include<queue>
#include<list>
#include<vector>
#include<bitset> 
#include<unordered_map> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include "boost/algorithm/string.hpp"
// RAJJI KI MEHER 
#define fio ios_base::sync_with_stdio(false)
//#define mod 1000000007
#define mod1 mod
#define mod2 100000009
#define li long long int
#define ll int
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define readi(x) scanf("%d",&x)
#define  reads(x)  scanf("%s", x)
#define readl(x) scanf("%lld",&x)
#define rep(i,n) for(i=0;i<n;i++)
#define revp(i,n) for(i=(n-1);i>=0;i--)
#define myrep1(i,a,b) for(i=a;i<=b;i++)
#define myrep2(i,a,b) for(i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
#define MAXN 100000000000000005
#define MINN -10000000000000000
#define INTMAX 1000001000
#define pii pair<li,li>
#define pdd pair<double,double>
#define pic pair<int,char>
//#define N 5005
#define lgn 20
#define ddouble long double
#define minus minu
#define PI 3.1415926535
#define lgn 20
using namespace std;
vector<li>a(3005);li n,n1=0,n2=0,n3=0,k;
li AA[3005][3005][2];
li ff(li i1,li i2,li i3){
    if(i2==i1) {if(i3==0) return(a[i1]);
    else return((-1)*a[i1]);}
    //if(i==0) return(0);
    if(AA[i1][i2][i3]!=-1) return(AA[i1][i2][i3]);    
    li ans;
if(i3==0){ans=max(a[i1]+ff(i1+1,i2,1),a[i2]+ff(i1,i2-1,1));}
else{ans=min(ff(i1+1,i2,0)-a[i1],ff(i1,i2-1,0)-a[i2]);}
AA[i1][i2][i3]=ans;return(ans);
}
int main(){readl(n);memset(AA,-1,sizeof(AA));li i;
for(i=0;i<n;i++) {cin>>a[i];}
li ans=ff(0,n-1,0);
cout<<ans;
}
