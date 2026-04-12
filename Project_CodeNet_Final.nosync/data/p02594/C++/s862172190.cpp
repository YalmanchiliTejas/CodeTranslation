//#####   #####   #####   #####   #####   #       #####   #   #//
//#   #   #   #   #       #       #   #   #       #   #   ## ##//
//#####   #####   #####   #       #####   #       #####   # # #//
//##      #   #       #   #       #   #   #       #   #   #   #//
//# #     #   #       #   #       #   #   #       #   #   #   #//
//#  #    #   #       #   #       #   #   #       #   #   #   #//
//#   #   #   #   #####   #####   #   #   #####   #   #   #   #//


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ppb pop_back
#define cs(n) cout<<n<<" "
#define cn(n) cout<<n<<"\n"
#define rep(i,j,k) for(int i=j;i<k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
ll bin(ll a, ll b, ll mod)
{
	if(b==0)
		return 1;
	if(b%2==0)
		return bin((a*a)%mod , b/2 , mod)%mod;
	return ((a%mod)*(bin((a*a)%mod , b/2 , mod)%mod))%mod;
}
void solve()
{
	int x;
	cin>>x;
	if(x>=30){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	fastio;
	int t;
	t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
	return 0;
}