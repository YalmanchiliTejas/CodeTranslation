#include <bits/stdc++.h>

using namespace std;

typedef pair< int,int > PII;
typedef long long int lo;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid (bas+son)/2

const lo MAX = -1000000000000000000; 
const lo MIN = 1000000000000000000; 
const lo inf = 1000000000; 
const lo KOK = 100000; 
const lo LOG = 30; 
const lo li = 100005; 
const lo mod = 1000000007; 

lo n,m,cev,b,a[li],dp[3005][3005][5];
string s;
vector<int> v;

lo f(lo bas,lo son,lo sira){
	if(bas>son){
		return 0;
	}
	if(~dp[bas][son][sira]) return dp[bas][son][sira];
	if(sira==0){
		return dp[bas][son][sira]=max(f(bas+1,son,1)+a[bas],f(bas,son-1,1)+a[son]);
	}
	else{
		return dp[bas][son][sira]=min(f(bas+1,son,0)-a[bas],f(bas,son-1,0)-a[son]);
	}
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	FOR{
		scanf("%lld",&a[i]);
	}
	printf("%lld\n",f(1,n,0));
	return 0;
}
