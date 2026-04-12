#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N=1<<19;
ll Mi[2222222],Ma[2222222],A[2222222];
class StarrySkyTree{
public:
  void init(){fill(Mi,Mi+2222222,0);fill(Ma,Ma+2222222,0);fill(A,A+2222222,0);}
  void add(int a,int b,int x,int k=0,int l=0,int r=N) {
    if(r<=a||b<=l) return;
    if(a<=l&&r<=b){
      A[k]+=x;
      while(k){
        k=(k-1)/2;
        Mi[k]=min(Mi[k*2+1]+A[k*2+1],Mi[k*2+2]+A[k*2+2]);
        Ma[k]=max(Ma[k*2+1]+A[k*2+1],Ma[k*2+2]+A[k*2+2]);
      }
      return;
    }
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
  ll getMin(int a,int b,int k=0,int l=0,int r=N) {
    if(r<=a||b<=l)return LLONG_MAX;if(a<=l&&r<=b)return Mi[k]+A[k];
    ll left=getMin(a,b,k*2+1,l,(l+r)/2),right=getMin(a,b,k*2+2,(l+r)/2,r);
    return min(left,right)+A[k];
  }
  ll getMax(int a,int b,int k=0,int l=0,int r=N) {
    if(r<=a||b<=l)return -LLONG_MAX;if(a<=l&&r<=b)return Ma[k]+A[k];
    ll left=getMax(a,b,k*2+1,l,(l+r)/2),right=getMax(a,b,k*2+2,(l+r)/2,r);
    return max(left,right)+A[k];
  }
};

int main() {
  int n;
  cin >> n;
  ll a[n];
  for(int i=0; i<n; i++) cin >> a[i];
  StarrySkyTree b;
  b.init();
  for(int i=0; i<n/2; i++) b.add(i,i+1,a[i]-a[n-1-i]);
  int m;
  cin >> m;
  while(m--) {
    int x,y,z;
    cin >> x >> y >> z;
    x--,y--;
    if(y<n/2) b.add(x,y+1,z);
    else if(n/2<=x) {
      x=n-x-1;
      y=n-y-1;
      b.add(y,x+1,-z);
    } else {
      y=n-y-1;
      b.add(x,n/2+1,z);
      b.add(y,n/2+1,-z);
    }
    ll mi=b.getMin(0,n/2+1);
    ll ma=b.getMax(0,n/2+1);
    if(!mi&&!ma) cout << 1 << endl;
    else cout << 0 << endl;
  }
  return 0;
}
