#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main(void){
	int N;
	cin >> N;
	int H[N+1];
	for(int i=1;i<=N;i++) cin >> H[i];
	
	int ans=1;
	for(int i=2;i<=N;i++){
		int count=0;
		for(int j=1;j<=i-1;j++){
			if(H[j]<=H[i]) count++;
		}
		if(count==i-1) ans++;
	}
	cout << ans;
}