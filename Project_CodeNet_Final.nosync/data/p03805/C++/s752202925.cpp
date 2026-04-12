#include<bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
using namespace std;
#define COUT(v) cout<<(v)<<endl
#define CIN(n)  int(n);cin >> (n)
#define YES(n) cout<<((n)? "YES" : "NO")<<endl
#define Yes(n) cout<<((n)? "Yes" : "No")<<endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) <<endl
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
 
#define FOREACH(x,a) for(auto& (x) : (a) )
 
#define ALL(obj) (obj).begin(),(obj).end()
 
#define P pair<int,int>
#define I vector<int>
#define S set<int>
#define pb(v) push_back(v)
#define V vector
#define rt return
class Edge{
public:
    int from,to,value;
    Edge(int a,int b,int c){
        from = a;
        to = b;
        value = c;
    }
    Edge(int a,int b){
        from = a;
        to = b;
    }
};
int N,M;
int ar[10];
int main(){
  vector<Edge> vec;
  cin >> N >> M;
  REP(a,M){
      CIN(b);CIN(c);
      Edge E(b,c);
      vec.pb(E);
  }
  I ne(N-1);
  iota(ALL(ne),2);
  int ans = 0;
  do{
      bool result = true;
      for(int a = 0;a < N-1;a++){
          if(a==0){
              bool w = false;
              FOREACH(v,vec){
                  if(v.from==1&&v.to==ne.at(a)){
                      w = true;
                      break;
                  }
                  if(v.to==1&&v.from==ne.at(a)){
                      w = true;
                      break;
                  }
              }
              if(!w){
                 result = false;
                 break;
              }
          }else{
              bool w = false;
              FOREACH(v,vec){
                  if(v.from==ne.at(a-1)&&v.to==ne.at(a)){
                      w = true;
                      break;
                  }
                  if(v.to==ne.at(a-1)&&v.from==ne.at(a)){
                      w = true;
                      break;
                  }
              }
              if(!w){
                 result = false;
                 break;
              }
          }
      }
      if(result)ans++;
  }while(next_permutation(ALL(ne)));
  COUT(ans);
  return 0;
}
