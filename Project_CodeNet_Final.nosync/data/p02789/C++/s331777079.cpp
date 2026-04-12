#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define double long double
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> iP;
typedef pair<P,int> Pi;
typedef pair<P,P> PP;
double eps=1e-8;
int mod=1e9+7;
int inf=1LL<<55;

priority_queue<P,vector<P>,greater<P> > pq;

template <typename T>
int Count(const vector<T> &v, T l,T r){
  //counting [l,r]
  auto L = lower_bound(v.begin(), v.end(), l );
  auto R = upper_bound(v.begin(), v.end(), r );
  // [l,r) change upper -> lower
  return R-L;
}

signed main(){
  int a,b;
  cin>>a>>b;
  cout<<((a==b)?"Yes":"No")<<endl;
  return 0;
}
