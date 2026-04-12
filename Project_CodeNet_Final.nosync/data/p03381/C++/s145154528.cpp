//#include    <bits/stdc++.h>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <iterator>
#include <complex>
#define N  1001000
#define mem(a,b) memset(a,b,sizeof(a))
#define IOS ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f
template<typename T> inline T max(T a,T b,T c){
    return max(a,max(b,c));
}
template<typename T> inline T min(T a,T b,T c){
    return min(a,min(b,c));
}
template<typename T> inline T max(T a,T b,T c,T d){
    return max(a,max(b,c,d));
}
template<typename T> inline T min(T a,T b,T c,T d){
    return min(a,min(b,c,d));
}
const int  dx[]={0,1,0,-1,0,1,-1,1,-1};
const int  dy[]={0,0,1,0,-1,1,-1,-1,1};
typedef long long ll;
using namespace std;
using namespace std;
/*
ll a[N];
ll C(ll n,ll m){
  if (m<n-m) m=n-m;
  ll ans=1;
  for (int i=m+1;i<=n;i++) ans*=i;
  for (int i=1;i<=n-m;i++) ans/=i;
  return ans;
}
int main(){
   ll n,maxn=0;
   scanf("%lld",&n);
   for (int i=1;i<=n;i++)
   {
       scanf("%lld",&a[i]);
       maxn=max(maxn,a[i]);
   }
   ll mid=maxn/2,x=n-mid;
   sort(a+1,a+1+n);
   for (int i=1;i<=n;i++){
      if (a[i]>=mid){
        pos1=a[i];
      }
   }
  printf("%lld %lld\n",maxn,temp);
}
/**/
ll a[N],b[N], n;
int main(){
  scanf("%lld",&n);
  for (int i=1;i<=n;i++)
  {
       scanf("%lld",&a[i]);
       b[i]=a[i];
  }
  sort(b+1,b+1+n);
  ll w=b[n/2],v=b[n/2+1];
  for (int i=1;i<=n;i++){
    if (a[i]<=w) printf("%lld\n",v);
    else printf("%lld\n",w);
  }

   return 0;
}
