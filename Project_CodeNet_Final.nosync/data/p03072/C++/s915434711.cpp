#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(auto &h:H)cin >> h;
	int ans=0,max=0;
	for(int i=0;i<N;i++){
		if(H[i]>=max){
			ans++;
			max=H[i];
		}
	}
	cout << ans << endl;
	return 0;
}