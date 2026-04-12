#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<limits>
#include<algorithm>
#include<numeric>
#include<utility>
#include<iomanip>

using ULLI = unsigned long long int;
using LLI = long long int;

using namespace std;

template<class T>
class ModCal{
private:
    const ULLI MAX = 1000000;
    ULLI mod;

    std::vector<T> fac;
    std::vector<T> finv;
    std::vector<T> inv;

    void COMinit() {
        fac.resize(MAX);
        finv.resize(MAX);
        inv.resize(MAX);

        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
public:
    ModCal(ULLI _mod){
        this->mod = _mod;
        ModCal<T>::COMinit();
    }
    ModCal(){
        this->mod = 0;
    }

    T add(T a, T b){
        T tmp;
        tmp = a + b;
        if(mod != 0) tmp %= mod;
        return tmp;
    }

    T sub(T a, T b){
        T tmp;
        tmp = a - b;
        if(mod != 0){
            if(tmp < 0) tmp += mod;
            tmp %= mod;
        }
        return tmp;
    }

    T mul(T a, T b){
        T tmp;
        tmp = a * b;
        if(mod != 0) tmp %= mod;
        return tmp;
    }

    T modinv(T a, T m){
        T b = m, u = 1, v = 0;
        while (b) {
            T t = a / b;
            a -= t * b; std::swap(a, b);
            u -= t * v; std::swap(u, v);
        }
        u %= m;
        if (u < 0) u += m;
        return u;
    }

    T div(T a, T b){
        if(mod == 0){
            return a / b;
        }
        a %= mod;
        T tmp = a * ModCal<T>::modinv(b, mod) % mod;
        return tmp;
    }

    T pow(T a, T b){
        T tmp = 1;
        while(b > 0){
            if(mod != 0){
                if(b & 1) tmp = tmp * a % mod;
                a = a * a % mod;
            }else{
                if(b & 1) tmp *= a;
                a *= a;
            }
            b >>= 1;
        }
        return tmp;
    }

    // 以下の関数はMODを設定しない限り使えない
    // 無理やり使う場合は "ModCal<T> cal(Tの最大値)" でオブジェクトを作る
    T com(T n, T k){
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }

    T fact(T n){
        return fac[n];
    }
};

struct S{
    int A;
    int B;
    double v;

    S(int A, int B){
        this->A = A;
        this->B = B;
    }

    bool operator<(const S &l) const{
        return static_cast<double>(B)/A < static_cast<double>(l.B)/l.A;
    };
};

struct P{
    int x;
    int y;

    P(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int main() {
    int N,M;

    cin >> N >> M;

    cout << ((N==M)?"Yes":"No") << endl;

    return 0;
}
