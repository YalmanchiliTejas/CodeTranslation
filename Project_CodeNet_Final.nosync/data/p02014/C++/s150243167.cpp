#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, P> P3;
typedef pair<P ,P> PP;
constexpr ll MOD = ll(1e9) + 7;
constexpr int IINF = INT_MAX;
constexpr ll LLINF = LLONG_MAX;

struct BIT {
    int N;
    vector<ll> bit;

    void init(int _n){
        N = _n;
        bit.resize(_n+1, 0LL);
    }
    ll getSum(int i) {  // i番目までの要素の和を求める(1-index)
        ll sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
    void add(int i, ll x) {  // i番目の要素にxを加算
        while (i <= N) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

struct SegmentTree {
    int N;
    vector<int> node;
    const int INF = INT_MAX;

    SegmentTree(){}
    SegmentTree(int n_){
        init(n_);
    }
    void init(int siz){
        N = 1;
        while (N < siz) N *= 2;  // 最下段の要素数を2のべき乗にする
        node.resize(2*N-1, INF);
    }
    void build(vector<int> &dat){
        int siz = dat.size();
        init(siz);
        for(int i=0; i<siz; i++){
            node[i+N-1] = dat[i];
        }
        for(int i=N-2; i>=0; i--){  // 最下段に値を入れたあと下から順に更新
            node[i] = min(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int k, int a) {
        k += N - 1; // 最下段最左の節点の番号
        node[k] = a;
        while (k > 0) { //登りながら上の要素を更新
            k = (k-1)/2;
            node[k] = min(node[k*2+1], node[k*2+2]);
        }
    }
    int getMin(int a, int b) {return getMin(a, b, 0, 0, N);}
    int getMin(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return INF;  //[a,b)と[l,r)に共通区間がないならINF
        if (a <= l && r <= b)
            return node[k];  //[a,b)が[l,r)を完全に含むならその節点kの値
        else {
            int vl = getMin(a, b, k*2+1, l, (l+r)/2);
            int vr = getMin(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};

ll n, k;
vector<int> x, pos, ans;
BIT rsq;
SegmentTree rmq;

int main() {
    cin >> n >> k;
    x.resize(n);
    pos.resize(n+1);
    ans.resize(n, -1);
    for(int i=0;i<n;i++){
        cin >> x[i];
        pos[x[i]] = i;
    }
    ll inv = 0;  // 転倒数
    rsq.init(n);
    for(int i=n;i>=1;i--){
        inv += rsq.getSum(pos[i]+1);
        rsq.add(pos[i]+1, 1);
    }
    k = max(0LL, inv - k);
    if(k == 0) ans = x;
    else{
        rmq.build(x);
        for(int i=0;i<n;i++){
            int j = rmq.getMin(0, n);  // 貪欲に最小の数を先頭に持っていく
            while(rsq.getSum(pos[j]) > k){  // 不可能ならばその前方の最小値
                j = rmq.getMin(0, pos[j]);
            }
            ans[i] = j;
            k -= rsq.getSum(pos[j]);
            rsq.add(pos[j]+1, -1);
            rmq.update(pos[j], rmq.INF);
            if(k==0)break;
        }
        for(int i=0,j=0;i<n;i++){
            if(ans[i] < 0){
                while(rmq.getMin(j,j+1)==rmq.INF) j++;
                ans[i] = rmq.getMin(j,j+1);
                rmq.update(j, rmq.INF);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[i] << endl;
    }
    return 0;
}

