#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<int(n);i++)
#define FOR(i,n,m) for(int i=n;i<int(m);i++)
#define ALL(v) (v).begin(),(v).end()
#define pb push_back
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
 
int vx[]={0,0,-1,1};
int vy[]={1,-1,0,0};
int dx[]={1,0,-1,1,-1,1,0,-1};
int dy[]={1,1,1,0,0,-1,-1,-1};
 
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a*b/gcd(a,b);}	
 
const ll mod=1e9+7;
const int INF=INT_MAX/2;

int main(){
	string s;
	cin>>s;
	REP(i,2){
		if(s[i]!=s[i+1]){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
 