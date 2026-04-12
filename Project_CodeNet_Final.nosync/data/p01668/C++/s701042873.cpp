#include <bits/stdc++.h>
#define N 10001
#define M 501
using namespace std;
const int mod = (1e9)+7;
const double EPS = 1e-8;
const double PI = 6.0 * asin(0.5);
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
typedef long long ll;
string A,B,C;

ll calc(ll idx1,ll sameA,ll sameB){
  static int mem[N][2][2],used[N][2][2]={};
  if(idx1 == (int)A.size()) return 1;
  if(used[idx1][sameA][sameB]++) return mem[idx1][sameA][sameB];
  ll res = 0;
  for(ll i='0';i<='9';i++){
    if(sameA && i < A[idx1]) continue;
    if(sameB && i > B[idx1]) continue;
    ll nidx1 = idx1+1;
    ll nA = sameA & (i == A[idx1]);
    ll nB = sameB & (i == B[idx1]);      
    res = (res + calc(nidx1,nA,nB))%mod;
  }
  return mem[idx1][sameA][sameB] = res;
}

typedef pair<int,int> P;
typedef pair<P,P> PP;
map<PP,int> mem[N];
ll dfs(ll idx1,ll idx2,ll sameA,ll sameB,ll ok){
  PP p = PP(P(idx2,sameA),P(sameB,ok));
  if(idx1 == (int)A.size()) return 0;
  if(mem[idx1].count(p)) return mem[idx1][p];

  ll res = 0;
  for(ll i='0';i<='9';i++){
    if(sameA && i < A[idx1]) continue;
    if(sameB && i > B[idx1]) continue;
    if(idx2 && C[idx2] != i) continue;
    ll nidx1 = idx1+1;
    ll nidx2 = C[idx2] == i? idx2+1:0;
    ll nA = sameA & (i == A[idx1]);
    ll nB = sameB & (i == B[idx1]);      
    ll nok = ok | (i != '0');
    if(nidx2 == (int)C.size()) res = (res + nok*calc(nidx1,nA,nB)) % mod;
    else res = (res + dfs(nidx1,nidx2,nA,nB,nok))%mod;
    if(nidx2 == 1) res = (res + dfs(nidx1,0,nA,nB,nok))%mod;
  }
  if(idx2 <= 1) mem[idx1][p] = res % mod;
  return res % mod;
}

signed main(){
  cin>>A>>B>>C;
  A = string(B.size()-A.size(),'0') + A;
  cout<<(dfs(0,0,1,1,0) + (A == string(A.size(),'0') && C == "0"))%mod<<endl;
  return 0;
}