#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i=0;i<N;i++){
		cin >> H[i];
	}
	int ans = 1;
	for(int i=1;i<N;i++){
		int check = 1;
		for(int j = 0;j<i;j++){
			if(H[j] > H[i]) check=0;
		}
		if(check) ans++;
	}
	cout << ans << endl;
}