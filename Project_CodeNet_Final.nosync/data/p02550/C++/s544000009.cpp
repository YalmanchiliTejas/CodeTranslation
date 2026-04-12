#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,x,k,i,j,m,ans,cur,res1,res2;
	cin >> n >> x >> m;
	
	vector<long long> p(m,-1),sum(m,0);
	sum[1]=x;
	cur=x; p[x]=1;
	for(i=2; i<=n; i++){
		cur=(cur*cur)%m;
		sum[i]=sum[i-1]+cur;
		if(p[cur]==-1){
			p[cur]=i;
		}else{
			res1=(n-p[cur])/(i-p[cur]);
			res2=(n-p[cur])-(i-p[cur])*res1;
			ans=sum[p[cur]]+res1*(sum[i]-sum[p[cur]])+sum[p[cur]+res2]-sum[p[cur]];
			cout << ans << endl; return 0;
		}
	}
	cout << sum[n] << endl;
	
	
	return 0;
}