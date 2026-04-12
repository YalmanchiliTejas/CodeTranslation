#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	
	vector<int> H(N);
	
	for(int i=0;i<N;i++){
		cin >> H[i];
	}
	
	int cnt=1;
	int max = H[0];
	for(int i=0;i<N-1;i++){
		if(max <= H[i+1]){
			cnt++;
			max = H[i+1];
		}
	}
	cout << cnt << endl;
}