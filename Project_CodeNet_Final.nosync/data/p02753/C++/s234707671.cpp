#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;
 
#define f first
#define s second
 
#define pb push_back
#define pp pop_back
#define mp make_pair
 
#define sz(x) (int)x.size()
#define sqr(x) ((x) * 1ll * (x))
#define all(x) x.begin(), x.end()
#define clr(a,v) memset(a, v, sizeof(a))
 
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)
#define reflex ios_base::sync_with_stdio(false)
 
#define nl '\n'
#define ioi exit(0);
 
 
#define PI 3.14159265
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N= (int)2e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
//const int mod = 1000000007;
const ll linf = (ll)1e18 + 7;
const ll limit = 2e9;

const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int kx[] = {-1,1,2,2,1,-1,-2,-2};
const int ky[] = {2,2,1,-1,-2,-2,-1,1};
 
//const int mod = 998244353;
 
struct dsu{
	int parent[N];
	int cont;
	void make_set(int n){
		for(int i = 1; i <= n; i++)
			parent[i] = i;
		cont = n;
	}
	
	int find_set(int v){
		if(v == parent[v])
			return v;
		return find_set(parent[v]);
	}
	
	void union_sets(int a, int b){
		a = find_set(a); 
		b = find_set(b);	
		if(a != b){
			parent[b] = a;
			cont--;
		}
	}	
};


//~ map<int,int> h;
//~ int dp[2007];
//~ vector <int> arraySort(vector <int> v) {
	//~ vector<int> ans;
	//~ for(int i = 1; i <= (int)v.size(); i++){
		//~ dp[i] = 1;
	//~ }
	
	//~ for(int i = 1; i <= (int)v.size(); i++){
		//~ for(int j = 1; j < i; j++){
			//~ if(v[j-1] <= v[i-1]){ 
				//~ if(dp[i] < dp[j] + 1){
					//~ dp[i] = dp[j] + 1;
					//~ h[i] = j;
				//~ }
				//~ else if(dp[i] == dp[j] + 1){					
					//~ int index = h[i];
					//~ int val = v[index-1];
					//~ if(v[j-1] < val){
						//~ h[i] = j;
					//~ }
				//~ }
			//~ }
		//~ }
	//~ }
	//~ int index, maxi = 0, minval = inf;
	//~ for(int i = 1; i <= (int)v.size(); i++){
		//~ if(maxi <= dp[i] ){
			//~ maxi = dp[i];
		//~ }
	//~ } 
	
	//~ for(int i = 1; i<= (int)v.size(); i++){
		//~ if(maxi == dp[i]){
			//~ if(minval > v[i-1]){
				//~ minval = v[i-1];
				//~ index = i;
			//~ }
		//~ }
	//~ }
	
	//~ cout<<minval<<" "<<index<<endl;
	
	//~ int next = index;
	
	//~ while(next){
		//~ cout<<next<<" ";
		//~ next = h[next];
	//~ }
	//~ return ans;
//~ }

int v[4];
int main(){
	string s;
	cin>> s;
	bool a = false, b = false;
	for(char c: s){
		if(c == 'A')
			a = true;
		if(c =='B')
			b = true;
	}
	
	if(a && b)
		cout<<"Yes";
	else
		cout<<"No";
		
	
	return 0;
}











