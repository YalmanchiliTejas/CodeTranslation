#include <bits/stdc++.h>

#define x first
#define y second

#ifdef ONLINE_JUDGE
#define DEBUG(x)
#else
#define DEBUG(x) cerr << #x << ": " << x << endl;
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int mod=1000000000+7;

int addm(int& a,int b) {return (a+=b)<mod?a:a-=mod;}

template<class T,class U> bool smin(T& a,U b) {return a>b?(a=b,1):0;}
template<class T,class U> bool smax(T& a,U b) {return a<b?(a=b,1):0;}

int n;
deque<int> deq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0;i<n;i++) {
		int a;cin >> a;
		if (i%2) deq.push_back(a);
		else deq.push_front(a);
	}

	if (n%2) {
		for (int i=0;i<n;i++) {
			if (i) cout << ' ';
			cout << deq[i];
		}
	}
	else {
		for (int i=n-1;i>=0;i--) {
			cout << deq[i];
			if (i) cout << ' ';
		}
	}
	cout << endl;
}