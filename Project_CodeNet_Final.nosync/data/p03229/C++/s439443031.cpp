#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define print(s) cout << s << endl
#define acc(v) accumulate(v.begin(), v.end(), 0)
#define cinv(n,v) rep(i,n) cin >> v[i]
using namespace std;
const int INF = 1e9;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<char> vchar;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
int x_pos[4] = {1,0,-1,0}, y_pos[4] = {0,1,0,-1};
int ctoi(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	return 0;
}

char upper(char c){
	return c-0x20;
}

char lower(char c){
	return c+0x20;
}

void unique_vector(vector<int>& v){
	sort(all(v));
	v.erase(unique(all(v)), v.end());
}

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> mini(n / 2), maxi(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        mini[i] = a[i];
    }
    reverse(a.begin(), a.end());
    for (int i = 0; i < n / 2; ++i) {
        maxi[i] = a[i];
    }
    long long ans = maxi[0] - mini[0];
    for (int i = 1; i < n / 2; ++i) {
        ans += maxi[i - 1] - mini[i];
    }
    for (int i = 1; i < n / 2; ++i) {
        ans += maxi[i] - mini[i - 1];
    }
    if (n % 2 == 1) {
        ans += max(a[n / 2 - 1] - a[n / 2], a[n / 2] - a[n / 2 + 1]);
    }
    cout << ans << endl;
}

