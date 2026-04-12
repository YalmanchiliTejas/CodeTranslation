#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;

ll solodd(const vector<ll> &as) {
    ll n = as.size();
    vector<vector<ll>  > memo(3, vector<ll>(n, 0));
    vector<vector<int> > visit(3, vector<int>(n, 0));


    memo[0][0] = as[0];
    memo[1][1] = as[1];
    memo[2][2] = as[2];
    visit[0][0] = visit[1][1] = visit[2][2] = 1;

    for (int x = 0; x < n; x++) {
        for (int s = 0; s < 3; s++) {
            if (visit[s][x] == 0) {
                continue;
            }
            if (s == 0) {
                if (x >= n - 3) { continue; }
                memo[0][x + 2] = memo[0][x] + as[x + 2];
                visit[0][x + 2] = 1;

                if (!visit[1][x + 3]) {
                    memo[1][x + 3] = memo[0][x] + as[x + 3];
                    visit[1][x + 3] = 1;
                }
                memo[1][x + 3] = max(memo[1][x + 3], memo[0][x] + as[x + 3]);

                if (!visit[2][x + 4]) {
                    memo[2][x + 4] = memo[0][x] + as[x + 4];
                    visit[2][x + 4] = 1;                    
                }                    
                memo[2][x + 4] = max(memo[2][x + 4], memo[0][x] + as[x + 4]);

            } else if (s == 1) {
                if (x >= n - 2) { continue; }
                
                if (!visit[1][x + 2]) {
                    memo[1][x + 2] = memo[1][x] + as[x + 2];
                    visit[1][x + 2] = 1;
                }                    
                memo[1][x + 2] = max(memo[1][x + 2], memo[1][x] + as[x + 2]);                

                
                if (!visit[2][x + 3]) {
                    memo[2][x + 3] = memo[1][x] + as[x + 3];
                    visit[2][x + 3] = 1;
                }
                memo[2][x + 3] = max(memo[2][x + 3], memo[1][x] + as[x + 3]);
            } else {
                if (x >= n - 1) { continue; }
                if (!visit[2][x + 2]) {
                    memo[2][x + 2] = memo[2][x] + as[x + 2];
                    visit[2][x + 2] = 1;
                }
                memo[2][x + 2] = max(memo[2][x + 2], memo[2][x] + as[x + 2]);
            }
        }
    }
    return max(max(memo[0][n-3], memo[1][n-2]), memo[2][n-1]);
}

ll soleven(const vector<ll> &as) {
    ll n = as.size();
    vector<vector<ll>  > memo(2, vector<ll>(n, 0));
    vector<vector<int> > visit(2, vector<int>(n, 0));


    memo[0][0] = as[0];
    memo[1][1] = as[1];
    visit[0][0] = visit[1][1] = 1;

    for (int x = 0; x < n; x++) {
        for (int s = 0; s < 2; s++) {
            if (visit[s][x] == 0) {
                continue;
            }
            if (s == 0) {
                if (x >= n - 2) { continue; }
                memo[0][x + 2] = memo[0][x] + as[x + 2];
                visit[0][x + 2] = 1;

                if (!visit[1][x + 3]) {
                    memo[1][x + 3] = memo[0][x] + as[x + 3];
                    visit[1][x + 3] = 1;
                }
                memo[1][x + 3] = max(memo[1][x + 3], memo[0][x] + as[x + 3]);
            } else {
                if (x >= n - 1) { continue; }
                
                if (!visit[1][x + 2]) {
                    memo[1][x + 2] = memo[1][x] + as[x + 2];
                    visit[1][x + 2] = 1;
                }                    
                memo[1][x + 2] = max(memo[1][x + 2], memo[1][x] + as[x + 2]);                
            }
        }
    }
    return max(memo[0][n-2], memo[1][n-1]);
}


int main () {
    ll n; cin >> n;
    vector<ll> as(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
    }

    if (n % 2 == 0) {
        cout << soleven(as) << endl;
    } else {
        cout << solodd(as) << endl;
    }
    return 0;
}