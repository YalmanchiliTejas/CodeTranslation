#include<bits/stdc++.h>

#define INF 1000010000
#define nl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pdd pair<double,double>
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define sz(c) (c).size()
#define rep(i,n) for( int i = 0; i < n; ++i )
#define repi(i,n) for( int i = 1 ; i <= n; ++i )
#define repn(i,n) for( int i = n - 1 ; i >= 0 ; --i )
#define repf(j,i,n) for( int j = i ; j < n ; ++j )
#define die(s) {std::cout << s << nl;}
#define dier(s) {std::cout << s; return 0;}
#define vi vector<int>
typedef long long ll;

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(0); 

	int n;
	cin >> n;
	
	vi a(n);
	
	rep(i , n){
		cin >> a[i];
	}
	
	vi b(n);
	
	int l = 0 , r = n - 1;
	
	repn(i , n){
		if((n - i + 1) & 1){
			b[l] = a[i];
			++l;
		}else{
			b[r] = a[i];
			--r;
		}
	}
	
	reverse(all(b));
	
	rep(i , n){
		cout << b[i] << " ";
	}

	return 0;
}