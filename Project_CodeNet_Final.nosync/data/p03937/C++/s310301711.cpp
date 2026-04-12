#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;

int GCD(int a, int b){return b == 0 ? a : GCD(b, a % b);}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m, k = 0;
    cin >> n >> m;

    string cur;

    for(int i = 0; i < n; ++i){
        cin >> cur;

        /*

        // Forgot to account the case where you go down but go back up again

        if(i > 0){
            for(int j = 1; j < m; ++j){
                if(prev[j] == '#' && cur[j] == '#' && cur[j - 1] == '#'){
                    cout << "Impossible";
                    return 0;
                }
            }
        }*/

        for(auto j : cur){
            if(j == '#')
                ++k;
        }

        //prev = cur;
    }

    if(k == n + m - 1)
        cout << "Possible";
    else
        cout << "Impossible";

    return 0;
}
