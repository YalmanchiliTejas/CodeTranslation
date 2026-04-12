#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;


const int maxn = 1e6 + 5;

ll divceil(ll x, ll y) {
    assert(y);
    return (x+y-1)/y;
}

void print(vector<ll> a) {
    for (ll x: a) cout<<x<<" ";
    cout<<endl;
}

ll n;
vector<ll> a;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n;
    a.resize(n);
    for (int i=0; i<n; i++) {
	cin>>a[i];
    }

    ll iter = 0;

    while (*max_element(a.begin(),a.end()) > n-1) {
	for (int i=0; i<n; i++) {
	    if (a[i] >= n) {
		ll go = a[i]/n;
		a[i] %= n;
		iter += go;
		for (int j=0; j<n; j++) {
		    if (i==j) continue;
		    a[j] += go;
		}
	    }
	}
    }

    cout<<iter<<endl;    
    
    return 0;
}
