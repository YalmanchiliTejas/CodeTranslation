#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 987654321;
const int MOD = (int)1e9+7;
//const long double PI = (acos(-1));
//const long double EPS = 0.0000000001;

const int MAX_N = 100050;
int n;
int a[MAX_N];

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	rep(i,0,n) {
		cin >> a[i];
	}
	multiset<int> s;
	int total = 0;
	rep(i,0,n) {
		if(s.empty()) {
			s.insert(-a[i]);
			total++;
			continue;
		}

		auto it = s.upper_bound(-a[i]);
		if(it == s.end()) {
			s.insert(-a[i]);
			total++;
		} else {
			s.erase(it);
			s.insert(-a[i]);
		}
	}
	cout << total << endl;
	return 0;
}
