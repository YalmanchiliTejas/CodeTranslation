#include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

char S[100];

int main() {
  // ios_base::sync_with_stdio(0);

  scanf("%s", S);
  REP(i,strlen(S)-1) if (string(S+i, 2) == "AC") {
    printf("Yes\n");
    return 0;
  }
  printf("No\n");
}
