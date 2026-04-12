// $%U%$ $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string n;
int k;

ll memo[102][8][2];
bool memod[102][8][2];
ll f(int p, int kl, bool ma){
	if(!kl)return 1;
	if(p>=(int)n.size())return 0;
	if(memod[p][kl][ma])return memo[p][kl][ma];
	memod[p][kl][ma]=1;
	if(ma){
		if(n[p]!='0')memo[p][kl][ma]=f(p+1,kl-1,1);
		else memo[p][kl][ma]=f(p+1,kl,1);
		if(n[p]>'1')memo[p][kl][ma]+=f(p+1,kl-1,0)*(n[p]-'1');
		if(n[p]!='0')memo[p][kl][ma]+=f(p+1,kl,0);
	} else {
		memo[p][kl][ma]=9*f(p+1,kl-1,0)+f(p+1,kl,0);
	}
	return memo[p][kl][ma];
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	cout<<f(0,k,1)<<endl;
	return 0;
}

