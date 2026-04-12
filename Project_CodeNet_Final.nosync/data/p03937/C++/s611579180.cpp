#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF (1e9+1)
//#define INF (1LL<<59)

int main(){
	int h,w;
	cin>>h>>w;
	vector<string> v(h);
	rep(i,h)cin>>v[i];
	
	int sum=0;
	rep(i,h)rep(j,w)if(v[i][j]=='#')sum++;
	
	int c=1;
	int x=0,y=0;
	while(x!=w-1||y!=h-1){
		if(y+1<h && v[y+1][x]=='#'){
			y++;
		}
		else if(x+1<w && v[y][x+1]=='#'){
			x++;
		}else{
			cout<<"Impossible"<<endl;
			return 0;
		}
		c++;
	}
	if(c!=sum)cout<<"Impossible"<<endl;
	else cout<<"Possible"<<endl;
}