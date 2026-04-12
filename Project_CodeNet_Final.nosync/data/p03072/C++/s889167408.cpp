#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
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
typedef long long ll;
const double EPS = 1e-9;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
template<class T, class C> void chmax(T& a, C b){ a>b?:a=b; }
template<class T, class C> void chmin(T& a, C b){ a<b?:a=b; }
int main(int argc, char* argv[]) {
   int n;
   int h[100];
   int ans=0;
   int flag;
   cin >> n;
   rep(i,n){
       cin >> h[i];
   }
   for(int i = 1; i < n; i++){
       flag = 1;
       for(int j = 0; j<i; j++ ){
        if(h[i]<h[j]){
            flag = 0;
            }
       }
   if (flag)ans++;
   }

  cout << ans+1 <<endl;
    return 0;
}
