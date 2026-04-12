#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int n;
// int s[525252];
int seq[252521];

// http://algoogle.hadrori.jp/algorithm/segment-tree.html

struct segtree {
  int N;
  vector<int> datmin, datmax, sum;
  segtree(int n, int *initial) {
    N = 1;
    while(N < n) N <<= 1;
    datmin.assign(2*N-1,0);
    datmax.assign(2*N-1,0);
    REP(i,n) datmin[i+N-1]=datmax[i+N-1]=initial[i];
    REP(_i,N-2){
      int i = N-2-_i;
      int lc = 2*i+1;
      int rc = 2*i+2;
      datmin[i] = min(datmin[lc],datmin[rc]);
      datmax[i] = max(datmax[lc],datmax[rc]);
    }
    sum.assign(2*N-1,0);
  }
  void add(int a, int b, int x) { add(a,b,x,0,0,N); }
  pii add(int a, int b, int x, int k, int l, int r) {
    if(b <= l or r <= a) return make_pair(datmin[k],datmax[k]);
    if(a <= l and r <= b) {
        sum[k] += x;
        return make_pair(datmin[k]+=x, datmax[k]+=x);
    }
    int m = (l+r)/2;
    pii left = add(a,b,x,2*k+1,l,m);
    pii right = add(a,b,x,2*k+2,m,r);
    return make_pair(
      datmin[k] = min(left.first, right.first)+sum[k],
      datmax[k] = max(left.second,right.second)+sum[k]
    );
  }
  int minquery(int a, int b) { return minquery(a,b,0,0,N); }
  int minquery(int a, int b, int k, int l, int r) {
    if(b <= l or r <= a) return 1e9;
    if(a <= l and r <= b) return datmin[k];
    int m = (l+r)/2;
    return min(minquery(a,b,2*k+1,l,m),minquery(a,b,2*k+2,m,r))+sum[k];
  }
  int maxquery(int a, int b) { return maxquery(a,b,0,0,N); }
  int maxquery(int a, int b, int k, int l, int r) {
    if(b <= l or r <= a) return -1e9;
    if(a <= l and r <= b) return datmax[k];
    int m = (l+r)/2;
    return max(maxquery(a,b,2*k+1,l,m),maxquery(a,b,2*k+2,m,r))+sum[k];
  }
  void debug(){
    REP(i,N){
      cout<<minquery(i,i+1)<<" ";
    }
    cout<<endl;
  }
};

int main(){
  scanf("%d",&n);
  int c = n/2;
  REP(i,c){
    int x;
    scanf("%d",&x);
    seq[c-1-i] -= x;
  }
  REP(i,c){
    int x;
    scanf("%d",&x);
    seq[i] += x;
  }
  segtree tr(c,seq);
  int __q;
  scanf("%d",&__q);
  while(__q--){
    int l,r,x;
    scanf("%d%d%d",&l,&r,&x);
    --l;--r;
    l -= c; r -= c;
    if(l<0 && r>=0){
      int a = -l-1;
      int b = r;
      if(a<b){
        l = a+1;
      }else{
        l = b+1;
        r = a;
        x = -x;
      }
    }else if(l<0 && r<0){
      swap(l,r);
      l = -l-1;
      r = -r-1;
      x = -x;
    }
    tr.add(l,r+1,x);
    int mn = tr.minquery(0,c);
    int mx = tr.maxquery(0,c);
    if(mn==0 && mx==0){
      puts("1");
    }else{
      puts("0");
    }
  }
  return 0;
}