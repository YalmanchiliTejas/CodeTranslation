#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<(n);i++)
#define all(t) (t).begin(),(t).end()
#define MOD 1000000007
typedef long long ll;
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}else{return 0;}}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}else{return 0;}}
template <class T> inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <class T> inline T LCM(T a,T b){return a*b/GCD(a,b);}

int main(){
	ll n,a[100010];
	cin >> n;
	FOR(i,n)cin >> a[i];
	deque<ll> v;
	v.push_back(a[0]);
	for(int i=1;i<n;i++){
		int p=lower_bound(all(v),a[i])-v.begin();
		if(p==0)v.push_front(a[i]);
		else v[p-1]=a[i];

	}

	cout << v.size() << endl;
}