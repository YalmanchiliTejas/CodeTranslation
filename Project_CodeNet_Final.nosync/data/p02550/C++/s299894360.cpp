#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
long long n,ans,tot;
int x,m,y,sz,lft;
int used[N];
vector<int> v;

int main(){
	scanf("%lld%d%d",&n,&x,&m);
	for(y=x;!used[y];y=1ll*y*y%m){
		used[y]=1;
		v.push_back(y);
	}
	sz=int(v.size());
	if(n<=1ll*sz){
		sz=int(n);
		for(int i=0;i<sz;i++) ans+=v[i];
	}else{
		int i;
		for(i=0;i<v.size();i++){
			if(v[i]==y) break;
			ans+=v[i];
		}
		n-=1ll*i;
		sz=int(v.size())-i;
		for(int j=i;j<v.size();j++) tot+=v[j];
		ans+=n/sz*tot;
		lft=int(n%(1ll*sz));
		for(int j=i;j<i+lft;j++) ans+=v[j];
	}
	printf("%lld\n",ans);
	return 0;
}