#include"bits/stdc++.h"
using namespace std;
#define LL long long
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define PB push_back
#define MP make_pair
#define MOD 1000000007

int main(){
	int N,H[20];
	cin >> N;
	for(int i=0; i<N; i++) cin >> H[i];

	int ans = 0;
	for(int i=0; i<N; i++){
		bool flg = true;
		for(int j=0; j<i; j++){
			if(H[j] > H[i]) flg = false;
		}
		if(flg) ans++;
	}
	cout << ans << endl;

	return 0;
}
