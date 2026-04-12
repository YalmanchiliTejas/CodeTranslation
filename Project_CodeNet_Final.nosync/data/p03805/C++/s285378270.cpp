#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <vector>
#include <deque>
#include <cstdlib>
#include <numeric>
#include <cstring>
#include <ctime>
#include <climits>
#include <sstream>
#include <complex>
#define Mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define Rep(__i,__n) for(int __i = 0 ; __i < (__n);__i++)
#define Range(_ind,_a,_b) for(int _ind = (_a) ; _ind <(int)(_b);_ind++)
#define iRange(_i,_a,_b,_c) for(int _i = (_a) ; _i <(int)_b;_i+=_c)
#define All(__cont)  (__cont).begin(),(__cont).end()
#define ForEach(_itr,_cont) for(auto _itr  = _cont.begin();_itr !=  _cont.end();_itr++)


using namespace std;
typedef complex<double> P;
typedef long long ll;
typedef vector<int> vi ;
typedef vector<double> vd;
typedef vector<vector <int> > vvi;
typedef vector<vector<double> > vvd;
typedef pair<int,int> pii;
const int inf = INT_MAX / 3;
const double eps = 1e-9;

template <typename T >
void output(T a,string label = ""){
#ifdef DEBUG
  cout<<"[" <<(label==""?"":label + ":")<< a <<  "]"<< endl;
#endif
}
template <typename T>
void output(vector<T> &vec){
#ifdef DEBUG
  cout << "[";
  ForEach(itr,vec){
    if(itr != vec.begin())cout << ",";
    cout << *itr;
  }
  cout << "]"<<endl;;
#endif
}
#ifndef __NOT__MAIN
vi route;
int DFS(vvi &g, vi &visited, const int now, const size_t count){
  int ans = 0;
  route.pb(now);
  visited[now] = true;
  if (count+1 == g.size()) {
    ans = 1 ;
  } 
  ForEach(next, g[now]) {
    if(!visited[*next]){
      ans += DFS(g, visited, *next, count+1);
    }
  }  
  visited[now] = false;
  route.pop_back();
  return ans;
}
int main(){
  int N, M;
  cin >> N >> M;
  vvi graph(N);
  Rep(_i, M){
    int a, b;
    cin >> a >> b;
    a--;b--;
    graph[a].pb(b);
    graph[b].pb(a);
  }
  vi visited(N,false);
  cout << DFS(graph, visited, 0, 0) << endl;
}
#endif
