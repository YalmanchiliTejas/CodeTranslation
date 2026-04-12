#include <iostream>
#include <iomanip> // << fixed << precision(10)
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

    lint res = 0;

    if(N == 7 || N == 5 || N == 3) PRINT("YES");
    else PRINT("NO");

    return 0;
}
