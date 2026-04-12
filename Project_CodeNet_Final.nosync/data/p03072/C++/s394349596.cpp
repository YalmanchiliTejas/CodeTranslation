#include<bits/stdc++.h>

using namespace std;

#define int long long

#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)

typedef vector<int> VI;
typedef pair<int, int> PII;

//-------------------

int ans = 0;

signed main(){

    int N;
    cin >> N;

    int prev = -1;
    bool ok = true;

    REP(i, N){
        int y;
        cin >> y;
        if(prev <= y){
            ans++;
            prev = y;
        }
    }

    cout << ans << endl;

    return 0;
}
