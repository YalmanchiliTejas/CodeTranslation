#include "bits/stdc++.h"
#define rep(i, j) for (int i = 0; i < j; i++)
#define srep(i, j, k) for (int i = j; i < k; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using ull = unsigned long long;

ll gcd(ll x, ll y);
int fac(ll n, vector<int> num);

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//�G�X�g���l�X���
vector<ll> estora(vector<ll> num) {
    int sel = 0;
    while (sel < num.size()) {
        int d = num[sel];
        for (int i = 0; i < num.size(); i++) {
            if (num[i] % d == 0 && num[i] != d && d != 1) {
                num.erase(num.begin() + i);
                i--;
            }
        }
        sel++;
    }
    return num;
}

const int INF = 1001001001;

//mint�p�̒萔 (10��9�� + 7)
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) :x((x% mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this; }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint& operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream& operator>>(istream & is, const mint & a) { return is >> a.x; }
ostream& operator<<(ostream & os, const mint & a) { return os << a.x; }

int main() {
    int x;
    string s;
    cin >> x;
    if (x >= 30) {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No";
    return 0;
}

/*���C�u�����ő����*/
//���[�O���b�h�̌ݏ��@
ll gcd(ll x, ll y) {
    ll num[3];
    num[0] = (x > y) ? x : y;
    num[1] = (x <= y) ? x : y;
    num[2] = num[0] % num[1];

    while (num[2]) {
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[0] % num[1];
    }

    return num[1];
}

/*�f��������*/
//���색�C�u����
//i����ɑf���ɂ��Ă����Ȃ��Ƃ��܂��ł��Ȃ�&&�v�Z�ʃ��o�C
//�G�X�g���l�X��⿂őf����U����Ă����K�v�������肻��
int fac(ll n, vector<int> num) {
    ll kazu = n;
    for (int i = 2; i <= sqrt(n); i++) {
        while (1) {
            if (kazu % i != 0) break;

            kazu /= i;
            num[i]++;
        }
    }
    if (kazu == n && n != 1) return 1;
    int ans = 0;
    if (kazu != 1) ans++;
    for (int i = 2; i <= sqrt(n); i++) {
        for (int j = 1; j <= num[i]; j++) {
            num[i] -= j;
            ans++;
        }
    }
    return ans;
}