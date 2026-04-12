//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 5;
void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y;
	cout << min({x * a + y * b, min(x, y) * c * 2 + (x - min(x, y)) * a + (y - min(x, y)) * b, 
	max(x, y) * c * 2});
}
int main(){
	speed;
	int t = 1;
	//cin >> t;
	while(t--) solve();
}