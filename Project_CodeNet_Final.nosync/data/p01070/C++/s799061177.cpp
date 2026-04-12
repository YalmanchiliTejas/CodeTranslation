#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

typedef pair<int, int> P;

string S;

int bit[MAX_N+10], bitSize;
void init(int sz) {
	bitSize = sz+1;
	fill(bit, bit+bitSize+1, 0);
}
// [0, i]
int sum(int i) {
	if (i < 0) return 0;
	++i;
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
// [l, r)
int sum(int l, int r) {
	return sum(r-1) - sum(l-1);
}
void add(int i, int x) {
	++i;
	while (i <= bitSize) {
		bit[i] += x;
		i += i & -i;
	}
}

int k;
int sa_rank[MAX_N+1];
int tmp[MAX_N+1];

bool compare_sa(int i, int j) {
	if (sa_rank[i] != sa_rank[j]) return sa_rank[i] < sa_rank[j];
	else {
		int ri = i + k <= S.size() ? sa_rank[i+k] : -1;
		int rj = j + k <= S.size() ? sa_rank[j+k] : -1;
		return ri < rj;
	}
}
void construct_sa(int *sa) {
	for (int i = 0; i <= S.size(); ++i) {
		sa[i] = i;
		sa_rank[i] = i < S.size() ? S[i] : -1;
	}
	for (k = 1; k <= S.size(); k *= 2) {
		sort(sa, sa+S.size()+1, compare_sa);
		tmp[sa[0]] = 0;
		for (int i = 1; i <= S.size(); ++i) {
			tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
		}
		for (int i = 0; i <= S.size(); ++i) {
			sa_rank[i] = tmp[i];
		}
	}
}

struct Query {
	int l, r;
	string s;
};
struct Query2 {
	P p, sa_p;
};

P get_lu(int *sa, string T) {
	int left, right;
	{
		int l = 0, r = S.size()+1;
		for (int t = 0; t < 50; ++t) {
			int m = (l + r) / 2;
			if ( S.compare(sa[m], T.size(), T) < 0 ) {
				l = m;
			}
			else {
				r = m;
			}
		}
		left = r;
	}
	{
		int l = 0, r = S.size()+1;
		for (int t = 0; t < 50; ++t) {
			int m = (l + r) / 2;
			if ( S.compare(sa[m], T.size(), T) <= 0 ) {
				l = m;
			}
			else {
				r = m;
			}
		}
		right = r;
	}
	return P(left, right);
}

int sa[MAX_N+1];
int main() {
	cin >> S;
	int M; cin >> M;
	vector<Query> q;
	for (int i = 0; i < M; ++i) {
		int l, r; cin >> l >> r; ++r;
		string s; cin >> s;
		q.push_back( (Query){l, r, s} );
	}
	construct_sa(sa);
/*
	for (int i = 0; i < S.size()+1; ++i) {
		cout << i << " " << sa[i] << " " << S.substr(sa[i], S.size()-sa[i]) << endl;
	}
*/
	vector<Query2> q2;
	for (int i = 0; i < M; ++i) {
		q2.push_back( (Query2){ P(q[i].l, q[i].r), get_lu(sa, q[i].s) } );
	}
/*
	for (int i = 0; i < M; ++i) {
		cout << q2[i].sa_p.first << " " << q2[i].sa_p.second << endl;
	}
*/
	map<int, vector<int> > el, er;
	for (int i = 0; i < M; ++i) {
		P& p = q2[i].p;
		el[p.first].push_back(i);
		er[p.second-q[i].s.length()+1].push_back(i);
	}
	init(S.size()+1);
	vector<int> rev_sa(S.size()+1, -1);
	for (int i = 0; i < S.size()+1; ++i) {
		rev_sa[sa[i]] = i;
	}
	vector<int> ans(M, 0);
	for (int i = 0; i < S.size()+2; ++i) {
		{
			vector<int>& v = el[i];
			for (int qid : v) {
//				cout << "left: " << i << " " << qid << endl;
				P& p = q2[qid].sa_p;
//				cout << sum(p.first, p.second) << endl;
				ans[qid] -= sum(p.first, p.second);
			}
		}
		{
			vector<int>& v = er[i];
			for (int qid : v) {
//				cout << "right: " << i << " " << qid << endl;
				P& p = q2[qid].sa_p;
//				cout << sum(p.first, p.second) << endl;
				ans[qid] += sum(p.first, p.second);
			}
		}
		if (i < S.size()+1) {
//			cout << "add: " << rev_sa[i] << endl;
			add(rev_sa[i], 1);
		}
	}
	for (int i = 0; i < M; ++i) {
		cout << ans[i] << endl;
	}
}