#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
#define all(a) (a).begin(),(a).end()
#define sz(x) (int)x.size()
#define max_heap priority_queue<int>
#define min_heap priority_queue<int,vector<int>,greater<int>>
using ll = long long;
#define int long long
#define endl "\n"
#define vi vector<int>
#define pb push_back
#define inp_arr(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define out_arr(a) for(ll i=0;i<a.size();i++)cout<<a[i]<<" ";
#define deb(n) cerr << #n << " = " << n << "\n";
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
ll mypower(ll x,ll n,ll c){
    if(n == 0)
        return 1;
    ll temp = mypower(x,n/2,c)%c;
    if(n%2)
        return (n<0)? (1/x)*temp*temp%c: ((x*temp)%c)*temp%c;
    else
        return temp*temp%c;
}
bool codejam = 0;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	ll n;
	cin>>n;
	n>=30? cout<<"Yes":cout<<"No";
	cout<<endl;
	return 0;
}
