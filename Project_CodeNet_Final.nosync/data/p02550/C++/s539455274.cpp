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
	ll n, x, m;
	cin >> n >> x >> m;
	
	//{ll ans = x, sum = 0;
	//for(int i = 0; i < n-1; i++){
		//cout << ans << endl;
		//sum += ans;
		//ans = (ans * ans) % m;
	//}
	
	//cout << ans << endl;
	//sum += ans;
	//cout << ")) " << ' ' << sum << endl;}
	
	vector <ll> sum = {x};
	unordered_map <ll, int> s;
	s[x] = 0;
	
	ll ans = x;
	for(int i = 0; i < n-1; i++){
		ans = (ans * ans) % m;
		if(ans == 0)
			return cout << sum.back() << endl, 0;
		
		if(s.count(ans)){
			//cout << i << endl;
			//cout << ans << endl;
			ll summ = sum.back() - (s[ans]-1 >= 0 ? sum[s[ans] - 1] : 0);
			ll d = (n - 1 - s[ans]) / (len(sum) - s[ans]);
			
			ll res = d * summ;
			res += sum[s[ans] - 1];
			
			res += sum[s[ans] + (n - 1 - s[ans] - d * (len(sum) - s[ans]))];
			res -= sum[s[ans] - 1];
			cout << res << endl;
			return 0;
		}
		
		s[ans] = i+1;
		
		sum.pb(sum.back() + ans);
	}

	cout << sum.back() << endl;
	return 0;
}
