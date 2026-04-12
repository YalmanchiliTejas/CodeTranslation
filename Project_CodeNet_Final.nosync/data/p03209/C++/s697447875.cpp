#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <bitset>
#include <numeric>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <numeric>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll mod=1000000007ll;
const ll inf=1000000000000000ll;

const ll MAX_N=50;
ll N,X,height[MAX_N+5],p_num[MAX_N+5];

ll solve(ll n,ll x){
  ll res;
  if(x==1&&n==0)res=1;
  else if(n==0)res=0;
  else if(x==1)res=0;
  else if(2<=x&&x<=1+height[n-1])res=solve(n-1,x-1);
  else if(x==2+height[n-1])res=p_num[n-1]+1;
  else if(3+height[n-1]<=x&&x<=2+2*height[n-1]) res=solve(n-1,x-(2+height[n-1]))+p_num[n-1]+1;
  else if(x==height[n]) res=p_num[n];
  return res;
}

int main(){
  cin>>N>>X;
  height[0]=1;
  p_num[0]=1;
  for(ll i=0;i<=N;i++){
    height[i+1]=2*height[i]+3;
    p_num[i+1]=2*p_num[i]+1;
  }

  ll ans=solve(N,X);
  cout<<ans<<endl;
  return 0;
}
