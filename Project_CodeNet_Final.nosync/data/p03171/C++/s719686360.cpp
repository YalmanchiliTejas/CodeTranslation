/*

Coded by peyha X

*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int NMAX=3*1e3+2,FIRST=1,SECOND=2;
const ll AUCUN=-1e15;
int n,a[NMAX];
ll dp[NMAX][NMAX][3];

int autre(int x){
	return (x)%2+1;
}

ll state(int player,int debut,int fin){
	
	int signe=1;
	if(player==SECOND) signe=-1;
	
	if(dp[debut][fin][player]!=AUCUN){
		return dp[debut][fin][player];
	}
	if(debut==fin){
		dp[debut][fin][player]=signe*a[debut];
		return dp[debut][fin][player];
	}
	
	ll premier=signe*a[debut]+state(autre(player),debut+1,fin),deux=signe*a[fin]+state(autre(player),debut,fin-1);
	//cout << player << ' ' << debut << ' ' << fin << ' ' << premier << ' ' << deux << endl;
	if((player==FIRST && premier>deux) ||(player==SECOND && deux>premier)){
		 dp[debut][fin][player]=premier;
	}
	else{
		dp[debut][fin][player]=deux;
	}
	return dp[debut][fin][player];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int id=0;id<=2;id++){
				dp[i][j][id]=AUCUN;
			}
		}
	}
	
	
	cout << state(FIRST,1,n) << '\n';
	
	
	
}
