#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main() {
  int n;
  cin>>n;
  int a[100005],b[100005];
  rep(i,n) cin>>a[i];
  int l=100000,r=100001;
  b[l]=a[0];
  for (int i=1; i<n; i++) {
    int x=lower_bound(b+l,b+r,a[i])-b;
    if (x==l) l--;
    b[x-1]=a[i];
  }
  cout<<r-l<<endl;
  return 0;
}