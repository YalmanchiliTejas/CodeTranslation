#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int INF = -1e9;

struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        //ここでminを使うことで区間の最小値となる、最大にすれば最大値
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

//x番目(0-indexed)の要素をvalにする
void update(int x, int val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
        x = (x - 1) / 2;
        //ここでminを使うことで区間の最小値となる、最大にすれば最大値
        node[x] = max(node[2*x+1], node[2*x+2]);
    }
}

// 要求区間 [a, b) 中の要素の最大値を答える(つまりbは含まれない)
// k := 自分がいるノードのインデックス
// 対象区間は [l, r) にあたる

int getmax(int a, int b, int k = 0, int l = 0, int r = - 1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す(今回は最小値なので、結果に影響しないような大きい値を返しておく)
    if(r <= a || b <= l) return INF;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    int vl = getmax(a, b, 2*k+1, l, (l+r)/2);//部分だった場合、
    int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
    return max(vl, vr);
}

// 要求区間 [a, b) 中の要素の最大値を答える(つまりbは含まれない)
// k := 自分がいるノードのインデックス
// 対象区間は [l, r) にあたる

int getleft(int a, int val, int k = 0, int l = 0, int r = - 1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す(今回は最小値なので、結果に影響しないような大きい値を返しておく)
    if(r <= a || n <= l) return INF;

    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= n){
      if (k >= n - 1)
        return ((node[k] >= val) ? k - n + 2 : INF);
      if (getmax(a, n, 2*k+1, l, (l+r)/2) >= val)
        return (getleft(a, val, 2*k+1, l, (l+r)/2));
      if (getmax(a, n, 2*k+2, (l+r)/2, r) >= val)
        return (getleft(a, val, 2*k+2, (l+r)/2, r));
    }

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    int vl = INF, vr = INF;
    if (getmax(a, n, 2*k+1, l, (l+r)/2) >= val)
      vl = getleft(a, val, 2*k+1, l, (l+r)/2);
    if (getmax(a, n, 2*k+2, (l+r)/2, r) >= val)
      vr = getleft(a, val, 2*k+2, (l+r)/2, r);
    if (vl != INF)
        return (vl);
    if (vr != INF)
        return (vr);
    return (INF);
}
};

int	main(void)
{
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	SegmentTree seg(a);
	for (int i = 0; i < q; i++)
	{
		int t, x, v;
		cin >> t >> x >> v;
		if (t == 1) seg.update(x - 1, v);
		else if (t == 2) cout << seg.getmax(x - 1, v) << endl;
		else 
		{
			int ans = seg.getleft(x - 1, v);
			cout << ((ans == INF) ? n + 1 : ans) << endl;
		}
	}
	return (0);
}
