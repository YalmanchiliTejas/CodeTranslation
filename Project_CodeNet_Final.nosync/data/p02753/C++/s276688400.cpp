#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cassert>
#include<stack>
#include<fstream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

int main(){
	char c[3];
	rep(i,3)cin>>c[i];
	sort(c,c+3);
	if(c[0]==c[2])cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
