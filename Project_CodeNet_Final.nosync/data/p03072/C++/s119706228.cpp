#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	rep(i,N){
		cin >> H[i];
	}
	
	int ans = 1;
	int temp = H[0];
	
	rep(i,N-1){
		if(H[i+1] >= temp){
			ans++;
			temp = H[i+1];
		}
	}
	
	cout << ans << endl;
    return 0;
}

