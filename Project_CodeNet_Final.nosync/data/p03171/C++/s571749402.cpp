#include <bits/stdc++.h>
 
using namespace std;

vector<long long> in(3000);
long long tb[3000][3000][2];
bool valid[3000][3000][2];

long long dp(int i, int j, bool turn){
	if(i == j){
		if(!turn) return in[i];
		else return -in[i];
	}
	
	if(valid[i][j][turn]) return tb[i][j][turn];
	
	valid[i][j][turn] = true;
	if(!turn) return tb[i][j][turn] = max(dp(i+1, j, !turn) + in[i], dp(i, j-1, !turn) + in[j]);
	else return tb[i][j][turn] = min(dp(i+1, j, !turn) - in[i], dp(i, j-1, !turn) - in[j]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> in[i];
	}
	
	cout << dp(0,n-1, 0) << endl;
	
	return 0;
}