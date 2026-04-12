#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;

const int maxi = 1e5;
 
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = 1e9;
    for(int i = 0; i <= maxi; i++){
        ans = min(ans, i*2*C + max(0, X-i)*A + max(0, Y-i) * B);
    }

    cout << ans << endl;


    return 0;
}