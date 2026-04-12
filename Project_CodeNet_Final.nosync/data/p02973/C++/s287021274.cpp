#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int a[110000];
vector<int> b;
//kより小さい要素のうち最小のもののインデックスを求める
int upper_bound(int k){
  int left=-1,right=b.size();
  while(right-left>1){
    int mid=(right+left)/2;
    if(b[mid]<k) right=mid;
    else left=mid;
  }
  return right;
}

void solve(){
  rep(i,n){
    int ub = upper_bound(a[i]);
    if(ub==b.size()){
      b.push_back(a[i]);
    }
    else{
      b[ub] = a[i];
    }
  }
  cout << (int)b.size() << "\n";
}

int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];
  solve();
  return 0;
}
