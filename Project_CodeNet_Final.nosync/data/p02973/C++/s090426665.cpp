#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> PPI;
typedef pair<LL, LL> PL;
typedef long long LL;
// LLONG_MIN, INT_MIN
#define xx first
#define yy second

// int seg[810000];
// void build(int id=1, int l=0, int r = n){
//   if(l==r-1){
//     seg[id] = da[l];
//   }
//   int mid = (l+r)/2;
//   build(id*2, l, mid);
//   build(id*2+1,mid, r);
//   s[id] = max(s[id*2],s[id*2+1]);
// }
// void mx(int x, int y, int id=1, int l=0, int r = n){
//   if(x>=r||y<=l) return -1;
//   if(l>=x&&r<=y)return seg[id];
//   int mid = (l+r)/2;
//   return max(mx(x,y,id*2,l,mid),mx(x,y,id*2+1,mid, r));
// }

multiset<int> ms;

int main()
{
  //freopen("input", "r", stdin);
  // freopen("output", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int t;cin>>t;
    auto it = ms.lower_bound(t);
    if(it==ms.begin())
      ms.insert(t);
    else{
      it--;
      ms.erase(it);
      ms.insert(t);
    }
  }
    cout<<ms.size()<<endl;

}
