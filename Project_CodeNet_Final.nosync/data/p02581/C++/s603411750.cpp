#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

#define SHORT_MAX 30000

template<typename T>
struct SegmentTree{
private:
    int N;
    vector<T> node;
    function<T(T, T)> F;
    T E;
public:
    void init(int n, function<T(T, T)> f, T e, T def){
        F = f;
        E = e;
        N = 1;
        while(N < n) N = (N<<1);
        node.assign(2*N-1, e);
        for(int i=0; i<n; i++) node[N-1+i] = def;
        for(int i=N-2; i>=0; i--) node[i] = F(node[(i<<1)+1], node[(i<<1)+2]);
    }
    T& operator [](int a){
        return node[N-1+a];
    }
    void update(int a, T x){
        a += N-1;
        node[a] = x;
        while(a > 0){
            a = (a-1)>>1;
            node[a] = F(node[(a<<1)+1], node[(a<<1)+2]);
        }
    }
    T query(int a, int b, int k=0, int l=0, int r=-1){
        if(r == -1) r = N;
        if(b <= l || r <= a) return E;
        if(a <= l && r <= b) return node[k];
        return F(query(a, b, (k<<1)+1, l, (l+r)>>1), query(a, b, (k<<1)+2, (l+r)>>1, r));
    }
};

int N;
short A[6000];

short sdp[6001];
short sum(short i){
    if(i < 3) return 0;
    if(sdp[i] != -1) return sdp[i];
    return sdp[i] = (short)(A[i-1] == A[i-2] && A[i-2] == A[i-3]) + sum(i-3);
}

inline short L(short j){
    short ret = j+1;
    while(ret%3 != 2) ret++;
    return ret;
}

inline short gl(short k){
    if(k%3 == 2) return k+1;
    if(k%3 == 0) return k-1;
    if(k%3 == 1) return k-2;
}

inline short gr(short k){
    if(k%3 == 2) return k+2;
    if(k%3 == 0) return k+1;
    if(k%3 == 1) return k-1;
}

short fdp[6001][2001];
short find(short l, short a){
    if(fdp[l][a] != -1) return fdp[l][a];
    if(l+2 >= 3*N) return SHORT_MAX;
    short cnt = 0;
    if(A[l] == a) cnt++;
    if(A[l+1] == a) cnt++;
    if(A[l+2] == a) cnt++;
    if(cnt < 2) return fdp[l][a] = find(l+3, a);
    else{
        if(A[l] != a) return fdp[l][a] = l;
        if(A[l+1] != a) return fdp[l][a] = l+1;
        if(A[l+2] != a) return fdp[l][a] = l+2;
        return fdp[l][a] = l+2;
    }
}

short f2dp[6001][2001];
short find2(short l, short a){
    if(f2dp[l][a] != -1) return f2dp[l][a];
    if(l >= 3*N) return SHORT_MAX;
    if(A[l] == a) return f2dp[l][a] = l;
    return f2dp[l][a] = find2(l+1, a);
}

short dp[6001][6001];

short solve(short, short);

short dpM[6001];
short solMax(short l){
    if(l == 3*N) return 0;
    if(dpM[l] != -1) return dpM[l];
    return dpM[l] = max(solve(gl(l), gr(l)) + sum(L(gr(l))-3), (int)solMax(l+1));
}

short dpR[6001][6001];
short solRMQ(short i, short l){
    if(l >= 3*N-1) return 0;
    if(dpR[i][l] != -1) return dpR[i][l];
    return dpR[i][l] = max(solve(i, l) + sum(L(l)-3), (int)solRMQ(i, l+1));
}

short solve(short i, short j){
    if(dp[i][j] != -1) return dp[i][j];
    int l = L(j);
    if(l == 3*N-1){
        return (A[i] == A[j] && A[j] == A[3*N-1]);
    }
    if(l > 3*N-1) return 0;

    int ret = 0;

    /*for(int k=l; k<3*N-1; k++){
        ret = max(ret, solve(j, k) + sum(L(k)-3) - sum(l));
        ret = max(ret, solve(i, k) + sum(L(k)-3) - sum(l));
    }*/
    ret = max(ret, solRMQ(j, l) - sum(l));
    ret = max(ret, solRMQ(i, l) - sum(l));
    short I = find(l, A[i]);
    if(I != SHORT_MAX) ret = max(ret, solve(j, I) + sum(L(I)-3) - sum(l) + 1);
    short J = find(l, A[j]);
    if(J != SHORT_MAX) ret = max(ret, solve(i, J) + sum(L(J)-3) - sum(l) + 1);

    /*for(int k=l; k<3*N; k++){
        ret = max(ret, solve(gl(k), gr(k)) + sum(L(gr(k))-3) - sum(l));
    }*/
    ret = max(ret, solMax(l) - sum(l));
    if(A[i] == A[j]){
        short K = find2(l, A[i]);
        if(K != SHORT_MAX) ret = max(ret, solve(gl(K), gr(K)) + sum(L(gr(K))-3) - sum(l) + 1);
    }

    return dp[i][j] = ret;
}

signed main(){
    cin >> N;
    rep(i, 3*N){
        cin >> A[i];
        A[i]--;
    }
    memset(sdp, -1, sizeof(sdp));
    memset(fdp, -1, sizeof(fdp));
    memset(f2dp, -1, sizeof(f2dp));
    memset(dp, -1, sizeof(dp));
    memset(dpM, -1, sizeof(dpM));
    memset(dpR, -1, sizeof(dpR));
    cout << solve(0, 1) << endl;
}