#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	ll N;

	cin >> N;

	ll a[N+1] = {} , dpf[N+1][N+1] = {} , dps[N+1][N+1] = {};
	// dpf[i][j] := [i,j]の区間でゲームを行った際の先攻の人の得点
	// dps[i][j] := [i,j]の区間でゲームを行った際の後攻の人の得点


	for(int i=1 ; i<=N ; i++ ){
		cin >> a[i];
		dpf[i][i] = a[i];
	}

	for(int i=1 ; i<=N ; i++ ){ // i := 幅 -> 幅が小さい区間から決まっていくから
		for(int j=1 ; j+i<=N ; j++ ){ // [j,j+i]の計算

			dpf[j][i+j] = max( dps[j+1][i+j]+a[j] , dps[j][i+j-1]+a[i+j] );
			// 区間[j,i+j]で先攻の人の得点は 
			//( a[j]+区間[j+1,i+j]で後攻の人の得点 )　または　( a[j+i]+区間[j,i+j-1]で後攻の人の得点 )


			dps[j][i+j] = dps[j+1][i+j]+a[j] > dps[j][i+j-1]+a[i+j] ? dpf[j+1][i+j] : dpf[j][i+j-1];
			// 区間[j,i+j]で後攻の人の得点は 
			// 先攻の人がa[j]を取った場合 -> 区間[j+1,i+j]の先攻の人の得点
			// 先攻の人がa[i+j]を取った場合 -> 区間[j,i+j-1]の先攻の人の得点
		}
	}

	cout << dpf[1][N] - dps[1][N] << endl;
	
}