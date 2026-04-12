#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
#define int long long
template <typename T, typename U>
istream &operator>>(istream &in, pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}
signed main(signed argc, char* argv[]) {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	const int MOD=1e9+7;
	int n,m;
	cin>>n>>m;
	if(n==m)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}