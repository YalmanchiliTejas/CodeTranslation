#include <bits/stdc++.h>
#define endl '\n'
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back
#define ll long long
using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n , k, s= 0;
	cin>>n>>k;
	if(n==k)
	cout<<"Yes";
	else
	cout<<"No";
	
	return 0;
}