#include<bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
#define d1(x)  cerr << #x << "--> " << x << endl
#define d2(x, y)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<endl
#define d3(x, y,z)  cerr << #x << "--> " << x << " | " << #y << "--> " << y <<" | " << #z << "--> "<< z<< endl
#define vpll vector<pair<ll,ll>>
#define F first
#define S second
#define T ll tt; cin>>tt; while(tt--)
using namespace std;
ll mode=pow(10,9)+7;
bool cmp(pair<long double ,int > x, pair<long double , int> y){ return x.F<y.F; }
const ll MAXN=1e3+5;
ll __lcm(ll a, ll b){ return (a*b)/__gcd(a,b); }
 
int main(){ 
    
//    #ifndef ONLINE_JUDGE
//  		freopen("input.txt", "r", stdin);
//    #endif
    
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	ll a,b;
	cin>>a>>b;
	if (a==b) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}
