// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")



#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define Find order_of_key
// #define at find_by_order
#define x first
#define y second
#define ll long long
#define int long long
#define lll __int128
#define ull unsigned long long
#define ulll unsigned __int128
#define pii pair<int,int>
#define pb push_back
#define eb emplace_back
#define gu getchar_unlocked()
#define pu putchar_unlocked()
#define all(x) x.begin(),x.end()
#define endl '\n'
ll n,x,m;
inline ll f(ll v){
	return (v*v)%m;
}
int arr[100010];
int val[100010];
signed main()
{
	cin>>n>>x>>m;
	ll k=0,st=0;
	ll ans=0;
	val[1]=x;
	arr[x]=1;
	ans+=val[1];
	for(int i=2;i<=m && i<=n;i++){
		val[i]=f(val[i-1]);
		ans+=val[i];
		if(arr[val[i]]!=0){
			k=i-arr[val[i]];
			st=arr[val[i]];
			break;
		}
		arr[val[i]]=i;
	}
	if(st==0){
		cout<<ans<<endl;
		return 0;
	}

	ll ex=(n-st+1)%k;
	ll g=(n-st+1)/k;
	// cout<<st<<' '<<k<<endl;
	// cout<<ex<<' '<<g<<endl;
	ans=0;
	ll an=0;
	for(int i=1;i<st;i++)ans+=val[i];
	for(int i=st,j=0;j<k;j++,i++)an+=val[i];
	ans+=an*g;
	for(int i=st,j=0;j<ex;j++,i++)ans+=val[i];
	cout<<ans<<endl;
	return 0;
}