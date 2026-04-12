#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100010

string S;

int main()
{
    cin >> S;
    REP(i, S.length() -1) {
        if(S[i] == 'A' && S[i+1] == 'C') {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
