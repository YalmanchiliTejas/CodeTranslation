#include <bits/stdc++.h>
using namespace std;

long n,m,ans=0;
vector<long> a(100),b(100);
set<long> ab;

void zts(vector<long> x,long y) {
  if(x.size()==n) {
    bool a=true;
    for(long i=0;i<n-1;i++) {
      if(!(ab.count(x[i]*100+x[i+1]))) a=false;
    }
    if(a)ans++;
    return;
  }
  for(long i=0;i<n;i++) {
    if(!((1<<i)&y)) {
      vector<long> xx=x;
      xx.push_back(i);
      zts(xx,y+(1<<i));
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  for(long i=0;i<m;i++) {
    cin >> a[i] >> b[i];
    ab.insert((a[i]-1)*100+(b[i]-1));
    ab.insert((b[i]-1)*100+(a[i]-1));
  }
  zts({0},1);
  
  cout << ans << endl;
}