#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    #define EXIT { cout << "-1\n"; return 0;}
    using UINT64 = unsigned long long;

    int n; 
    cin >> n;  
    
    vector<vector<int>> M(2, vector<int>(n, 0));
    vector<vector<UINT64>> X(2, vector<UINT64>(n, 0));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> X[i][j];
        }
    }


    vector<vector<UINT64>> res(n, vector<UINT64>(n, 0));

    auto check = [&]() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                auto tar = X[i][j];
                int op = M[i][j];
                UINT64 val = 0;
                if (i == 0) {
                    val = res[j][0];
                } else {
                    val = res[0][j];
                }
                for (int k = 0; k < n; ++k) {
                    int x = j, y = k;
                    if (i == 1) {
                        swap(x, y);
                    }
                    if (op == 0) {
                        val &= res[x][y];
                    } else {
                        val |= res[x][y];
                    }
                }
                if (val != tar) {
                    return false;
                }
            }
        }
        return true;
    };

    auto build = [&](UINT64 b) -> bool  {
        vector<vector<int>> F(n, vector<int>(n, 0));

        vector<vector<int>> cnts(2, vector<int>(n, 0));
        vector<vector<int>> reqs(2, vector<int>(n, 0));
        vector<vector<vector<pair<int,int>>>> cands(2, vector<vector<pair<int,int>>>(n));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                UINT64 tar = (X[i][j] & b) ? 1 : 0;
                int op = M[i][j];
                for (int k = 0; k < n; ++k) {
                    int x = j, y = k;
                    if (i == 1) {
                        swap(x, y);
                    }

                    if (op == 0 && tar == 1) {
                        F[x][y] |= 2;
                    }
                    if (op == 1 && tar == 0) {
                        F[x][y] |= 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (F[i][j] == 3) {
                    return false;
                }
            }
        }


        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                UINT64 tar = (X[i][j] & b) ? 1 : 0;
                int op = M[i][j];
                reqs[i][j] = tar;
                // cout << i << "," << j <<  ": " << tar << endl;
                for (int k = 0; k < n; ++k) {
                    int x = j, y = k;
                    if (i == 1) {
                        swap(x, y);
                    }
                    if (F[x][y] != 0) {
                        int v = F[x][y] == 1 ? 0 : 1;
                        if (v == tar) {
                            cnts[i][j] = 0;
                            cands[i][j].clear();
                            break;
                        }
                        continue;
                    }
                    // cout << i << "," << j << "::: " << x <<"," << y << " " << F[x][y] << endl;
                    ++cnts[i][j];
                    cands[i][j].emplace_back(x, y);
                }
            }
        }


        vector<vector<bool>> used(n, vector<bool>(n, false));

        while (true) {
            int mn = n + 123;
            pair<int,int> S{-1, -1};

            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < n; ++j) {
                    // assert(cnts[i][j] >= 0);
                    if (cnts[i][j] <= 0) {
                        continue;
                    }
                    if (mn > cnts[i][j]) {
                        mn = cnts[i][j];
                        S = make_pair(i, j);
                    }
                }
            }
            if (S.first < 0) {
                break;
            }
            for (auto& P : cands[S.first][S.second]) {
                int x = P.first;
                int y = P.second;
                if (!used[x][y]) {
            // cout << S.first << " x " << S.second
            //     << ": " << x << " " << y << " " << reqs[S.first][S.second] << endl;

                    used[x][y] = true;
                    F[x][y] |= 1 << reqs[S.first][S.second];
                    cnts[S.first][S.second] = 0;
                    if (S.first == 0) {
                        cnts[1][y] -= 1;
                    } else {
                        cnts[0][x] -= 1;
                    }
                    break;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int x = F[i][j] == 2 ? 1 : 0;
                if (x) {
                    res[i][j] |= b;
                }
            }
        }

        return true;
    };

    for (int _ = 0; _ < 64; ++_) {
        UINT64 b = 1ULL << _;

        if (!build(b)) {
            EXIT;
        }
    }

    if (!check()) {
        EXIT;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << (j == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}