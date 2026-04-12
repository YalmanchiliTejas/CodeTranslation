#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
#define infinite 1000000000

int n, lista[200002], memo[200010][4];

int dp_par(int obj, int pulados){
	if(memo[obj][pulados]!=-1) return memo[obj][pulados];
	
	if(obj>n) return memo[obj][pulados]=0;
	if(pulados>=1) return memo[obj][pulados]=dp_par(obj+2, pulados)+lista[obj];
	
	int nao_pula=dp_par(obj+2, pulados)+lista[obj];
	int pula=dp_par(obj+1, pulados+1);
	return memo[obj][pulados]=max(nao_pula, pula);
}

int dp_impar(int obj, int pulados){
	if(memo[obj][pulados]!=-1) return memo[obj][pulados];
	
	if(obj==n and pulados==0) return memo[obj][pulados]=0;
	if(obj>n and pulados==0) return memo[obj][pulados]=-infinite;
	if(obj>n) return memo[obj][pulados]=0;
	if(pulados>=2) return memo[obj][pulados]=dp_impar(obj+2, pulados)+lista[obj];
	
	int nao_pula=dp_impar(obj+2, pulados)+lista[obj];
	int pula=dp_impar(obj+1, pulados+1);
	return memo[obj][pulados]=max(pula, nao_pula);
}

void solve(){
	cin >> n;
	for(int i=1; i<=n; i++) cin >> lista[i];
	for(int i=0; i<=n; i++) for(int j=0; j<4; j++) memo[i][j]=-1;
	if(n%2==0) cout << dp_par(1, 0);
	if(n%2==1) cout << dp_impar(1,0);
}

signed main(){
	solve();
}