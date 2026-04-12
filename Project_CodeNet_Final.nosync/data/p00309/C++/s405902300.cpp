#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
template<unsigned mod>
class modint {
private:
    unsigned x;
public:
    modint() : x(0) {};
    modint(long long x_) : x(x_ >= 0 ? x_ % mod : (mod - (-x_) % mod) % mod) {};
    unsigned get() { return x; }
    bool operator==(const modint& m) const { return x == m.x; }
    bool operator!=(const modint& m) const { return x != m.x; }
    modint& operator+=(const modint& m) { x += m.x; x = (x < mod ? x : x - mod); return *this; }
    modint& operator-=(const modint& m) { x += mod - m.x; x = (x < mod ? x : x - mod); return *this; }
    modint& operator*=(const modint& m) { x = 1ULL * x * m.x % mod; return *this; }
    modint operator+(const modint& m) const { return modint(*this) += m; }
    modint operator-(const modint& m) const { return modint(*this) -= m; }
    modint operator*(const modint& m) const { return modint(*this) *= m; }
    modint pow(unsigned long long b) const {
        modint ans(1), mul(*this);
        while(b > 0) {
            if(b & 1) ans *= mul;
            mul *= mul;
            b >>= 1;
        }
        return ans;
    }
    modint inv() const { return pow(mod - 2); }
};
using mint = modint<1000000007>;
mint determinant(int n, vector<vector<mint> > a) {
    mint ans = 1;
    for(int i = 0; i < n; ++i) {
        int ptr = -1;
        for(int j = i; j < n; ++j) {
            if(a[i][j] != mint(0)) {
                ptr = j;
                break;
            }
        }
        if(ptr == -1) return mint(0);
        if(ptr > i) {
            swap(a[i], a[ptr]);
            ans *= mint(-1);
        }
        mint mul = a[i][i], mulinv = mul.inv();
        ans *= mul;
        for(int j = i; j < n; ++j) {
            a[i][j] *= mulinv;
        }
        for(int j = i + 1; j < n; ++j) {
            mint coeff = a[j][i];
            for(int k = 0; k < n; ++k) {
                a[j][k] -= coeff * a[i][k];
            }
        }
    }
    return ans;
}
int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(M), T(M), D(M);
    for(int i = 0; i < M; ++i) {
        cin >> S[i] >> T[i] >> D[i]; --S[i], --T[i];
    }
    vector<int> sd = D;
    sort(sd.begin(), sd.end());
    sd.erase(unique(sd.begin(), sd.end()), sd.end());
    vector<vector<int> > comps;
    for(int i = 0; i < N; ++i) {
        comps.push_back(vector<int>({ i }));
    }
    int threshold = -1;
    for(int i : sd) {
        vector<vector<int> > sg(N);
        for(int j = 0; j < M; ++j) {
            if(D[j] <= i) {
                sg[S[j]].push_back(T[j]);
                sg[T[j]].push_back(S[j]);
            }
        }
        vector<vector<int> > ncomps;
        vector<bool> vis(N);
        for(int j = 0; j < N; ++j) {
            if(vis[j]) continue;
            queue<int> que;
            que.push(j);
            vis[j] = true;
            vector<int> ncomp;
            while(!que.empty()) {
                int u = que.front(); que.pop();
                ncomp.push_back(u);
                for(int k : sg[u]) {
                    if(!vis[k]) {
                        vis[k] = true;
                        que.push(k);
                    }
                }
            }
            sort(ncomp.begin(), ncomp.end());
            ncomps.push_back(ncomp);
        }
        if(ncomps.size() == 1) {
            threshold = i;
            break;
        }
        comps = ncomps;
    }
    int C = comps.size();
    vector<mint> sub(1 << C);
    for(int i = 1; i < 1 << C; ++i) {
        vector<int> verts;
        for (int j = 0; j < C; ++j) {
            if ((i >> j) & 1) {
                verts.insert(verts.end(), comps[j].begin(), comps[j].end());
            }
        }
        sort(verts.begin(), verts.end());
        int V = verts.size();
        vector<vector<mint> > mat(V, vector<mint>(V));
        for (int j = 0; j < M; ++j) {
            int pa = lower_bound(verts.begin(), verts.end(), S[j]) - verts.begin();
            int pb = lower_bound(verts.begin(), verts.end(), T[j]) - verts.begin();
            if (pa != V && verts[pa] == S[j] && pb != V && verts[pb] == T[j]) {
                mat[pa][pb] = mint(-1);
                mat[pb][pa] = mint(-1);
                mat[pa][pa] += 1;
                mat[pb][pb] += 1;
            }
        }
        vector<vector<mint> > redmat(V - 1, vector<mint>(V - 1));
        for (int j = 0; j < V - 1; ++j) {
            for (int k = 0; k < V - 1; ++k) {
                redmat[j][k] = mat[j][k];
            }
        }
        sub[i] = determinant(V - 1, redmat);
    }
    mint ans = 0;
    for(int i = 1; i < (1 << C) - 1; ++i) {
        ans += sub[i] * sub[(1 << C) - i - 1];
    }
    cout << threshold << ' ' << ans.get() << endl;
    return 0;
}
