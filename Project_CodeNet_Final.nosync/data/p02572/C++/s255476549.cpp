#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mk make_pair
#define all(a) a.begin(), a.end()
#define len(a) (int)a.size()

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int main(){
	int n;
	cin >> n;
	vector <ll> d(n);
	for(int i = 0; i < n; i++)
		cin >> d[i];
		
	ll ans = 0;
	ll mod = 1e9 + 7;
	ll sum = 0;
	for(int i = 1; i < n; i++)
		sum += d[i];
	
	for(int i = 0; i < n-1; i++){
		ans = (ans + ((sum % mod) * d[i]) % mod) % mod;
		sum -= d[i+1];
	}
	
	cout << ans << endl;
	return 0;
}
