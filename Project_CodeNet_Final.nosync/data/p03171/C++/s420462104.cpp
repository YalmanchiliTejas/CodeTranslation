#include <bits/stdc++.h>
#define MAXN 3030
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> pll;
pll pd[MAXN][MAXN];
bool vis[MAXN][MAXN];
lli seq[MAXN];
int n;

pll solve(int i, int j, int jog){
	
	if(i == j && jog==1) return pll(seq[i],0);
	if(i==j && jog==2) return pll(0,seq[j]);
	
	if(vis[i][j]) return pd[i][j];
	
	if(jog == 1){
		pll a = solve(i+1,j,2);
		a.first += seq[i];
		pll b = solve(i,j-1,2);
		b.first += seq[j];
		vis[i][j] = 1;
		if(a.first - a.second > b.first - b.second) return pd[i][j] = a;
		else return pd[i][j] = b;
	}else{
		pll a = solve(i+1,j,1);
		a.second += seq[i];
		pll b = solve(i,j-1,1);
		b.second += seq[j];
		vis[i][j] = 1;
		if(a.first - a.second < b.first - b.second) return pd[i][j]= a;
		else return pd[i][j] = b;
	}
	
	
	
}

int main (){
	int i;
	cin >> n;
	
	for(i = 1; i <= n; i++){
		cin >> seq[i];
	}
	
	cout << solve(1,n,1).first - solve(1,n,1).second << endl;
	
	
}
