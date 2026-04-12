#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N;
int X, M;
bool used[100100];

int main() {
    cin >> N >> X >> M;
    ll ans = 0;
    ll x = X;
    vector<int> S;
    while (!used[x]) {
        used[x] = true;
        S.push_back(x);
        x = x * x % M;
    }
    ll sum = 0;
    bool flag = false;
    vector<int> V;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == x) flag = true;
        if (flag) { 
            sum += S[i];
            V.push_back(S[i]);
        } 
        else ans += S[i];
    }
    ll t = N - S.size() + V.size();
    ans += sum * (t / V.size());
    for (int i = 0; i < t % V.size(); i++) ans += V[i];
    cout << ans << endl; 
    return 0;
}