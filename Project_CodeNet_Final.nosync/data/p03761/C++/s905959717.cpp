#include <bits/stdc++.h>

using namespace std;

#define INF 1000007
#define MOD 1000000007
#define int long long
#define maxn 100
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) FOR(i, 0, n)

typedef std::pair<int, int> P;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int mpow(int N, int P, int M) //繰り返し自乗法
{
    if (P == 0)
        return 1;
    if (P % 2 == 0) {
        int t = mpow(N, P / 2, M);
        return t * t % M;
    }
    return N * mpow(N, P - 1, M) % M;
}

int counter(int x) //bit計算
{
    if (x == 0)
        return 0;
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

bool IsPrime(int num) //素数判定
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> divisor(int n) //約数列挙
{
    vector<int> ret;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i - 1);
            if (i * i != n) {
                ret.push_back((n / i) - 1);
            }
        }
    }
    sort(ret.begin(), ret.end());
    return (ret);
}

signed main() {
    int n;
    cin >> n;
    vector<string> S;
    rep(i, n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        S.push_back(s);
    }
    string ch = S[0];
    rep(i, n - 1) {
        string ans = "";
        int start, end;
        start = end = 0;
        while (true) {
            if (ch[start] != S[i + 1][end]) {
                if ((ch[start] - 'a') > (S[i + 1][end] - 'a')) {
                    end++;
                } else {
                    start++;
                }
            } else {
                ans += ch[start];
                start++;
                end++;
            }
            if (start == ch.length()) {
                break;
            }
            if (end == S[i + 1].length()) {
                break;
            }
        }
        ch = ans;
        if (ch.empty()) {
            cout << "" << endl;
            return 0;
        }
    }
    cout << ch << endl;
}
