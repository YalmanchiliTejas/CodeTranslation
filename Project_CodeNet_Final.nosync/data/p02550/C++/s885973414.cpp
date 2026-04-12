#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    LL N, X, M;
    cin >> N >> X >> M;
    vector<bool> V(M), C(M);
    vector<LL> A;
    LL x = X;
    while(true) {
        V[x] = true;
        x = (x * x) % M;
        if(V[x]) {
            break;
        }
    }
    while(true) {
        C[x] = true;
        A.push_back(x);
        x = (x * x) % M;
        if(C[x]) {
            break;
        }
    }
    LL ans = 0;
    while(N) {
        if(C[X]) {
            break;
        }
        ans += X % M;
        X = (X * X) % M;
        --N;
    }
    for(int i = 0; i < int(A.size()); ++i) {
        ans += (N / LL(A.size()) + LL((N % A.size()) > i)) * A[i]; 
    }
    cout << ans << "\n";
    
    return 0;
}
