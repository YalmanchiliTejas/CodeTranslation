#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;
#ifndef MOD_INT
#define MOD_INT
template<int mod>
struct ModInt{
  private:
    int x;

  public:
    ModInt() : x(0){}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod){}
  
    ModInt &operator+=(const ModInt &p){
      if((x += p.x) >= mod) x -= mod;
      return *this;
    }
    ModInt &operator-=(const ModInt &p){
      if((x += mod - p.x) >= mod) x -= mod;
      return *this;
    }
    ModInt &operator*=(const ModInt &p){
      x = (int) (1LL * x * p.x % mod);
      return *this;
    }
    ModInt &operator/=(const ModInt &p){
      *this *= p.inverse();
      return *this;
    }
  
    ModInt operator-() const {return ModInt(-x);}
    ModInt operator+(const ModInt &p) const {return ModInt(*this) += p;}
    ModInt operator-(const ModInt &p) const {return ModInt(*this) -= p;}
    ModInt operator*(const ModInt &p) const {return ModInt(*this) *= p;}
    ModInt operator/(const ModInt &p) const {return ModInt(*this) /= p;}
    bool operator==(const ModInt &p) const {return x == p.x;}
    bool operator!=(const ModInt &p) const {return x != p.x;}
	bool operator<(const ModInt &p) const {return x < p.x;}
  
    template<typename T>
    operator T() const {return (T)x;}
  
    ModInt inverse() const {
      int a = x, b = mod, u = 1, v = 0, t;
      while(b > 0) {
        t = a / b;
        swap(a -= t * b, b);
        swap(u -= t * v, v);
      }
      return ModInt(u);
    }
  
    ModInt pow(int64_t n) const {
      ModInt ret(1), mul(x);
      while(n > 0) {
        if(n & 1) ret *= mul;
        mul *= mul;
        n >>= 1;
      }
      return ret;
    }
  
    friend ostream &operator<<(ostream &os, const ModInt &p){
      return os << p.x;
    }
  
    friend istream &operator>>(istream &is, ModInt &a){
      int64_t t;
      is >> t;
      a = ModInt< mod >(t);
      return (is);
    }
  
    static int get_mod(){return mod;}
};

using mint = ModInt<MOD>;
#endif

class Factorial{
    private:
        int max;
        vector<mint> fact, ifact;

        void resize(int n){
            if(n <= max) return;

            fact.resize(n+1);
            ifact.resize(n+1);
            for(int i = max + 1; i <= n; i++) fact[i] = fact[i-1] * i;
            ifact[n] = fact[n].inverse();
            for(int i = n; i >= max + 1; i--) ifact[i-1] = ifact[i] * i;
            max = n;
        }

    public:
        Factorial(int N = 0):max(N), fact(N+1), ifact(N+1){
            fact[0] = 1;
            for(int i = 1; i <= N; i++) fact[i] = fact[i-1] * i;
            ifact[N] = fact[N].inverse();
            for(int i = N; i >= 1; i--) ifact[i-1] = ifact[i] * i;
        }

        mint operator()(int n){
            if(n > max) this -> resize(n);

            return fact[n];
        }

        mint inverse(int n){
            if(n > max) this -> resize(n);

            return ifact[n];
        }

        mint combination(int n, int k){
            if(n < 0 or k < 0 or n < k) return 0;
            if(n > max) this -> resize(n);

            return fact[n]*ifact[k]*ifact[n-k];
        }

        mint permutation(int n, int k){
            if(n < 0 or k < 0 or n < k) return 0;
            if(n > max) this -> resize(n);

            return fact[n]*ifact[n-k];
        }

        mint hcombination(int n, int k){
            if(n < 0 or k < 0) return 0;
            if(n == 0 and k == 0) return 1;
            return this -> combination(n+k-1, k);
        }
};

int main(void){
	mint N, M, K;
	cin >> N >> M >> K;

	Factorial fact;
	mint res = 0;
	for(mint d = 0; d < N; d+=1){
		res += d * (N-d) * M * M * fact.combination(N*M-2, K-2);
	}
	for(mint d = 0; d < M; d+=1){
		res += d * (M-d) * N * N * fact.combination(N*M-2, K-2);
	}

	cout << res << '\n';

	return 0;
}