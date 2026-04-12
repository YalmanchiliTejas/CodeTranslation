#include <bits/stdc++.h>
using namespace std;
string k;
int d, n;
long long dp[100005][105][2][2];
vector<int>v;
long long md = 1e9 + 7;
long long rec(int x, int y, int z, int cek){
	if(x == n){
		if(y == 0 && cek && z){
//			for(int i = v.size()-1; i >= 0; i--)cout << v[i];
//			cout << endl;
			return z;
		}
		return 0;
	}
	if(dp[x][y][z][cek] != -1)return dp[x][y][z][cek];
	long long ret = 0;
	if(y == 0 && cek == 1)ret++;
	ret %= md;
	int num = k[n-1-x] - '0';
	for(int i = 0; i < 10; i++){
		if(num > i){
//			v.push_back(i);
			ret += rec(x+1, (y+i)%d, 1, i > 0);
			ret %= md;
//			v.pop_back();
		}else
		if(num == i){
//			v.push_back(i);
			ret += rec(x+1, (y+i)%d, z, i > 0);
			ret %= md;
//			v.pop_back();
		}else{
//			v.push_back(i);
			ret += rec(x+1, (y+i)%d, 0, i > 0);
			ret %= md;
//			v.pop_back();
		}
	}
	return dp[x][y][z][cek] = ret;
}
int main(){
	for(int i = 0; i <= 100000; i++)
		for(int j = 0; j <= 100; j++)
			for(int k = 0; k < 2; k++)
				for(int cek = 0; cek < 2; cek++)
					dp[i][j][k][cek] = -1;
	cin >> k >> d;
	n = k.size();
	cout << rec(0,0,1,0);
}