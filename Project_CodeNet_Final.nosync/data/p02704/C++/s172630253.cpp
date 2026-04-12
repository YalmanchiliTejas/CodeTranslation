#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

template <i64 p>
class fp {
    public:
    i64 x;
    fp() : x(0) {}
    fp(i64 x_) : x((x_ % p + p) % p) {}
    fp operator+() const { return fp(x); }
    fp operator-() const { return fp(-x); }
    fp& operator+=(const fp& y) {
        x += y.x;
        if (x >= p) x -= p;
        return *this;
    }
    fp& operator-=(const fp& y) { return *this += -y; }
    fp& operator*=(const fp& y) {
        x = x * y.x % p;
        return *this;
    }
    fp& operator/=(const fp& y) { return *this *= fp(inverse(y.x)); }
    fp operator+(const fp& y) const { return fp(x) += y; }
    fp operator-(const fp& y) const { return fp(x) -= y; }
    fp operator*(const fp& y) const { return fp(x) *= y; }
    fp operator/(const fp& y) const { return fp(x) /= y; }
    bool operator==(const fp& y) const { return x == y.x; }
    bool operator!=(const fp& y) const { return !(*this == y); }
    i64 extgcd(i64 a, i64 b, i64& x, i64& y) {
        i64 d = a;
        if (b != 0) {
            d = extgcd(b, a % b, y, x);
            y -= (a / b) * x;
        } else {
            x = 1;
            y = 0;
        }
        return d;
    }
    i64 inverse(i64 a) {
        i64 x, y;
        extgcd(a, p, x, y);
        return (x % p + p) % p;
    }
};

template <i64 p>
i64 abs(const fp<p>& x) { return x.x; }

template <i64 p>
istream& operator>>(istream& is, fp<p>& x) {
    is >> x.x;
    return is;
}

template <i64 p>
ostream& operator<<(ostream& os, const fp<p>& x) {
    os << x.x;
    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (const auto& v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

template <typename T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename A, typename T, size_t size>
void fill(A (&ary)[size], const T& val) {
    fill((T*)ary, (T*)(ary + size), val);
}

constexpr int inf = 1.01e9;
constexpr i64 inf64 = 4.01e18;
constexpr long double eps = 1e-9;

// double(64bit浮動小数)のn分探索のループ回数の上限(2分探索なら50でも十分かもしれない). long double(80ビットの x87 浮動小数点型?)だと, 2分探索であってもこれだと足りないケースがある気がするので, もうちょっと余裕を持たせた方が良さそう.
constexpr i64 max_loop = 100;

void no_answer(){
    cout << -1 << endl;
    exit(0);
}

void solve() {
    //constexpr i64 mod = 1'000'000'007;
    using u64=uint64_t;
    i64 N;
    cin >> N;
    vector<u64> S(N),T(N),U(N),V(N);
    rep(i,0,N) cin >> S[i];
    rep(i,0,N) cin >> T[i];
    rep(i,0,N) cin >> U[i];
    rep(i,0,N) cin >> V[i];

    auto get=[&](u64 b,u64 i){
        return (b>>i)&1;
    };

    vector<vector<u64>> ans(N,vector<u64>(N));
    for(u64 b=0; b<64; ++b){
        vector<u64> u(N),v(N);
        rep(i,0,N) u[i]=get(U[i],b);
        rep(i,0,N) v[i]=get(V[i],b);

        vector<vector<bool>> dec(N,vector<bool>(N));
        vector<vector<u64>> a(N,vector<u64>(N));
        rep(i,0,N){
            // (AND, 1)
            if(S[i]==0 and u[i]==1){
                rep(j,0,N){
                    dec[i][j]=true;
                    a[i][j]=1;
                }
            }
            // (OR, 0)
            if(S[i]==1 and u[i]==0){
                rep(j,0,N){
                    dec[i][j]=true;
                    a[i][j]=0;
                }
            }
        }
        rep(j,0,N){
            // (AND, 1)
            if(T[j]==0 and v[j]==1){
                rep(i,0,N){
                    if(dec[i][j]){
                        if(a[i][j]!=1){
                            no_answer();
                        }
                    }else {
                        dec[i][j] = true;
                        a[i][j] = 1;
                    }
                }
            }
            // (OR, 0)
            if(T[j]==1 and v[j]==0){
                rep(i,0,N){
                    if(dec[i][j]){
                        if(a[i][j]!=0){
                            no_answer();
                        }
                    }else {
                        dec[i][j] = true;
                        a[i][j] = 0;
                    }
                }
            }
        }

        deque<u64> and0,or1,fre;
        rep(j,0,N){
            if(T[j]==0 and v[j]==0){
                bool ok=false;
                rep(i,0,N){
                    if(dec[i][j] and a[i][j]==0){
                        ok=true;
                        break;
                    }
                }
                if(!ok) and0.emplace_back(j);
                else fre.emplace_back(j);
            }
            if(T[j]==1 and v[j]==1){
                bool ok=false;
                rep(i,0,N){
                    if(dec[i][j] and a[i][j]==1){
                        ok=true;
                        break;
                    }
                }
                if(!ok) or1.emplace_back(j);
                else fre.emplace_back(j);
            }
        }
        rep(i,0,N){
            // (AND, 0)
            if(S[i]==0 and u[i]==0){
                bool ok=false;
                rep(j,0,N){
                    if(dec[i][j] and a[i][j]==0){
                        ok=true;
                        break;
                    }
                }
                if(ok) continue;

                if(fre.size()>0) {
                    i64 j = fre.front();
                    dec[i][j] = true;
                    a[i][j] = 0;
                }else if(and0.size()>0){
                    i64 j=and0.back();
                    and0.pop_back();
                    fre.emplace_back(j);
                    dec[i][j]=true;
                    a[i][j]=0;
                }else if(or1.size()>0){
                    i64 j=or1.back();
                    or1.pop_back();
                    or1.push_front(j);
                    dec[i][j]=true;
                    a[i][j]=0;
                }else{
                    no_answer();
                }
            }

            // (OR, 1)
            if(S[i]==1 and u[i]==1){
                bool ok=false;
                rep(j,0,N){
                    if(dec[i][j] and a[i][j]==1){
                        ok=true;
                        break;
                    }
                }
                if(ok) continue;

                if(fre.size()>0) {
                    i64 j = fre.front();
                    dec[i][j] = true;
                    a[i][j] = 1;
                }else if(or1.size()>0){
                    i64 j=or1.back();
                    fre.emplace_back(j);
                    dec[i][j]=true;
                    a[i][j]=1;
                }else if(and0.size()>0){
                    i64 j=and0.back();
                    and0.pop_back();
                    and0.push_front(j);
                    dec[i][j]=true;
                    a[i][j]=1;
                }else{
                    no_answer();
                }
            }
        }
        for(i64 j:and0){
            bool ok=false;
            rep(i,0,N){
                if(dec[i][j]){
                    if(a[i][j]==0){
                        ok=true;
                        break;
                    }
                }else{
                    ok=true;
                    dec[i][j]=true;
                    a[i][j]=0;
                    break;
                }
            }
            if(!ok){
                no_answer();
            }
        }
        for(i64 j:or1){
            bool ok=false;
            rep(i,0,N){
                if(dec[i][j]){
                    if(a[i][j]==1){
                        ok=true;
                        break;
                    }
                }else{
                    ok=true;
                    dec[i][j]=true;
                    a[i][j]=1;
                    break;
                }
            }
            if(!ok){
                no_answer();
            }
        }

        rep(i,0,N) rep(j,0,N) ans[i][j]|=(a[i][j]<<b);

        rep(i,0,N){
            u64 or_=0,and_=1;
            rep(j,0,N){
                or_|=a[i][j];
                and_&=a[i][j];
            }
            if(S[i]==0 and u[i]!=and_){
                assert(false);
            }
            if(S[i]==1 and u[i]!=or_){
                assert(false);
            }
        }
        rep(j,0,N){
            u64 or_=0,and_=1;
            rep(i,0,N){
                or_|=a[i][j];
                and_&=a[i][j];
            }
            if(T[j]==0 and v[j]!=and_){
                assert(false);
            }
            if(T[j]==1 and v[j]!=or_){
                assert(false);
            }
        }
    }

    rep(i,0,N){
        rep(j,0,N){
            cout << ans[i][j];
            if(j==N-1) cout << endl;
            else cout << " ";
        }
    }
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
