#include "bits/stdc++.h"
using namespace std;
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename \
//   enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge { c b, e; };
// sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
// sim > auto dud(c* x) -> decltype(cerr << *x, 0);
// sim > char dud(...);
// struct debug {
// #ifdef LOCAL
// ~debug() { cerr << endl; }
// eni(!=) cerr << boolalpha << i; ris; }
// eni(==) ris << range(begin(i), end(i)); }
// sim, class b dor(pair < b, c > d) {
//   ris << "(" << d.first << ", " << d.second << ")";
// }
// sim dor(rge<c> d) {
//   *this << "[";
//   for (auto it = d.b; it != d.e; ++it)
//     *this << ", " + 2 * (it == d.b) << *it;
//   ris << "]";
// }
// #else
// sim dor(const c&) { ris; }
// #endif
// };
// #define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

// using ll = long long;

// const int nax = 2e5 + 5;
// vector<pair<int,int>> intervals[nax];
// const ll INF = 1e18L + 5;

// // add to the prefix
// // give the min of everything

// struct S {
//     ll small, lazy;
//     void merge(const S& a, const S& b) {
//         small = min(a.small, b.small);
//         assert(lazy == 0);
//     }
//     void add(ll x) {
//         small += x;
//         lazy += x;
//     }
// };
// vector<S> tree;

// const int TYPE_ADD = 1, TYPE_MIN = 2;
// void rec(int id, int low, int high, int q_low, int q_high, int type, ll& x) {
//     if(high < q_low || q_high < low) {
//         return;
//     }
//     if(q_low <= low && high <= q_high) {
//         if(type == TYPE_ADD) {
//             tree[id].add(x);
//         }
//         else if(type == TYPE_MIN) {
//             x = min(x, tree[id].small);
//         }
//         else {
//             assert(false);
//         }
//         return;
//     }
//     for(int b : {2 * id, 2 * id + 1}) {
//         tree[b].add(tree[id].lazy);
//     }
//     tree[id].lazy = 0;

//     int last_left = (low + high) / 2;
//     rec(2 * id, low, last_left, q_low, q_high, type, x);
//     rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);

//     tree[id].merge(tree[2*id], tree[2*id+1]);
// }


// int main() {
//     int n, m;
//     scanf("%d%d", &n, &m);
//     ll sum_of_scores = 0;
//     for(int i = 0; i < m; ++i) {
//         int a, b, c;
//         scanf("%d%d%d", &a, &b, &c);
//         intervals[b].emplace_back(a, c);
//         sum_of_scores += c;
//     }
//     ll answer = 0;

//     int base = 1;
//     while(base <= n + 1) {
//         base *= 2;
//     }
//     tree.resize(2 * base, {INF, 0});

//     ll whatever = 0 - INF;
//     rec(1, 0, base - 1, 0, 0, TYPE_ADD, whatever);
//     for(int i = 1; i <= n + 1; ++i) {
//         // I want to put '1' here
//         for(pair<int,int> p : intervals[i-1]) {
//             whatever = p.second;
//             rec(1, 0, base - 1, 0, p.first - 1, TYPE_ADD, whatever);
//         }
//         ll best = INF;
//         rec(1, 0, base - 1, 0, base - 1, TYPE_MIN, best);
//         if(i == n + 1) {
//             answer = best;
//         }
//         whatever = best - INF;
//         rec(1, 0, base - 1, i, i, TYPE_ADD, whatever);
//     }

//     printf("%lld\n", sum_of_scores - answer);
// }

struct interval {
    int l;
    int r;
    int v;
    interval(int l, int r, int v) : l(l), r(r), v(v) {}
    bool is_in(int i) const {
        return l <= i && i <= r;
    }
};



struct S {
    long small, lazy;
    S(long s, long l) : small(s), lazy(l) {}
    void merge(const S& a, const S& b) {
        small = max(a.small, b.small);
        assert(lazy == 0);
    }
    void add(long x) {
        small += x;
        lazy += x;
    }
};
vector<S> tree;

const int TYPE_ADD = 1, TYPE_MAX = 2;
void rec(int id, int low, int high, int q_low, int q_high, int type, long& x) {
    if(high < q_low || q_high < low) {
        return;
    }
    if(q_low <= low && high <= q_high) {
        if(type == TYPE_ADD) {
            tree[id].add(x);
        }
        else if(type == TYPE_MAX) {
            x = max(x, tree[id].small);
        }
        else {
            assert(false);
        }
        return;
    }
    for(int b : {2 * id, 2 * id + 1}) {
        tree[b].add(tree[id].lazy);
    }
    tree[id].lazy = 0;

    int last_left = (low + high) / 2;
    rec(2 * id, low, last_left, q_low, q_high, type, x);
    rec(2 * id + 1, last_left + 1, high, q_low, q_high, type, x);

    tree[id].merge(tree[2*id], tree[2*id+1]);
}

// vector<long long> data, lazy;

// void Add(int node, int b, int e, int l, int r, int val) {
//     if (l > r) return;
//     if (b == l && e == r) {
//         lazy[node] += val;
//         return;
//     }

//     int m = (b + e) / 2;
//     Add(node * 2, b, m, l, min(r, m), val);
//     Add(node * 2 + 1, m + 1, e, max(l, m + 1), r, val);
//     data[node] = max(data[node * 2] + lazy[node * 2],
//                      data[node * 2 + 1] + lazy[node * 2 + 1]);
// }

// long long Get() {
//     return max(0LL, data[1] + lazy[1]);
// }


int main(int argc, char *argv[])
{
    int N, M;
    cin >> N >> M;
    map<int, vector<interval>> left;
    map<int, vector<interval>> right;
    for (int i = 0; i < M; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        //I.emplace_back(l, r, v);
        left[l].emplace_back(l, r, v);
        right[r + 1].emplace_back(l, r, v);
    }
    // auto sum = [&](int i, int j) {
    //     long res = 0;
    //     for (auto inter : I) {
    //         if (inter.is_in(i) && !inter.is_in(j)) {
    //             res += inter.v;
    //         }
    //     }
    //     return res;
    // };
    int base = 1;
    while(base <= N + 1) {
        base *= 2;
    }
    const long INF = 1e18;
    tree.resize(2 * base, {0, 0});
//    segment_tree st(N + 1);
//    vector<long> dp(N + 2, -INF);
    // long tmp = INF;
    // rec(1, 0, base - 1, 0, 0, TYPE_ADD, tmp);
    //dp[0] = 0;
    long res = 0;
    for (int i = 1; i <= N + 1; i++) {
        // for (int j = 0; j < i; j++) {
        //     dp[i] = max(dp[i], dp[j] + sum(i, j));
        // }
        long v = 0;
        for (const auto& inter : left[i]) {
            v += inter.v;
        }
        rec(1, 0, base - 1, 0, i - 1, TYPE_ADD, v);
        for (const auto& inter : right[i]) {
            v = -inter.v;
            rec(1, 0, base - 1, 0, inter.l - 1, TYPE_ADD, v);
        }


//        rec(1, 0, base - 1, 0, i - 1, TYPE_ADD, v);
        v = -INF;
        rec(1, 0, base - 1, 0, i - 1, TYPE_MAX, v);
        res = max(res, v);
        rec(1, 0, base - 1, i, i, TYPE_ADD, v);




        // for (const auto& inter : right[i]) {
        //     v -= inter.v;
        // }
        // rec(1, 0, base - 1, 0, i - 1, TYPE_ADD, v);


        // st.update(0, i - 1, v);

        // st.update(0, i - 1, v);

        // st.update(i, i, st.get_max(0, i - 1));
        // if (i == N + 1) res = st.get_max(0, i - 1);

    }
    cout << res << endl;
    return 0;
}

/*
  for(int i=0;i<m;i++){
		int L,R,a; scanf("%d%d%d",&L,&R,&a);
		query[L].pb(mp(1,mp(R,a)));
		query[R+1].pb(mp(-1,mp(L,a)));
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<query[i].size();j++){
			int ty = query[i][j].fi;
			int za = query[i][j].sc.fi;
			int cs = query[i][j].sc.sc;
			if(ty == 1){
				kaede.update(0,i-1,0,0,s-1,1LL*cs);
			}
			else{
				kaede.update(0,za-1,0,0,s-1,-1LL*cs);
			}
		}
		ll v = kaede.query(0,i-1,0,0,s-1);
		ans = max(ans,v);
		kaede.update(i,i,0,0,s-1,v);
	}
*/


// #include <bits/stdc++.h>
// #define int long long

// using namespace std;

// vector<long long> data, lazy;

// void Add(int node, int b, int e, int l, int r, int val) {
//     if (l > r) return;
//     if (b == l && e == r) {
//         lazy[node] += val;
//         return;
//     }

//     int m = (b + e) / 2;
//     Add(node * 2, b, m, l, min(r, m), val);
//     Add(node * 2 + 1, m + 1, e, max(l, m + 1), r, val);
//     data[node] = max(data[node * 2] + lazy[node * 2],
//                      data[node * 2 + 1] + lazy[node * 2 + 1]);
// }

// long long Get() {
//     return max(0LL, data[1] + lazy[1]);
// }

// int32_t main() {

//     int n, m; cin >> n >> m;
//     lazy.resize(4 * n, 0);
//     data.resize(4 * n, 0);

//     vector<tuple<int, int, int>> segs;
//     for (int i = 0; i < m; ++i) {
//         int l, r, w; cin >> l >> r >> w; --l; --r;
//         segs.emplace_back(r, l, w);
//     }

//     sort(segs.begin(), segs.end());

//     vector<long long> dp(n, 0);


//     int at = 0;
//     for (int i = 0; i < n; ++i) {
//         while (at < m && get<0>(segs[at]) < i) {
//             int l, r, w; tie(r, l, w) = segs[at++];
//             Add(1, 0, n - 1, l, r, w);
//         }
//         Add(1, 0, n - 1, i, i, Get());
//     }
//     while (at < m) {
//         int l, r, w; tie(r, l, w) = segs[at++];
//         Add(1, 0, n - 1, l, r, w);
//     }

//     cout << Get() << endl;


//     return 0;
// }
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<P1>query[200005];
class segtree
{
public:
#define s (1<<18)
    ll seg[s*2];
    ll lazy[s*2];
    void lazy_evaluate(int k)
    	{
    		if(k*2+2>=s*2) return ;
    		lazy[k*2+2]+=lazy[k];
    		lazy[k*2+1]+=lazy[k];
    		seg[k*2+2]+=lazy[k];
    		seg[k*2+1]+=lazy[k];
    		lazy[k]=0;
    	}
    ll update(int beg,int end,int idx,int lb,int ub,ll num)
    	{
    		if(ub<beg||end<lb)
    		{
    			return seg[idx];
    		}
    		if(beg<=lb&&ub<=end)
    		{
    			lazy[idx]+=num;
    			seg[idx]+=num;
    			return seg[idx];
    		}
    		if(lazy[idx])
    		{
    			lazy_evaluate(idx);
    		}
    		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
    	}
    ll query(int beg,int end,int idx,int lb,int ub)
    	{
    		if(ub<beg||end<lb)
    		{
    			return -1000000000000000000LL;
    		}
    		if(beg<=lb&&ub<=end)
    		{
    			return seg[idx];
    		}
    		if(lazy[idx])
    		{
    			lazy_evaluate(idx);
    		}
    		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
    	}
}kaede;
//Kaede Takagaki is my wife!
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int L,R,a; scanf("%d%d%d",&L,&R,&a);
        query[L].pb(mp(1,mp(R,a)));
        query[R+1].pb(mp(-1,mp(L,a)));
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<query[i].size();j++){
            int ty = query[i][j].fi;
            int za = query[i][j].sc.fi;
            int cs = query[i][j].sc.sc;
            if(ty == 1){
                kaede.update(0,i-1,0,0,s-1,1LL*cs);
            }
            else{
                kaede.update(0,za-1,0,0,s-1,-1LL*cs);
            }
        }
        ll v = kaede.query(0,i-1,0,0,s-1);
        ans = max(ans,v);
        kaede.update(i,i,0,0,s-1,v);
    }
    cout<<ans<<endl;
}
*/