#include<bits/stdc++.h>
#define INF 2000000000
#define int long long int
#define MOD 1000000007
#define pb push_back
#define cin1(n) (cin >> n)
#define cin2(a,b) (cin >> a >> b)
#define cin3(a,b,c) (cin >> a >> b >> c)
#define cout(n) (cout << n << endl)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define fr first 
#define sc second 
#define EPS (1e-10)

using namespace std;

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<pair<int,int>> vpii;
typedef vector<string> vs;
typedef vector<vector<string>> vss;
typedef pair<int,int> pii;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int n,m;
int a,b;
int p,q;


void kuru(vi &d, char str) {
		if (str == 'N') {
			swap(d[0],d[4]);		
			swap(d[0],d[3]);		
			swap(d[0],d[1]);		
		}else if(str == 'W') {
			swap(d[0],d[5]);		
			swap(d[0],d[3]);		
			swap(d[0],d[2]);		
		}else if(str == 'S') {
			swap(d[0],d[1]);		
			swap(d[0],d[3]);		
			swap(d[0],d[4]);		
		}else if(str == 'E') {
			swap(d[0],d[2]);		
			swap(d[0],d[3]);		
			swap(d[0],d[5]);		
		}else if(str == 'R') {
			swap(d[1],d[5]);		
			swap(d[1],d[4]);		
			swap(d[1],d[2]);		
		}else if(str == 'L') {
			swap(d[1],d[2]);		
			swap(d[1],d[4]);		
			swap(d[1],d[5]);		
		}
		return ;
	
}
signed main() {

	while(1) {
	vi dice = {1,2,3,6,5,4};
	cin1(n);
	if (n == 0) break;
	int ans = 1;
	rep(i,0,n) {
		string str; cin1(str);
		kuru(dice,str[0]);
		ans += dice[0];
	}
	cout(ans);
	}
	return 0;
}