#include <iostream>
#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long ll;
typedef ll li;
typedef pair<int,int> PI;
#define EPS (1e-10L)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) a.begin(),a.end()
#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)
void pkuassert(bool t){t=1/t;};

int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};

int main(int argc, char *argv[])
{
  string ri("qwertasdfgzxcvb");
  string in;
  while(cin >> in && in!="#"){
    int ans = 0;
    bool ini=
      ri.find(in[0]) == string::npos;
    rep(i,SZ(in)-1){
      bool np=
        ri.find(in[i+1]) == string::npos;
      if(np!=ini) ++ ans;
      ini=np;
    }
    cout << ans << endl;
  }
  return 0;
}