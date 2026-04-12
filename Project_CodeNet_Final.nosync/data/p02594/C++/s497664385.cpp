//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

/*
struct Mo {
    using ADD = function< void(int) >;
    using DEL = function< void(int) >;
    using REM = function< void(int) >;

    int width;
    vector< int > left, right, order;
    vector< bool > v;

    Mo(int N, int Q) : width((int)sqrt(N)), order(Q), v(N) {
        iota(begin(order), end(order), 0);
    }

    void add(int l, int r) { // [l, r) 
        left.emplace_back(l);
        right.emplace_back(r);
    }

    int run(const ADD& add, const DEL& del, const REM& rem) {
        assert(left.size() == order.size());
        sort(begin(order), end(order), [&](int a, int b) {
            int ablock = left[a] / width, bblock = left[b] / width;
            if (ablock != bblock) return ablock < bblock;
            if (ablock & 1) return right[a] < right[b];
            return right[a] > right[b];
            });
        int nl = 0, nr = 0;
        auto push = [&](int idx) {
            v[idx].flip();
            if (v[idx]) add(idx);
            else del(idx);
        };
        for (auto idx : order) {
            while (nl > left[idx]) push(--nl);
            while (nr < right[idx]) push(nr++);
            while (nl < left[idx]) push(nl++);
            while (nr > right[idx]) push(--nr);
            rem(idx);
        }
        return 0;
    }
};
int main() {
    int N, Q;
    cin >> N;
    cin >> Q;

    vector< int > A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector< int > f(1000001);
    Mo mo(N, Q);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        mo.add(--l, r);
    }
    int ret = 0;
    auto add = [&](int idx) { if (f[A[idx]]++ == 0) ret++; };
    auto del = [&](int idx) { if (f[A[idx]]-- == 1) --ret; };
    vector< int > ans(Q);
    auto rem = [&](int idx) { ans[idx] = ret; };
    mo.run(add, del, rem);
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}
*/

//4.5 4.5
//3.5 3.5

/*
int N, K;
vector<int> A;

bool isOK(int m) {
    priority_queue<double> q;
    for (int i = 0; i < N; i++) q.push(A[i]);
    for (int i = 0; (i < K) && (q.top() > m); i++) {
        auto top = q.top();
        q.pop();
        q.push(top - m + 1e-9);
        q.push(m - 1e-9);
    }
    return (q.top() <= m);
}

int main() {
    cin >> N >> K;
    A = vector<int>(N);
    for (int i = 0; i < N; i++)cin >> A[i];

    int left = 1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = INF/2; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    // どんな二分探索でもここの書き方を変えずにできる！ 
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        if (isOK(mid)) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
*/


/*

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> A(N+1,0), B(N+1,0);
    for (int i = 0; i < N; i++) {
        A[i + 1] = A[i] + (S[i] == 'W');
        B[i + 1] = B[i] + (S[i] == 'R');
       
    }
    int ans = INF;
    for (int i = 0; i <= N; i++) {
        int t1 = min(A[i] - A[0] , B[N] - B[i]),t2 = max(A[i] - A[0], B[N] - B[i]);
        ans = min(ans, t2);
    }
    cout << ans << endl;


}*/

/*
int main() {
    int K;
    cin >> K;
    ll a = 7 % K;

    for (int i = 0; i < 20000000; i++) {
        if (a == 0) {
            cout << i+1 << endl;
            return 0;
        }
        else {
            a = (a * 10 + 7) % K;
        }
    }
    cout << -1 << endl;
}*/

/*
int main() {
    ll N, D;
    cin >> N >> D;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if (a * a + b * b <= D * D)cnt++;
    }
    cout << cnt << endl;
}*/

int main() {
    int X;
    cin >> X;
    if (X >= 30) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}