#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define pb(a) push_back(a)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

typedef long long unsigned int ll;
typedef pair<ll, ll> P;

int main(){
  int N,n;
  cin >>N;
  vector<int> H;
  REP(i,N){
    int a;
    cin >>a;
    H.push_back(a);
  }
  REP(i,N){
    //cout << i << "回目" << endl;
    int f=1;
    REP(j,i){
      if(H[j]>H[i]){
        //cout << "だめだったよ" << endl;
        f=0;
        break;
      }
    }
    if(f) n++;
  }
  cout<<n<<endl;
}
