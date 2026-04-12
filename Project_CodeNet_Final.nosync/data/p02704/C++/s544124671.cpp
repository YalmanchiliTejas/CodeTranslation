#include <bits/stdc++.h>
using namespace std;

#define fr 1

bool V(unsigned long long a, int i) {
	return ((a & ((unsigned long long)1 << i)) ? 1 : 0);
}

void C(unsigned long long &a, int i) {
	a |= ((unsigned long long)1 << i);
}

const int N = 502;
int n, hope[2][N][64];
bool s[N], t[N];
unsigned long long u[N], v[N], fxd[N][N], fp[N][N];
set<pair<pair<int, bool> , pair<int, int> > > se;

bool del(pair<pair<int, bool>, pair<int, int> > a) {
	set<pair<pair<int, bool> , pair<int, int> > >::iterator it = se.find(a);
	if(it == se.end()) return 0;
	se.erase(it);
	return 1;
}

bool del(bool a, int i, int ii) {
	return del({{hope[a][i][ii], a}, {i, ii}});
}

void dbo(bool a, int i, int ii) {
	if(del(a, i, ii)) {
		--hope[a][i][ii];
		se.insert({{hope[a][i][ii], a}, {i, ii}});
	}
}

bool ru(bool a, int i, int ii) {
	if(a == 0) {
		if(s[i] == 0 && V(u[i], ii) == 0) {
			return 0;
		}
		if(s[i] == 1 && V(u[i], ii) == 1) {
			return 1;
		}
	} else {
		if(t[i] == 0 && V(v[i], ii) == 0) {
			return 0;
		}
		if(t[i] == 1 && V(v[i], ii) == 1) {
			return 1;
		}
	}
	return 0; // must be fixed
}

unsigned long long ao[2][2][N];

bool udr() {
	for(int i = 1; i <= n; ++i) {
		if(ao[s[i]][0][i] != u[i]) return 0;
		if(ao[t[i]][1][i] != v[i]) return 0;
	}
	return 1;
}

void dcm(unsigned long long a) {
	for(int i = 63; i >= 0; --i) {
		cout << V(a, i);
	}
	cout << "\n";
}

bool rd() {
	return (int)rand() % 2;
}

unsigned long long rnd() {
	unsigned long long a = 0;
	for(int i = 63; i >= 0; --i) {
		if(rd()) C(a, i);
	}
	return a;
}

bool gbd;

void cme() {
	if(fr) {
		cout << -1 << endl;
		exit(0);
	} else {
		gbd = 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	//freopen("untitledfile.txt", "r", stdin);
	#ifndef fr
	while(true)
	#endif
	{
	if(fr) {
		cin >> n;
		for(int i = 1; i <= n; ++i) cin >> s[i];
		for(int i = 1; i <= n; ++i) cin >> t[i];
		//cout << "\n";
		for(int i = 1; i <= n; ++i) cin >> u[i]/*, dcm(u[i])*/;
		for(int i = 1; i <= n; ++i) cin >> v[i]/*, dcm(v[i])*/;
	} else {
		n = 500;
		for(int i = 1; i <= n; ++i) s[i] = rd();
		for(int i = 1; i <= n; ++i) t[i] = rd();
		for(int i = 1; i <= n; ++i) u[i] = rnd();
		for(int i = 1; i <= n; ++i) v[i] = rnd();
	}
	gbd = 0;
	se.clear();
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			fxd[i][j] = fp[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int ii = 0; ii < 64; ++ii) {
				if(s[i]) {
					if(V(u[i], ii) == 0) C(fxd[i][j], ii);
				} else {
					if(V(u[i], ii)) C(fxd[i][j], ii), C(fp[i][j], ii);
				}
				///
				if(t[j]) {
					if(V(v[j], ii) == 0) {
						if(V(fxd[i][j], ii) && V(fp[i][j], ii)) {
							cme();
						}
						C(fxd[i][j], ii);
					}
				} else {
					if(V(v[j], ii)) {
						if(V(fxd[i][j], ii) && V(fp[i][j], ii) == 0) {
							cme();
						}
						C(fxd[i][j], ii);
						C(fp[i][j], ii);
					}
				}
			}
		}
	}
	/*cout << "\n";
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cout << fp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;*/
	/////
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			for(int ii = 0; ii < 64; ++ii) {
				if(V(fxd[i][j], ii) == 0) {
					++hope[0][i][ii];
					++hope[1][j][ii];
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int ii = 0; ii < 64; ++ii) {
			if((s[i] == 0 && V(u[i], ii) == 0) || (s[i] == 1 && V(u[i], ii) == 1)) {
				bool bo = 1;
				for(int j = 1; j <= n; ++j) {
					if(ru(0, i, ii) == V(fp[i][j], ii) && V(fxd[i][j], ii) == 1) {
						bo = 0;
						break;
					}
				}
				if(bo) se.insert({{hope[0][i][ii], 0}, {i, ii}});
			}
			///
			if((t[i] == 0 && V(v[i], ii) == 0) || (t[i] == 1 && V(v[i], ii) == 1)) {
				bool bo = 1;
				for(int j = 1; j <= n; ++j) {
					if(ru(1, i, ii) == V(fp[j][i], ii) && V(fxd[j][i], ii) == 1) {
						bo = 0;
						break;
					}
				}
				if(bo) se.insert({{hope[1][i][ii], 1}, {i, ii}});
			}
		}
	}
	while(se.size()) {
		int hp = (*se.begin()).first.first;
		bool rc = (*se.begin()).first.second;
		int i = (*se.begin()).second.first;
		int ii = (*se.begin()).second.second;
		se.erase(se.begin());
		//cout << hp << " " << rc << " " << i << " " << ii << endl;
		if(hp == 0) cme();
		///
		for(int j = 1; j <= n; ++j) {
			if(rc == 0) {
				if(V(fxd[i][j], ii) == 0) {
					C(fxd[i][j], ii);
					if(ru(rc, i, ii) == 1) C(fp[i][j], ii);
					if(ru((rc ^ 1), j, ii) == ru(rc, i, ii)) del((rc ^ 1), j, ii);
					dbo(1, j, ii);
                    break;
				}
			} else {
				if(V(fxd[j][i], ii) == 0) {
					C(fxd[j][i], ii);
					if(ru(rc, i, ii) == 1) C(fp[j][i], ii);
					if(ru((rc ^ 1), j, ii) == ru(rc, i, ii)) del((rc ^ 1), j, ii);
					dbo(0, j, ii);
                    break;
				}
			}
		}
	}
	#ifdef WEEE
	if(fr) cout << "\n";
	for(int i = 1; i <= n; ++i) {
		for(int ii = 0; ii < 64; ++ii) {
			hope[0][i][ii] = hope[1][i][ii] = 0;
		}
		for(int j = 1; j <= n; ++j) {
			if(j == 1) ao[0][0][i] = ao[1][0][i] = fp[i][j];
			else ao[0][0][i] &= fp[i][j], ao[1][0][i] |= fp[i][j];
			if(i == 1) ao[0][1][j] = ao[1][1][j] = fp[i][j];
			else ao[0][1][j] &= fp[i][j], ao[1][1][j] |= fp[i][j];
		}
	}
	if(fr) {
		if(udr()) {
			cout << "BRAVO!" << endl;
		} else {
			cout << "GO FIX THE BUGS!" << endl;
		}
		cout << endl;
	} else {
		if(!gbd && !udr()) {
			cout << n << endl;
			for(int i = 1; i <= n; ++i) cout << s[i] << " ";
			cout << "\n";
			for(int i = 1; i <= n; ++i) cout << t[i] << " ";
			cout << "\n";
			for(int i = 1; i <= n; ++i) cout << u[i] << " ";
			cout << "\n";
			for(int i = 1; i <= n; ++i) cout << v[i] << " ";
			cout << endl;
			return 0;
		}
	}
	#endif
	}
	///
	/*
	cout << "\n";
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			dcm(fp[i][j]);
		}
	}
	cout << endl;
	*/
	///
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cout << fp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << flush;
	return 0;
}
