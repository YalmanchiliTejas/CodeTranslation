#include<iostream>
#include<string.h>
#include<queue>
#include<map>
#include<vector>
#include <cstdlib>
#include<algorithm>
#include <cstdio>
#include <cctype>
using namespace std;
const long long INF=10000000000000LL;
typedef long long ll;
typedef pair<ll,ll> P;
ll N,M,K=1,C;
ll A,B,W;
ll T,a,b;
ll ans=0;
bool h,o;
//bool D[100005];
char str1[55][55],str2[55][55];
map<string,int> m;
vector<int> v[10];
ll reg(int n,ll S ){
//	cout<<n<<" "<<S<<endl;
	if(S==K)return 1;
	int res=0;
	for(int i=0;i<v[n].size();++i){
		if(!(S>>(v[n][i]-1)&1)){
			res+=reg(v[n][i],S|1<<(v[n][i]-1));
		}
	}
	return res;
}
int main(){
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=0;i<N;++i)K*=2;
	K--;
	cout<<reg(1,1)<<endl;
	return 0;
}
