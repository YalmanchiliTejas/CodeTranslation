#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n,s,t;
  cin>>n>>s>>t;
  cout<<"? "<<s<<' '<<t<<endl;
  int d;
  cin>>d;
  vector<pair<int,int>> v;
  FOR(i,1,n+1) {
    if(i==s || i==t) continue;
    cout<<"? "<<s<<' '<<i<<endl;
    int d1;
    cin>>d1;
    cout<<"? "<<i<<' '<<t<<endl;
    int d2;
    cin>>d2;
    if (d1+d2 == d) {
      v.emplace_back(d1, i);
    }
  }
  sort(ALL(v));
  int m=v.size();
  auto old = v[0];
  vector<int> res;
  res.push_back(s);
  res.push_back(old.second);
  REP(i,m-1) {
    int d1,i1,d2,i2;
    tie(d1,i1) = old;
    tie(d2,i2) = v[i+1];
    cout<<"? "<<i1<<' '<<i2<<endl;
    int d3;
    cin>>d3;
    if (d2 == d1 + d3) {
      res.push_back(i2);
      old = v[i+1];
    }
  }
  res.push_back(t);
  cout<<"!";
  for(int i : res) {
    cout<<' '<<i;
  }
  cout<<endl;
  return 0;
}

