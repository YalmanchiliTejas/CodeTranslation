#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
typedef vector<ll> VI;
typedef vector<pair<ll,ll> > VII;
typedef map<ll,ll> mll;
typedef pair<ll,ll> pll;
//
#define M 1000000007
#define INF (ll)0x3f3f3f3f3f3f3f3f
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define F first
#define S second
#define itr iterator
#define GO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void fileioe(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	freopen("error.txt","w",stderr);
}

void error_out() { cerr << endl; }
template <typename Head, typename... Tail>
void error_out(Head H, Tail... T) {
  cerr << " " << H;
  error_out(T...);
}
void time_elapsed(){
  cerr<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
}
#ifndef ONLINE_JUDGE
#define error(...) cerr << "[" << #__VA_ARGS__ << "]:", error_out(__VA_ARGS__)
#define fioe() fileioe()
#define time() time_elapsed()
#else
#define error(...) 1
#define fioe() 1
#define time() 1
#endif


//
int main()
{
	GO
	//fioe();
	ll n,m;
	cin>>n>>m;
	if(n==m){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	time();
	return 0;
}