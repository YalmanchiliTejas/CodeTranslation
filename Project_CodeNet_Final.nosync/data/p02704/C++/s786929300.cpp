#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef unsigned long long Int;
typedef pair<int,int> P;

Int power(Int a, Int n) {
    Int res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}


int main() {
    Int N;
    cin >> N;
    vector<vector<vector<int>>> A(64, vector<vector<int>>(N, vector<int>(N,0)));

    vector<int> S(N), T(N);
    vector<Int> Uall(N), Vall(N);
    rep(i,N) cin >> S[i];
    rep(i,N) cin >> T[i];
    rep(i,N) cin >> Uall[i];
    rep(i,N) cin >> Vall[i];

    vector<vector<Int>> U(64, vector<Int>(N,0));
    vector<vector<Int>> V(64, vector<Int>(N,0));

    rep(i,N) {
        rep(j,63) {
            U[j][i] = (Uall[i] % power(2,j+1)) / power(2,j);
            V[j][i] = (Vall[i] % power(2,j+1)) / power(2,j);
        }
        U[63][i] = Uall[i] / power(2,63);
        V[63][i] = Vall[i] / power(2,63);
    }


    
    //各ビットごとに0,1からなる行列を構成する
    rep(i,64) {
        if (N == 1) {
            if (U[i][0] == 1 && V[i][0] == 1) {
                A[i][0][0] = 1;
            }
            else if (U[i][0] == 0 && V[i][0] == 0) {
                A[i][0][0] = 0;
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
        else {

        //もう決めたかどうかを管理
        vector<vector<bool>> defined(N, vector<bool>(N, false));

        //すぐ決まらない行や列とその個数を管理
        set<int> undefined_row, undefined_column;
        //int num_of_undefr = 0, num_of_undefc = 0;

        vector<int> row_1(N,0), column_1(N,0);


        //すぐ決まる分を入れる
        //行について
        rep(j,N) {
            if (S[j] == 0 && U[i][j] == 1) {
                rep(k,N) {
                    A[i][j][k] = 1;
                    defined[j][k] = true;
                    row_1[j]++;
                    column_1[k]++;
                }
            }
            else if (S[j] == 1 && U[i][j] == 0) {
                rep(k,N) {
                    defined[j][k] = true;
                }
            }
            else {
                undefined_row.insert(j);
                //num_of_undefr++;
            }
        }

        //列について
        rep(j,N) {
            if (T[j] == 0 && V[i][j] == 1) {
                rep(k,N) {
                    if (defined[k][j] && A[i][k][j] == 0) {
                        cout << -1 << endl;
                        return 0;
                    }
                    else {
                        A[i][k][j] = 1;
                        if (!defined[k][j]) {
                            defined[k][j] = true;
                            column_1[j]++;
                            row_1[k]++;
                        }
                    }
                }
            }
            else if (T[j] == 1 && V[i][j] == 0) {
                rep(k,N) {
                    if (A[i][k][j] == 1) {
                        cout << -1 << endl;
                        return 0;
                    }
                    else {
                        defined[k][j] = true;
                    }
                }
            }
            else {
                undefined_column.insert(j);
                //num_of_undefc++;
            }

        }

        //決まっていないところがない場合は次のビットへ
        //if (num_of_undefr == 0 || num_of_undefc == 0) continue;

        //決まっていないところが2*2行列以上なら"市松模様"を入力
        /*else if (num_of_undefr > 1 && num_of_undefc > 1) {
            for (auto iter = undefined_row.begin(); iter != undefined_row.end(); ++iter) {
                for (auto itec = undefined_column.begin(); itec != undefined_column.end(); ++itec) {
                    int x = distance(undefined_row.begin(), iter);
                    int y = distance(undefined_column.begin(), itec);
                    A[i][*iter][*itec] = (x + y) % 2;
                }
            }
            continue;
        }*/

        for (auto iter = undefined_row.begin(); iter != undefined_row.end(); ++iter) {
            for (auto itec = undefined_column.begin(); itec != undefined_column.end(); ++itec) {
                if (U[i][*iter] == 1 && V[i][*itec] == 1) {
                    A[i][*iter][*itec] = 1;
                    defined[*iter][*itec] = true;
                    row_1[*iter]++;
                    column_1[*itec]++;
                }
                if (U[i][*iter] == 0 && V[i][*itec] == 0) {
                    A[i][*iter][*itec] = 0;
                    defined[*iter][*itec] = true;
                }
            }
        }


        //論理和が1であってほしいのに1がひとつもない行があればそこを訂正していく
        rep(j,N) {
            if (U[i][j] == 1 && row_1[j] == 0) {
                rep(k,N) {
                    if (T[k] == 0) {
                        if (column_1[k] < N-1) {
                            A[i][j][k] = 1;
                            defined[j][k] = true;
                            row_1[j]++;
                            column_1[k]++;
                            break;
                        }
                    }
                    if (k == N-1) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }

        //同様のことを列についてやる
        rep(j,N) {
            if (V[i][j] == 1 && column_1[j] == 0) {
                rep(k,N) {
                    if (S[k] == 0) {
                        if (row_1[k] < N-1) {
                            A[i][k][j] = 1;
                            defined[k][j] = true;
                            row_1[k]++;
                            column_1[j]++;
                            break;
                        }
                    }
                    if (k == N-1) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
        }


        
        






        //一旦出力させてみる
        /*rep(j,N) {
            rep(k,N-1) cout << A[i][j][k] << " ";
            cout << A[i][j][N-1] << endl;
        }*/
    }
    
    
    vector<vector<Int>> ans(N, vector<Int>(N,0));

    rep(i,N) {
        rep(j,N) {
            rep(k,64) {
                ans[i][j] += (Int)A[k][i][j] * power(2,k);
            }
        }
    }

    rep(i,N) {
        rep(j,N-1) cout << ans[i][j] << " ";
        cout << ans[i][N-1] << endl;
    }
}
