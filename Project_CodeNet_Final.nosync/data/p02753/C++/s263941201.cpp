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
bool cmp(pair<long double, int > x, pair<long double, int> y){ return x.F<y.F && x.S<y.S; }
const ll maxn=2*1e7+10;
ll __lcm(ll a, ll b){ return (a*b)/__gcd(a,b); }
ll random(ll mn, ll mx){
	return (rand() % (mx - mn + 1)) + mn; 
}
void solve(){
	
	string s;
	cin>>s;
	ll a=0, b=0;
	if (s[0]=='A') a++;
	else b++;
	if (s[1]=='A') a++;
	else b++;
	if (s[2]=='A') a++;
	else b++;
	if (a==3 || b==3) {
		cout<<"No"<<endl;
	}
	else cout<<"Yes"<<endl;
	
	return;
}

int main(){ 
    
    #ifndef ONLINE_JUDGE
  		//freopen("input.txt", "r", stdin);
    #endif
    srand(time(0)); 
    
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	//T{ solve(); }
	solve();
	
	return 0;
}