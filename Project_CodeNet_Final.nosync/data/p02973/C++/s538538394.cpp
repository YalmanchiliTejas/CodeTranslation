#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(v,a,b) for(int v=(a); v<=(b); v++)
#define fr(v,a,b) for(int v=(a); v>=(b); v--)
#define rng(v,a,b) for(int v=(a); v<(b); v++)

using namespace std;
typedef long long ll;
template<typename T> T& chmax(T& a, T b) { a = a > b ? a : b; return a;}
template<typename T> T& chmin(T& a, T b) { a = a < b ? a : b; return a;}
const int maxn=1e5+5;
int a[maxn];
int b[maxn],len;
int lb(int x)
{
	int l = 1, r = len, mid, ans = 1;
	while(l<=r) {
		mid = (l+r)>>1;
		if(b[mid] > x) {
			r = mid-1; ans = mid;
		} else {
			l = mid+1; 
		}
	}
	return ans;
}
int main()
{
	int n; cin >> n;
	fo(i,1,n) cin >> a[i];
	b[++len] = a[n];
	fr(i,n-1,1) {
		if(a[i] >= b[len]) {
			b[++len] = a[i];
		} else {
			b[lb(a[i])] = a[i];
		}
	}
	cout << len << '\n';
	return 0;
}
