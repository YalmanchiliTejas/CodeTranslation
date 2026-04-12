#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

inline void add(ll &x, ll y) { x += y; if (x >= MOD) x -= MOD; }

ll mod_pow(ll x, ll k) {
	ll res = 1;
	for (; k; x = x * x % MOD, k /= 2) {
		if (k & 1) {
			res = res * x % MOD;
		}
	}
	return res;
}

int N;
int h[110];
int mh[110][110];
ll dp[110][110][2][2][2]; //left, right, same
ll sub[110][2][2][2]; //left, right, same
ll tb[110][110][2][2][2];

void calc(int l, int r, int lo, int &pt) {
	//cerr << l << " " << r << " " << lo << endl;

	bool sm = 1;
	for (int i = l; i <= r; ++i) if (mh[l][r] != h[i]) {
		sm = 0;
	}

	int now = pt++;
	if (sm) {
		rep(j, 2) {
			rep(k, 2) {
				rep(t, 2) {
					tb[now][r][j][k][t] = sub[r-l+1][j][k][t];
				}
			}
		}
	} else {
		int la = -1;

		for (int m = l; m <= r; ++m) {
			if (h[m] == mh[l][r]) {
				if (la != -1) {
					calc(la, m-1, mh[l][r], pt);
					if (la == l) {
						rep(j, 2) {
							rep(k, 2) {
								rep(t, 2) {
									if (t == 1) {
										add(tb[now][m-1][j^1][k^1][t], dp[la][m-1][j][k][t]);
									} else {
										add(tb[now][m-1][j^1][k^1][t], dp[la][m-1][j][k][t]);
										add(tb[now][m-1][j][k][t], dp[la][m-1][j][k][t]);
									}
								}
							}
						}					
					} else {
						rep(j, 2) {
							rep(k, 2) {
								rep(t, 2) {
									rep(jj, 2) {
										rep(kk, 2) {
											rep(tt, 2) {
												int nj, nk, nt;
												if (tt == 1) {
													nj = j, nk = kk ^ 1, nt = (t | tt) | (k == (jj ^ 1));
													add(tb[now][m-1][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][m-1][jj][kk][tt] % MOD);
												} else {
													nj = j, nk = kk ^ 1, nt = (t | tt) | (k == (jj ^ 1));
													add(tb[now][m-1][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][m-1][jj][kk][tt] % MOD);

													nj = j, nk = kk, nt = (t | tt) | (k == jj);
													add(tb[now][m-1][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][m-1][jj][kk][tt] % MOD);
												}
											}
										}
									}
								}
							}
						}					
					}
				}

				if (m == l) {
					tb[now][l][0][0][0] = tb[now][l][1][1][0] = 1;
				} else {
					rep(j, 2) {
						rep(k, 2) {
							rep(t, 2) {
								if (tb[now][m-1][j][k][t] == 0) continue; 
								rep(nx, 2) {
									add(tb[now][m][j][nx][t | (nx == k)], tb[now][m-1][j][k][t]); 
								}
							}
						}
					}
				}
				la = -1;
			} else if (h[m] > mh[l][r]) {
				if (la == -1) {
					la = m;
				}
			}
		}

		if (la != -1) {
			calc(la, r, mh[l][r], pt);

			rep(j, 2) {
				rep(k, 2) {
					rep(t, 2) {
						if (tb[la-1][j][k][t] == 0) continue;
						rep(jj, 2) {
							rep(kk, 2) {
								rep(tt, 2) {
									if (dp[la][r][jj][kk][tt] == 0) continue;
									int nj, nk, nt;
									if (tt == 1) {
										nj = j, nk = kk ^ 1, nt = ((t | tt) | (k == (jj ^ 1)));
										add(tb[now][r][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][r][jj][kk][tt] % MOD);
									} else {
										nj = j, nk = kk ^ 1, nt = ((t | tt) | (k == (jj ^ 1)));
										add(tb[now][r][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][r][jj][kk][tt] % MOD);

										nj = j, nk = kk, nt = ((t | tt) | (k == jj));
										add(tb[now][r][nj][nk][nt], tb[now][la-1][j][k][t] * dp[la][r][jj][kk][tt] % MOD);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	int num = mh[l][r] - lo - 1;
	ll p[2];

	if (num == 0) {
		p[0] = 1;
		p[1] = 0;
	} else {
		p[0] = p[1] = mod_pow(2, num - 1);
	}

	rep(j, 2) {
		rep(k, 2) {
			rep(t, 2) {
				if (t == 1) {
					bool b = (num & 1);
					add(dp[l][r][j^b][k^b][t], tb[now][r][j][k][t]);
				} else {
					rep(b, 2) {
						add(dp[l][r][j^b][k^b][t], tb[now][r][j][k][t] * p[b] % MOD);
					}
				}
			}
		}
	}
}

int main() {
	cin >> N;
	rep(i, N) cin >> h[i];
	ll pp = 1;

	if (N >= 2) {
		if (h[0] > h[1]) {
			pp = pp * mod_pow(2, h[0] - h[1]) % MOD;
			h[0] = h[1];
		}
		if (h[N-2] < h[N-1]) {
			pp = pp * mod_pow(2, h[N-1] - h[N-2]) % MOD;
			h[N-1] = h[N-2];
		}
	}

	while (true) {
		bool fd = 0;
		rep(i, N) {
			if (i > 0 && i + 1 < N && h[i] > h[i+1] && h[i] > h[i-1]) {
				pp = pp * mod_pow(2, h[i] - max(h[i-1], h[i+1])) % MOD;
				h[i] = max(h[i-1], h[i+1]);
				fd = 1;
			}
		}
		if (!fd) {
			break;
		}
	}

	rep(i, N) {
		int d = 2e9;
		for (int j = i; j < N; ++j) {
			d = min(d, h[j]);
			mh[i][j] = d;
		}
	}

	sub[1][0][0][0] = sub[1][1][1][0] = 1;

	for (int i = 1; i < N; ++i) {
		rep(j, 2) {
			rep(k, 2) {
				rep(l, 2) {
					if (sub[i][j][k][l] == 0) continue;
					rep(nx, 2) {
						add(sub[i+1][j][nx][l | (k == nx)], sub[i][j][k][l]);
					}
				}
			}
		}
	}

	int k = 0;
	calc(0, N-1, 0, k);
	ll ret = 0;
	rep(j, 2) {
		rep(k, 2) {
			rep(t, 2) {
				add(ret, dp[0][N-1][j][k][t]);
			}
		}
	}

	cout << ret * pp % MOD << endl;

	return 0;
}