#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
//using namespace __gnu_pbds;
#define rep(i,a,b) for(i=(a);i<=(b);i++)
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define maxn 100005
#define inf 1e18
#define boost ios::sync_with_stdio(false);cin.tie(0)
#define fr freopen("source.txt","r",stdin),freopen("output.txt","w",stdout)
#define SET(a,b) memset(a,b,sizeof(a))
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
//template<typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out <<  "(" << a.F << ", " << a.S << ")";
}
 
template<class A> ostream& operator << (ostream& out, const vector<A> &a) {
	out << "[";
	for (auto it = a.begin(); it != a.end(); ++it) {
		if (it != a.begin())
			out << ", ";
		out << *it;
	}
	return out << "]";
}
int main()
{
    boost;
    ll n,i,j,x,t,y;
	string s;
	cin>>s;
	x=y=-1;
	for(auto p:s){
		if(p=='A') x++;
		else y++;
	}
	if(x==-1||y==-1) cout<<"No";
	else cout<<"Yes";
}