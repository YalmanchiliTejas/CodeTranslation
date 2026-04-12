#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<sstream>
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define lb(v,n) lower_bound(v.begin(),v.end(),n)
#define ub(v,n) upper_bound(v.begin(),v.end(),n)
#define mae(v) max_element(v.begin(),v.end())
#define mie(v) min_element(v.begin(),v.end())
#define INF 0x7FFFFFFF
#define mod 1000000007
typedef long long ll;
////////////////////////////////////////////////////////////

bool f[8][8];
int ans = 0;
int n;
void solve( int now , vector<bool> c , int cnt ){
	
	if( cnt == 0 ){
		ans++;
		ret;
	}
	
	rep(i,0,n){
		if( !c[i] && f[now][i] ){
			vector<bool> tmp = c;
			tmp[i] = 1;
			solve( i , tmp , cnt-1 );
		}
	}


}

int main(){
	int m;
	cin >> n >> m;
	rep(i,0,m){
		int a,b;
		cin >> a >> b;
		a--; b--;
		f[a][b] = 1;
		f[b][a] = 1;
	}
	
	vector<bool> c(n,0);
	c[0] = 1;
	solve( 0 , c , n-1);

	cout << ans << endl;

	ret 0;
}