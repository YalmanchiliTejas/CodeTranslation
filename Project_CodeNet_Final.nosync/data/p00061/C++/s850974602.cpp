#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define lengthof(x) (sizeof(x) / sizeof(*(x)))
#define FILL(ptr, value) FILL_((ptr), sizeof(ptr)/sizeof(value), (value))
template <typename T>
void FILL_(void * ptr, size_t size, T value){
  std::fill((T*)ptr, (T*)ptr+size, value);
}
//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};
typedef pair<int,int> P;
int R[110];
int main()
{
  int a,b;
  char c;
  vector<P> V;
  while(cin>>a>>c>>b,a||b){
    V.push_back(P(b,a));
  }
  sort(V.begin(),V.end(),greater<P>() );
  int k;
  int l;
  while(cin >>k){
  int ans = 1;
  for(int i = 0;i <V.size();i++){
    if(k == V[i].second){
      l = i;
      break;
    }
  }
  int c = -20;
  for(int i = 0;i <V.size();i++){
    if(V[l].first <V[i].first && V[i].first !=c){
      ans++;
      c = V[i].first;
    }
    }
  cout <<ans<<endl;
  }
  return 0;
}