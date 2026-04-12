#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef vector<int> vi;

const int INF = 1e9;

//Segment Tree
class SegmentTree{
public:
  int n;
  vi node;
  vi ofset;
  SegmentTree(vi a){
    int n_ = a.size();
    n=1;
    while(n<n_)n*=2;

    node = vi(2*n-1, INF);
    for(int i=0;i<n_;i++)node[i+n-1] = a[i];
    for(int i=n-2;i>=0;i--)node[i] = min(node[2*i+1], node[2*i+2]);

    ofset = vi(2*n-1,0);
  }

  //return minimum value in [a,b). ( [l,r) is interval in which k is.)
  int rmq(int a,int b,int k=0,int l=0,int r=0){
    if(l>=r)r = n;
    if(r<=a || b<=l)return INF;
    if(a<=l && r<=b)return node[k]+ofset[k];
    int pl = rmq(a,b,2*k+1,l,(l+r)/2);
    int pr = rmq(a,b,2*k+2,(l+r)/2,r);
    return min(pl,pr) + ofset[k];
  }

  int search(int a,int b,int v,int k=0,int l=0,int r=0){
    if(l>=r)r = n;
    if(r<=a || b<=l)return INF;
    if(a<=l && r<=b && node[k]+ofset[k] >= v)return l;
    if(r-l<=1)return INF;
    int vr = rmq(a,b,2*k+2,(l+r)/2,r);
    if(vr + ofset[k] >= v){
      int res = search(a,b,v-ofset[k],2*k+1,l,(l+r)/2);
      return min(res, (l+r)/2);
    }else{
      int res = search(a,b,v-ofset[k],2*k+2,(l+r)/2,r);
      return res;
    }
  }
 
  int update_range(int a,int b,int v,int k=0,int l=0,int r=0){
    if(l>=r)r = n;
    if(r<=a || b<=l)return node[k];
    if(a<=l && r<=b){
      ofset[k] += v;
      return node[k]+ofset[k];
    }

    int vl = update_range(a,b,v,2*k+1,l,(l+r)/2);
    int vr = update_range(a,b,v,2*k+2,(l+r)/2,r);
    node[k] = min(vl,vr);
    return node[k]+ofset[k];
  }
};

int main(){
  cin.tie(0); ios::sync_with_stdio(0);
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;

  set<int> minus;
  vi h(n,1);
  rep(i,n-1){
    if(s[i+1] == '(')h[i+1] = h[i] + 1;
    else{
      h[i+1] = h[i] - 1;
      minus.insert(i+1);
    }
  }
  SegmentTree st(h);

  while(q--){
    int p;
    cin >> p; p--;
    if(s[p] == '('){
      s[p] = ')';
      minus.insert(p);
      st.update_range(p,n,-2);

      p = *minus.begin();
      s[p] = '(';
      minus.erase(p);
      st.update_range(p,n,2);
    }else{
      s[p] = '(';
      minus.erase(p);
      st.update_range(p,n,2);

      p = st.search(0,p+1,2);
      s[p] = ')';
      minus.insert(p);
      st.update_range(p,n,-2);
    }
    cout << p+1 << endl;
  }
}