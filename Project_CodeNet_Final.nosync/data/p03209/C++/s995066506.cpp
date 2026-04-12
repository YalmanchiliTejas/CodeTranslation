#include <bits/stdc++.h>

using namespace std;

#define INF 1000007
#define MOD 1000000007
#define int long long int
#define maxn 100
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int mpow(int N, int P, int M)  //繰り返し自乗法
{
    if (P == 0)
        return 1;
    if (P % 2 == 0) {
        int t = mpow(N, P / 2, M);
        return t * t % M;
    }
    return N * mpow(N, P - 1, M) % M;
}

int counter(int x) {           //bit計算
    if (x == 0) return 0;
    return counter(x >> 1) + (x & 1);
}

vector<bool> prime(maxn + 1, true); //素数テーブル
void prime_table(void) {
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= maxn; i++) {
        if (!prime[i]) {
            continue;
        }
        for (int j = i + i; j <= maxn; j += j + i) {
            prime[j] = false;
        }
    }
}

bool IsPrime(int num) {   //素数判定
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


int all[51], p[51];

int ans(int N, int X) {
    if (N == 0)
        return ((X <= 0) ? 0 : 1);
    else if (X <= 1 + all[N - 1])
        return ans(N - 1, X - 1);
    else
        return p[N - 1] + 1 + ans(N - 1, X - 2 - all[N - 1]);

}

signed main() {
    int N, X;
    cin >> N >> X;
    all[0] = 1;
    p[0] = 1;
    for (int i = 1; i <= 50; i++) {
        p[i] = p[i - 1] * 2 + 1;
        all[i] = all[i - 1] * 2 + 3;
    }
    cout << ans(N, X) << endl;
}
