#include<bits/stdc++.h>
#define MAX_N 100001
#define INF_INT 2147483647
#define INF_LL 9223372036854775807
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
void init(int n);
int find(int n);
void unite(int x,int y);
bool same(int x, int y);
ll bpow(ll,ll,ll);
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B);
mat pow(mat A,ll n);
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
const int MOD = 1000000007;

bool cmp_P(const P &a,const P &b){
  return a.second < b.second;
}
int main()
{
  int N,a[100001],b[100001];
  ll ans=0;
  cin >> N;
  REP(i,N)cin >> a[i];
  deque<int> que,cons;
  sort(a,a+N);
  REP(i,N)que.push_back(a[i]);
  bool f=0;
  if(!que.empty()){
    int d = que.back();que.pop_back();
    cons.push_front(d);
  }
  REP(i,N){
    while(!que.empty()){
      if(f==0){
        if(!que.empty()){
          int d = que.front();que.pop_front();
          cons.push_front(d);
        }
        if(!que.empty()){
          int d = que.front();que.pop_front();
          cons.push_back(d);
        }
        f=1;
      }else{
        if(!que.empty()){
          int d = que.back();que.pop_back();
          cons.push_front(d);
        }
        if(!que.empty()){
          int d = que.back();que.pop_back();
          cons.push_back(d);
        }
        f = 0;
      }

    }
  }
  ll res=0,d=0;
  while(!cons.empty()){
    b[d++] = cons.front();cons.pop_front();
  }
  REP(i,N-1){
  
    res += abs(b[i+1] - b[i]);
  }
  ans = res;
  REP(i,N)que.push_back(a[i]);
  f=1;
  if(!que.empty()){
    int d = que.front();que.pop_front();
    cons.push_front(d);
  }
  REP(i,N){
    while(!que.empty()){
      if(f==0){
        if(!que.empty()){
          int d = que.front();que.pop_front();
          cons.push_front(d);
        }
        if(!que.empty()){
          int d = que.front();que.pop_front();
          cons.push_back(d);
        }
        f=1;
      }else{
        if(!que.empty()){
          int d = que.back();que.pop_back();
          cons.push_front(d);
        }
        if(!que.empty()){
          int d = que.back();que.pop_back();
          cons.push_back(d);
        }
        f = 0;
      }

    }
  }
  d = 0;
  while(!cons.empty()){
    b[d++] = cons.front();cons.pop_front();
  }
  res = 0;
  REP(i,N-1){
    res += abs(b[i+1] - b[i]);
  }
  ans = max(res,ans);
  cout << ans << endl;
  return 0;
}

