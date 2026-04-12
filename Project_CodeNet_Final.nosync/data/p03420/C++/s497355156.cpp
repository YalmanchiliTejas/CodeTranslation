#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
using namespace std;
typedef long double ld;
typedef long long int ll;
const ll INF = (1LL << 63);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
#define rep(i,n) for(int i = 0; i < n;i++)
const int MAX = 1000000010;
const ll MOD = 1000000007;
int st[1010][1010];
int main() {
    ll n, k; cin >> n >> k;
    ll sum = 1LL * n * n;
    if (k == 0) {
        cout << sum << endl;
        return 0;
    }
    for (int b = 1; b <= n; b++) {
        if (b > k) sum -= n / b * k + min(k, n % b + 1) - 1;
        else sum -= n;
    }cout << sum << endl;
}