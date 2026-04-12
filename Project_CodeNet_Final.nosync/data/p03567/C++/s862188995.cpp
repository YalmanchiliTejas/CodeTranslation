#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define EPS (1e-7)
#define INF 1e9

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int vx[]={0,1,0,-1};
int vy[]={1,0,-1,0};

int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};

const ll mod=1000000000+7;
const int MAX_N=1000;

int main(){
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i-1]=='A' && s[i]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}