#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i=0;i<N;i++)	cin >> H.at(i);

	int ans=0;
	for(int i=0;i<N;i++){
		bool flag=true;
		for(int j=0;j<=i;j++){
			if(H.at(i)<H.at(j))	flag=false;
		}
		if(flag)	ans++;
	}
	cout << ans << endl;
	
	return 0;
}
