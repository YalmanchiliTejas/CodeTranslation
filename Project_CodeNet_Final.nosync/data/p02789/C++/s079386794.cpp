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

struct nod{
	int x, y;
	nod(int x_,int y_): x(x_), y(y_){};
};

bool operator<(nod & a, nod & b){
  return a.y < b.y;
}

char tab[207][207];

vector<string> printVertically(string s) {
	for(int i = 0; i < 207; i++){
		for(int j = 0; j < 207; j++)
			tab[i][j] = ' ';
	}
	s += "$";
	vector<string> v;
	int r = 1,c = 1;
	for(int i = 0; i < (int)s.size(); i++){
		
		c = 1;
		while( s[i] != ' ' && s[i] != '$'){
			
			tab[r][c] = s[i];
			i++;
			c++;
			
		}
		r++;
	
	}
	
	for(int i = 1; i < 207; i++){
		string str = "";
		bool flag = false;
		for(int j = 206; j >= 1; j--){
			if(tab[j][i] != ' ')
				flag = true;
			if(flag){
				str+= tab[j][i];
			}
		}
		if(str.size() > 0){
			reverse(str.begin(),str.end());
			v.push_back(str);
		}
		
	}
	
	for(string x: v)
		cout<<x<<"-"<<endl;
	return v;
}
    
int main(){
	
	int n, m; cin>> n >> m;
	if(n == m){
		cout<<"Yes";
	}
	else
		cout<<"No";
	return 0;
}
