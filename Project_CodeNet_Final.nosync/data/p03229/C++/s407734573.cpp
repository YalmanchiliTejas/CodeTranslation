#include <bits/stdc++.h>

using namespace std;
using ll =long long;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
const ll INF = 1LL << 60;

//Write From this Line

const int mod = 1e9+7;
int main()
{
	int n ;
	cin >> n ;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	SORT(a);
	vector<ll> b(n);
	// > < > < > <で入れていくのと < > < > で入れて行くのをやる。
	int left = 0 , right = n - 1;
	rep(i,n){
		if(i%2==0){
			b[i] = a[left++];
		} else {
			b[i] = a[right--];
		}
	}
	ll ans1 = 0 ;
	rep(i,n-1){
		ans1 +=  abs(b[i] - b[i+1]);
	}
	ans1 = max(ans1,ans1-(abs(b[n-1]-b[n-2]))+(abs(b[n-1] - b[0])));

	left = 0 , right = n - 1;
	rep(i,n){
		if(i%2==0){
			b[i] = a[right--];
		} else {
			b[i] = a[left++];
		}
	}
	ll ans2 = 0 ;
	rep(i,n-1){
		ans2 += abs(b[i] - b[i+1]);
	}
	ans2 = max(ans2,ans2-(abs(b[n-1]-b[n-2]))+(abs(b[n-1] - b[0]))) ;
	cout << max(ans1,ans2) << endl;
}
