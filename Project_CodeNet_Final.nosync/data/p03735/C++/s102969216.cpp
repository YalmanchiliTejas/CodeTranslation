#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define MAXN 200010
#define LL long long
using namespace std;

int n;
LL v1[MAXN],v2[MAXN];
int s1,s2;

LL gao1(){
	if(s1==s2) return 1LL<<62;
	LL res1=v1[s1]-v2[s2];
	LL lim1=min(v1[s2],v2[s1]),lim2=max(v1[s2],v2[s1]);
	if(n==2) return res1*(lim2-lim1);
	static multiset< pair<LL,int> > S1;
	static multiset<LL> S2;
	static int c[MAXN];
	for(int i=1;i<=n;i++)
		if(i!=s1 && i!=s2){
			c[i]=2;
			S2.insert(v2[i]);
			S1.insert(make_pair(v1[i],i));
			S1.insert(make_pair(v2[i],i));
		}
	LL ans=1LL<<62;
	for(multiset< pair<LL,int> >::iterator it=S1.begin();it!=S1.end();it++){
		LL l1=min(it->first,lim1);
		LL l2=max(*(--S2.end()),lim2);
		if(res1*(l2-l1)<ans) ans=res1*(l2-l1);
		if(c[it->second]==1) break;
		c[it->second]--;
		S2.erase(S2.find(v2[it->second]));
		S2.insert(v1[it->second]);
	}
	return ans;
}

LL gao2(){
	LL l1=v1[s1],l2=v2[s2];
	for(int i=1;i<=n;i++){
		if(v1[i]<l1) l1=v1[i];
		if(v2[i]>l2) l2=v2[i];
	}
	return (v1[s1]-l1)*(l2-v2[s2]);
}

int main(){
#ifdef DEBUG
	freopen("E.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",v1+i,v2+i);
		if(v1[i]<v2[i]) swap(v1[i],v2[i]);
	}
	s1=s2=1;
	for(int i=1;i<=n;i++){
		if(v1[i]>v1[s1]) s1=i;
		if(v2[i]<v2[s2]) s2=i;
	}
	LL res=min(gao1(),gao2());
	printf("%lld\n",res);
	return 0;
}
