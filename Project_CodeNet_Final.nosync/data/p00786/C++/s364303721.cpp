#include "bits/stdc++.h"
using namespace std;
const int SIZE = 299;
struct but{
	vector<shared_ptr<but>>chs;
	char c;
	but(char c_) :chs(), c(c_) {
	}
	pair<int,vector<string>>getst() {
		if (chs.empty()) {
			return make_pair(0,vector<string>(1, string(1, c)));
		}
		else if (chs.size() == 1) {
			auto p = chs[0]->getst();
			auto chst = p.second;
			int chroot = p.first;
			vector<string>nst(chst.size() + 2,string( chst[0].size(),' '));
			for (int i = 0;i<nst.size()-2; ++i) {
				for (int j = 0; j < nst[0].size(); ++j) {
					nst[i][j] = chst[i][j];
				}
			}
			for (int i = nst.size() - 2; i < nst.size(); ++i) {
				for (int j = 0; j < nst[i].size(); ++j) {
					if (j == chroot) {
						if (i == nst.size() - 2) {
							nst[i][j] = '-';
						}
						else {
							nst[i][j] = c;
						}
					}
					else {
						nst[i][j] = ' ';
					}
				}
			}
			return make_pair(chroot, nst);
		}
		else {
			auto p1 = chs[0]->getst();
			auto p2 = chs[1]->getst();
			int chroot1 = p1.first;
			int chroot2 = p2.first;
			auto chst1 = p1.second;
			auto chst2 = p2.second;
			if (chst1.size() < chst2.size()) {
				int n = chst2.size() - chst1.size();
				for (int i = 0; i < n; ++i) {
					chst1.insert(chst1.begin(), string(chst1[0].size(), ' '));
				}
			}
			else if (chst1.size() > chst2.size()) {
				int n = chst1.size() - chst2.size();
				for (int i = 0; i < n; ++i) {
					chst2.insert(chst2.begin(), string(chst2[0].size(), ' '));
				}
			}
			int bet = 0;
			for (int i = 0; i < chst1.size(); ++i) {
				int r=-200, l=-200;
				for (int j = chst1[i].size() - 1; j >=0; --j) {
					if (chst1[i][j] != ' ') {
						r = j - chroot1;
						break;
					}
				}
				for (int j = 0; j < chst2[i].size(); ++j) {
					if (chst2[i][j] != ' ') {
						l = chroot2 - j;
						break;
					}
				}
				bet = max(bet, l + r);
			}
			bet += 2;
			while (1) {
				int loff = bet / 2;
				int roff = (bet + 1) / 2;
				int asize = chroot1 + chst2[0].size() - chroot2;
				vector<string>nst(chst1.size() + 2, string(SIZE, ' '));
				const int center = SIZE/2;
				const int lm = center - loff;
				const int ll = lm - chroot1;
				const int lr = ll + chst1[0].size();
				const int rm = center + roff;
				const int rl = rm - chroot2;
				const int rr = rl + chst2[0].size();
				for (int i = 0; i < nst.size() - 2; ++i) {
					for (int j = ll; j < lr; ++j) {
						nst[i][j] = chst1[i][j - ll];
					}
				}
				bool ok = true;
				for (int i = 0; i < nst.size() - 2; ++i) {
					for (int j = rl; j < rr; ++j) {
						if (chst2[i][j-rl] != ' ') {
							if (i&&nst[i - 1][j]!=' ') {
								ok = false;
							}
							if (nst[i + 1][j]!=' ') {
								ok = false;
							}
						}
					}
				}
				if (!ok) {
					bet++;
					continue;
				}
				for (int i = 0; i < nst.size() - 2; ++i) {
					for (int j = rl; j < rr; ++j) {
						if (nst[i][j] == ' ') {
							nst[i][j] = chst2[i][j - rl];
						}
					}
				}
				for (int i = nst.size() - 2; i < nst.size() - 1; ++i) {
					for (int j = lm; j <= rm; ++j) {
						nst[i][j] = '-';
					}
				}
				nst[nst.size() - 1][center] = c;
				while (1) {
					bool flag = true;
					for (int i = 0; i < nst.size(); ++i) {
						if (nst[i][0] != ' ')flag = false;
					}
					if (!flag)break;
					for (int i = 0; i < nst.size(); ++i) {
						nst[i].erase(nst[i].begin());
					}
				}
				while (1) {
					bool flag = true;
					for (int i = 0; i < nst.size(); ++i) {
						if (nst[i].back() != ' ')flag = false;
					}
					if (!flag)break;
					for (int i = 0; i < nst.size(); ++i) {
						nst[i].pop_back();
					}
				}
				int aa;
				for (int j = 0; j < nst[nst.size() - 1].size(); ++j) {
					if (nst[nst.size() - 1][j] != ' ') {
						aa = j;
						break;
					}
				}
				return make_pair(aa, nst);
			}
		}
	}
};
shared_ptr<but>mkbut(string st,int&a) {
	if (isalpha(st[a])) {
		shared_ptr<but>bt(make_shared<but>(st[a]));
		a++;
		if (st.size() == a || st[a] == ')'||st[a]==',') {
			return bt;
		}
		else if (st[a] == '(') {
			a++;
			shared_ptr<but>ch1(mkbut(st, a));
			bt->chs.push_back(ch1);
			if (st[a] == ')') {
				a++;
				return bt;
			}
			else {
				assert(st[a] == ',');
				a++;
				shared_ptr<but>ch2(mkbut(st, a));
				bt->chs.push_back(ch2);
				assert(st[a] == ')');
				a++;
				return bt;
			}
		}
	}
	else {
		assert(false);
	}
}

void solve(string st) {
	int a = 0;
	shared_ptr<but>head(mkbut(st, a));
	auto p = head->getst();
	for (int i = 0; i < p.second.size(); ++i) {
		while (!p.second[i].empty()&&p.second[i].back() == ' ')p.second[i].pop_back();
		cout << p.second[i] << endl;
	}
}

int main() {
	string nst;
	int num = 1;
	while (1) {
		string st; cin >> st;
		nst += st;
		if (nst.back() == ';') {
			nst.pop_back();
			cout << num << ":" << endl;
			solve(nst);
			num++;
			nst.clear();
		}
		else if (nst.back() == '.') {
			nst.pop_back();
			cout << num << ":" << endl;
			solve(nst);
			num++;
			nst.clear();
			break;
		}
	}
	return 0;
}