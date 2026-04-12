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
#define C(i) cin>>i
#define C2(i,j) cin>>i>>j
#define C3(i,j,k) cin>>i>>j>>k
#define C4(i,j,k,m) cin>>i>>j>>k>>m
////////////////////////////////////////////////////////////


int n,m;
const int MAX_N = 8;
vector<vector<bool>> v(MAX_N,vector<bool>(MAX_N,0));
int ans=0;

bool check(vector<bool> &c){
	bool f = true;
	rep(i,0,n)
		if(!c[i])
			f = false;

	ret f;
}

void solve( int now , vector<bool> c){
	if(check(c)){	
		ans++;
		ret;
	}
	
	rep(i,0,n){
		if(v[now][i]){
			if( !c[i] ){
				vector<bool> tmp = c;
				tmp[i] = 1;
				solve( i , tmp );
			}
		}
	}
	
	ret;
}

int main(){
	
	cin >> n >> m;
	rep(i,0,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		v[a][b] = 1;
		v[b][a] = 1;
	}
	
	vector<bool> tmp(n,0);
	tmp[0]=1;
	solve(0,tmp);
	P(ans);
	ret 0;
}