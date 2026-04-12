#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef std::vector<vector<int> > vvi;
typedef pair<int, int> pi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
#define inf (ll)1e9

#define debugone(x) cout << #x << " " << x << "\n"; cout.flush();
#define debugtwo(x) cout << #x << "-------------" << "\n";for(auto &it: x) cout << it << " ";cout << "\n"; cout.flush();
#define debugthree(x, i, j) cout << #x << "------------" << "\n";cout << "from " << i << " to " << j << "\n";for(ll k=i; k<=j; k++) cout << x[k] << " ";cout << "\n"; cout.flush();



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	int n;
	cin >> n;
	int cnt = 0;
	int maxi = -1;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		maxi = max(maxi, x);
		if(x == maxi){
			cnt++;
		}
	}

	cout << cnt << endl;

}