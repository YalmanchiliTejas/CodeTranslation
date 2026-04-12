// myfirstatcoder.cpp : アプリケーションのエントリ ポイントを定義します。

#include "bits/stdc++.h"
#define rep(i,cc,n) for(int i=cc;i<(n);++i)
#define drep(i,cc,n) for(int i=cc;i>(n);--i)
#define llrep(i,cc,n) for(long long i=cc;i<(n);++i)
using namespace std;
using ll = long long;

int Permutation(int N, vector<int> a, vector<int> b)
{
	int count = 0;

	// one_case = {0,1,2,3,...n-1} とする
	vector<int> node(N);
	iota(node.begin(), node.end(), 0);

	// 頂点と辺の探索 → 辺の元：a[i]  辺の先：b[i]
	vector<vector<int>> list(N, vector<int>(N));
	for (int i = 0;i < a.size();++i)
	{
		--a[i];
		--b[i];
		list[a[i]][b[i]] = 1;
		list[b[i]][a[i]] = 1;
	}

	do // 順列の最後になるまで one_case を並び替えながらループ O(N!)
	{
		int load = 1;
		rep(i,1,N)
			if (list[node[i - 1]][node[i]] == 0)
				load = 0;
		if (load)
			++count;
	} while (next_permutation(node.begin() + 1, node.end()));
	return count;
}

int main()
{
	int N,M;
	cin >> N >> M;
	vector<int> a(M), b(M);
	vector<vector<int>> side(M);
	rep(i, 0, M)
	{
		cin >> a[i] >> b[i];
	}

	cout << Permutation(N,a,b) << endl;
	
	return 0;
}
