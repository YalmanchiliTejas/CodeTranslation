#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=s;i<t;i++)
#define REP(i,n) FOR(i,0,n)
#define PRINT(s) cout << s << "\n"
#define SORT(A) sort(A.begin(), A.end())
#define EACHPRINT(A, T) for_each(begin(A), end(A), [&](T i){ cout << i << " "; });cout << "\n"

typedef long lint;
typedef pair<lint, lint> P;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    lint N; cin >> N;

    vector<lint> X;
    vector<lint> Y;

    REP(_, N) {
      lint x; cin >> x; X.push_back(x);Y.push_back(x);
    }
    SORT(Y);

    REP(i, N) {
      lint med = N/2;
      if(X[i] >= Y[med]) {
        cout << Y[med-1] << "\n";
      } else {
        cout << Y[med] << "\n";
      }
    }

    


    return 0;
}
