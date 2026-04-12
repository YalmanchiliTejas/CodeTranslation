#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(int)(N);i++)
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pii;

struct FenwickTree{
  int n;
  vector<int> bit;
  FenwickTree(int x=0):n(x){bit = vector<int>(x+1,0);}

  inline void add(int i, int x){
    while(i<=n){
      bit[i] += x;
      i += i & -i;
    }
  }

  inline int sum(int i){
    int res = 0;
    while(i > 0){
      res += bit[i];
      i -= i & -i;
    }
    return res;
  }

  inline int partial_sum(int l, int r){ return sum(r) - sum(l-1); }
};

int n,k;
vi r;

bool compare_sa(int i, int j){
  if(r[i]!=r[j]) return r[i] < r[j];
  int ri = i+k<=n ? r[i+k] : -1;
  int rj = j+k<=n ? r[j+k] : -1;
  return ri < rj;
}

void construct_sa(string &s, vi &sa){
  n = s.size();
  r.resize(n+1);
  vi tmp (n+1);
  sa.resize(n+1);
  
  rep(i,n+1){
    sa[i] = i;
    r[i] = i<n ? s[i] : -1;
  }

  for(k=1;k<=n;k*=2){
    sort(sa.begin(), sa.end(), compare_sa);

    tmp[sa[0]] = 0;
    for(int i=1;i<=n;i++){
      tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
    }
    rep(i,n+1)r[i] = tmp[i];
  }
}

int find(const vi &sa, const string &T, const string &S){
  int a = 0, b = sa.size();
  while(b - a > 1){
    int c = (a+b)/2;
    if(S.compare(sa[c], T.size(), T) < 0) a = c;
    else b = c;
  }
  return b;
}


int main(){
  string s;
  int q;
  cin >> s >> q;

  vi sa;
  construct_sa(s,sa);

  vector<pii> query;
  rep(i,sa.size()){
    query.push_back( pii(sa[i], -i-1) );
  }

  vector<pii> LR(q);
  rep(i,q){
    string M;
    int L, R;
    cin >> L >> R >> M;
    R -= M.size() - 1;

    int A = find(sa, M, s);
    int B = find(sa, M+"|", s);
    
    LR[i] = pii(A,B);
    query.push_back( pii(L-1, 2*i) );
    query.push_back( pii(R, 2*i+1) );
  }

  sort(query.begin(), query.end());

  vector<int> ans(q,0);
  FenwickTree bit(sa.size());
  for(pii p : query){
    if(p.second < 0){
      bit.add(-p.second, 1);
    }else{
      int lq = LR[p.second/2].first, rq = LR[p.second/2].second;
      int num = bit.partial_sum(lq+1, rq);
      
      if(p.second & 1){
	ans[p.second/2] += num;
      }else{
	ans[p.second/2] -= num;
      }
    }
  }

  for(int i=0;i<q;i++){
    cout << ans[i] << endl;
  }

}