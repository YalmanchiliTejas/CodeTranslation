#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

ll s[200000];
int main(){
	int n;scanf("%d",&n);
	rep(i,n){
		scanf("%lld",&s[i]);
	}
	ll Max=0;
	for(int i=1;i<=n-3;i++){//A-B
		ll s1=0;
		int p=0;
		ll s2=0;
		for(int A=n-1-i;A>0&&A>i;A-=i){//A
			int B=A-i;
			if(A<=B||A<=0||B<=0)continue;
			int need=(n-1-A)/i;
			if(A%(A-B)==0&&A/(A-B)<=need)continue;
			s2+=s[A];
			while(p<need){
				p++;
				s1+=s[p*i];
			}
			Max=max(Max,s1+s2);
		}
	}
	cout<<Max<<endl;
}