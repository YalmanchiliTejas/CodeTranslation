#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int n;
char S[55][55];
int c[55][55];
string ans;

int main(void) {
    scanf("%d", &n);
    rep(i, 0, n) {
        scanf("%s", S[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)strlen(S[i]); j++) {
            int ch = S[i][j] - 'a';
            c[ch][i]++;
        }
    }

    rep(ch, 0, 26) {
        int cnt = 1000000000;
        rep(i, 0, n) {
            cnt = min(cnt, c[ch][i]);
        }
        rep(i, 0, cnt) ans += 'a' + ch;

    }
    
   

  
    printf("%s\n", ans.c_str());

	return 0;
}
