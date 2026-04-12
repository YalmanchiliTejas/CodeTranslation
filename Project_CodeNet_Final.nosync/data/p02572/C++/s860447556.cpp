#include<bits/stdc++.h>
#define fo(i,a,b) for(int i= a ; i < b ; ++i)
#define rep(i,n) fo(i,0,n)
#define pln(n) printf("%lld\n",n)
#define sll(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) <<" , "<< #z <<": "<<(z)<<endl; }
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<int>
#define tr(c, it) \
for(decltype(c.begin()) it = c.begin(); it!= c.end(); it++)
#define pis pair<int,string>
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c),x) != c.end())
#define mod (int)(1e9 + 7) 
using namespace std;



int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> s(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n-1; i >= 0; i--){
		if(i +1 < n)s[i] = (s[i+1] + a[i]%mod)%mod;
		else s[i] = a[i];
	}
	int ans = 0;
	for(int i = 0; i < n-1; i++){
		ans = ans + ((ll)a[i] * s[i+1])%mod;
		ans = ans%mod;
	}
	cout << ans;



}
