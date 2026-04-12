#include<bits/stdc++.h>
#define rep(i, l, r) for(register int i = l; i < r; i++)
#define hrp(i, l, r) for(register int i = l; i <= r; i++)
#define rev(i, r, l) for(register int i = r; i >= l; i--)
#define pb push_back
#define int ll
#ifndef JOEON
#define D(...)
#define R(x, l)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename tn> inline tn next(void);
template<typename tn> inline ostream& operator << (ostream& os, const vector<tn>& v);
signed main(void)
{
	#ifdef JOEON
//		freopen("C:\\Users\\Joeon\\Desktop\\IN.txt", "r", stdin);
//		freopen("C:\\Users\\Joeon\\Desktop\\OUT.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin>>a>>b>>c;
	if (!((a*100+b*10+c)%4)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
template<typename tn> inline tn next(void)
{
	tn k;
	cin>>k;
	return k;
}
template<typename tn> inline ostream& operator << (ostream& os, const vector<tn>& v)
{
	rep(i, 0, v.size()) os<<v[i]<<' ';
	return os;
}
