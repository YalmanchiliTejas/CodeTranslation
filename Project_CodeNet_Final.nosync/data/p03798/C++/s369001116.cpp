#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

bool X[100100];
int main(){
    int N;
    cin >> N;
    REP(i,N){
        char c;
        cin >> c;
        if(c == 'x') X[i] = true;
    }

    string start[4] = {"SS", "SW", "WS", "WW"};

    string ans;
    bool find = false;
    for(int k = 0; k < 4; k++){
        ans = start[k];
        for(int i = 1; i < N; i++){
            bool x = X[i];
            bool s = (ans[i] == 'S');
            bool ss = (ans[i-1] == 'S');
            if((s && ss && x) || (s && !ss && !x) || (!s && !ss && x) || (!s && ss && !x))
                ans += "W";
            else
                ans += "S";
        }
        if(ans[0] == ans[N]){
            ans.pop_back();
            bool x = X[0];
            bool s = (ans[0] == 'S');
            bool ss = (ans[N-1] == 'S');
            char next;
            if((s && ss && x) || (s && !ss && !x) || (!s && !ss && x) || (!s && ss && !x))
                next = 'W';
            else
                next = 'S';
            if(next == ans[1]){
                find = true;
                break;
            }
        }
    }

    if(find)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}
