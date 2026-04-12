#include <bits/stdc++.h>
using namespace std;

#define SORT(c) sort((c).begin(), (c).end())
#define REVERSE(v) reverse((v).begin(), (v).end())
#define ANS(ans) cout << (ans) << endl;
#define UNIQUE(v) (v).erase(unique((v).begin(), (v).end()), (v).end());
typedef vector<int> VI;
typedef pair<int, int> P;

//repetition
//------------------------------------------
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define REP(i, n) for (long long i = 0; i < (n); ++i)

int main()
{
    int n,m;
    cin>>n>>m;

    if(n==m){
      ANS("Yes");
    } else {
      ANS("No");
    }
    return 0;
}
