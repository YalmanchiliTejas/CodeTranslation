#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
typedef unsigned int uint;
typedef unsigned long long ull;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;
void yesno(bool ok, string yes = "Yes", string no = "No") {
    if (ok) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

ll dp[510][510][64];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ull S[N], T[N], U[N], V[N];
    REP(i, 0, N) {
        cin >> S[i];
    }
    REP(i, 0, N) {
        cin >> T[i];
    }
    REP(i, 0, N) {
        cin >> U[i];
    }
    REP(i, 0, N) {
        cin >> V[i];
    }
    bool ok = true;
    REP(i, 0, 510) {
        REP(j, 0, 510) {
            fill(dp[i][j], dp[i][j] + 64, -1);
        }
    }
    vll rowrem(64, 0);
    REP(i, 0, N) {
        REP(j, 0, 64) {
            ull tmp = U[i] & ((ull)1 << j);
            if (S[i] == 0 && tmp > 0) {
                REP(k, 0, N) {
                    if (dp[i][k][j] == 0) {
                        ok = false;
                    }
                    dp[i][k][j] = 1;
                }
            } else if (S[i] == 1 && tmp == 0) {
                REP(k, 0, N) {
                    if (dp[i][k][j] == 1) {
                        ok = false;
                    }
                    dp[i][k][j] = 0;
                }
            }
        }
    }
    vll colrem(64, 0);
    REP(i, 0, N) {
        REP(j, 0, 64) {
            ull tmp = V[i] & ((ull)1 << j);
            if (T[i] == 0 && tmp > 0) {
                REP(k, 0, N) {
                    if (dp[k][i][j] == 0) {
                        ok = false;
                    }
                    dp[k][i][j] = 1;
                }
            } else if (T[i] == 1 && tmp == 0) {
                REP(k, 0, N) {
                    if (dp[k][i][j] == 1) {
                        ok = false;
                    }
                    dp[k][i][j] = 0;
                }
            }
        }
    }
    REP(j, 0, 64) {
        REP(i, 0, N) {
            ull tmp = U[i] & ((ull)1 << j);
            if ((S[i] == 0 && tmp == 0) || (S[i] == 1 && tmp > 0)) {
                ll zero = 0;
                ll one = 0;
                REP(k, 0, N) {
                    if (dp[i][k][j] == 0) {
                        zero++;
                    } else if (dp[i][k][j] == 1) {
                        one++;
                    }
                }
                if (zero + one == N) {
                    if (zero == 0 && tmp == 0) {
                        ok = false;
                    } else if (one == 0 && tmp > 0) {
                        ok = false;
                    }
                } else {
                    rowrem[j]++;
                }
            }
            tmp = V[i] & ((ull)1 << j);
            if ((T[i] == 0 && tmp == 0) || (T[i] == 1 && tmp > 0)) {
                ll zero = 0;
                ll one = 0;
                REP(k, 0, N) {
                    if (dp[k][i][j] == 0) {
                        zero++;
                    } else if (dp[k][i][j] == 1) {
                        one++;
                    }
                }
                if (zero + one == N) {
                    if (zero == 0 && tmp == 0) {
                        ok = false;
                    } else if (one == 0 && tmp > 0) {
                        ok = false;
                    }
                } else {
                    colrem[j]++;
                }
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    // REP(i, 0, N) {
    //     REP(j, 0, N) {
    //         REP(k, 0, 64) {
    //             cout << dp[i][j][k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    // REP(i, 0, 64) {
    //     cout << rowrem[i] << " ";
    // }
    // cout << endl;
    // REP(i, 0, 64) {
    //     cout << colrem[i] << " ";
    // }
    // cout << endl;
    REP(j, 0, 64) {
        if (rowrem[j] == 0 && colrem[j] == 0) {
            continue;
        }
        if (rowrem[j] == 1) {
            // cout << "rowrem" << endl;
            ll remnum = -1;
            REP(i, 0, N) {
                ull tmp = V[i] & ((ull)1 << j);
                if (T[i] == 0 && tmp == 0) {
                    bool tmpok = false;
                    REP(k, 0, N) {
                        if (dp[k][i][j] == 0) {
                            tmpok = true;
                        } else if (dp[k][i][j] == -1) {
                            remnum = k;
                        }
                    }
                    if (!tmpok) {
                        dp[remnum][i][j] = 0;
                    }
                } else if (T[i] == 1 && tmp > 0) {
                    bool tmpok = false;
                    REP(k, 0, N) {
                        if (dp[k][i][j] == 1) {
                            tmpok = true;
                        } else if (dp[k][i][j] == -1) {
                            remnum = k;
                        }
                    }
                    if (!tmpok) {
                        dp[remnum][i][j] = 1;
                    }
                }
            }
            bool tmpok = false;
            ull tmp = U[remnum] & ((ull)1 << j);
            if (S[remnum] == 0 && tmp == 0) {
                REP(k, 0, N) {
                    if (dp[remnum][k][j] == 0) {
                        tmpok = true;
                    } else if (dp[remnum][k][j] == -1) {
                        tmpok = true;
                        dp[remnum][k][j] = 0;
                    }
                }
            } else if (S[remnum] == 1 && tmp > 0) {
                REP(k, 0, N) {
                    if (dp[remnum][k][j] == 1) {
                        tmpok = true;
                    } else if (dp[remnum][k][j] == -1) {
                        tmpok = true;
                        dp[remnum][k][j] = 1;
                    }
                }
            }
            if (!tmpok) {
                ok = false;
            }
        } else if (colrem[j] == 1) {
            // cout << "colrem " << j << " " << colrem[j] << endl;
            ll remnum = -1;
            REP(i, 0, N) {
                ull tmp = U[i] & ((ull)1 << j);
                if (S[i] == 0 && tmp == 0) {
                    bool tmpok = false;
                    REP(k, 0, N) {
                        if (dp[i][k][j] == 0) {
                            tmpok = true;
                        } else if (dp[i][k][j] == -1) {
                            remnum = k;
                        }
                    }
                    if (!tmpok) {
                        dp[i][remnum][j] = 0;
                    }
                } else if (S[i] == 1 && tmp > 0) {
                    bool tmpok = false;
                    REP(k, 0, N) {
                        if (dp[i][k][j] == 1) {
                            tmpok = true;
                        } else if (dp[i][k][j] == -1) {
                            remnum = k;
                        }
                    }
                    if (!tmpok) {
                        dp[i][remnum][j] = 1;
                    }
                }
            }
            bool tmpok = false;
            ull tmp = V[remnum] & ((ull)1 << j);
            if (T[remnum] == 0 && tmp == 0) {
                REP(k, 0, N) {
                    if (dp[k][remnum][j] == 0) {
                        tmpok = true;
                    } else if (dp[k][remnum][j] == -1) {
                        tmpok = true;
                        dp[k][remnum][j] = 0;
                    }
                }
            } else if (T[remnum] == 1 && tmp > 0) {
                REP(k, 0, N) {
                    if (dp[k][remnum][j] == 1) {
                        tmpok = true;
                    } else if (dp[k][remnum][j] == -1) {
                        tmpok = true;
                        dp[k][remnum][j] = 1;
                    }
                }
            }
            if (!tmpok) {
                ok = false;
            }
        } else {
            ll mark = 0;
            REP(i, 0, N) {
                REP(k, 0, N) {
                    if (dp[i][k][j] == -1) {
                        dp[i][k][j] = mark;
                        mark = 1 - mark;
                    }
                }
                if (colrem[j] % 2 == 0) {
                    mark = 1 - mark;
                }
            }
            // ll remnum = -1;
            // ll remnumb = -1;
            // bool mark = true;
            // REP(i, 0, N) {
            //     bool used = false;
            //     ll tmp = V[i] & ((ll)1 << j);
            //     if (T[i] == 0 && tmp == 0) {
            //         bool tmpok = false;
            //         REP(k, 0, N) {
            //             if (dp[k][i][j] == 0) {
            //                 tmpok = true;
            //             } else if (dp[k][i][j] == -1) {
            //                 if (!used) {
            //                     remnum = k;
            //                     used = true;
            //                 } else {
            //                     remnumb = k;
            //                 }
            //             }
            //         }
            //         if (!tmpok) {
            //             if (mark) {
            //                 dp[remnum][i][j] = 0;
            //             } else {
            //                 dp[remnumb][i][j] = 0;
            //             }
            //             mark = !mark;
            //         }
            //     } else if (T[i] == 1 && tmp > 0) {
            //         bool tmpok = false;
            //         REP(k, 0, N) {
            //             if (dp[k][i][j] == 1) {
            //                 tmpok = true;
            //             } else if (dp[k][i][j] == -1) {
            //                 if (!used) {
            //                     remnum = k;
            //                     used = true;
            //                 } else {
            //                     remnumb = k;
            //                 }
            //             }
            //         }
            //         if (!tmpok) {
            //             if (mark) {
            //                 dp[remnum][i][j] = 1;
            //             } else {
            //                 dp[remnumb][i][j] = 1;
            //             }
            //             mark = !mark;
            //         }
            //     }
            // }
            // bool tmpok = false;
            // ll tmp = U[remnum] & ((ll)1 << j);
            // if (S[remnum] == 0 && tmp == 0) {
            //     REP(k, 0, N) {
            //         if (dp[remnum][k][j] == 0) {
            //             tmpok = true;
            //         } else if (dp[remnum][k][j] == -1) {
            //             tmpok = true;
            //             dp[remnum][k][j] = 0;
            //         }
            //     }
            // } else if (S[remnum] == 1 && tmp > 0) {
            //     REP(k, 0, N) {
            //         if (dp[remnum][k][j] == 1) {
            //             tmpok = true;
            //         } else if (dp[remnum][k][j] == -1) {
            //             tmpok = true;
            //             dp[remnum][k][j] = 1;
            //         }
            //     }
            // }
            // if (!tmpok) {
            //     ok = false;
            // }
        }
    }
    // REP(i, 0, N) {
    //     REP(j, 0, N) {
    //         REP(k, 0, 64) {
    //             cout << dp[i][j][k];
    //         }
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
    if (!ok) {
        cout << -1 << endl;
        // cout << "aaa" << endl;
    } else {
        REP(i, 0, N) {
            REP(j, 0, N) {
                ull ans = 0;
                REP(k, 0, 64) {
                    ans += ((ull)1 << k) * dp[i][j][k];
                    // cout << (1LL << k) << " " << dp[i][j][k] << " ";
                    // cout << ans << endl;
                }
                cout << ans << " ";
            }
            cout << endl;
        }
    }
}
