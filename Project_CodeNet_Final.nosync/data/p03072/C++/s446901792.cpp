#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1e9+7

int main(){
	int N;
	int M = -1;
	int ans = 0;
	cin >> N;
	int i = 0;
	while(i < N){
		int H;
		cin >> H;
		if(H >= M) ans++;
		M = max(M, H);
		i++;
	}
	cout << ans << endl;
}