#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N, h, sum=0, ans=0;
	vector<int>H;
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> h;
		H.push_back(h);
	}
	for (int i=1; i<N; i++){
		for (int j=0; j<i; j++){
			if(H[j] > H[i]){
				sum += 1;
		}
			}
		if (sum == 0){
			ans += 1;	
		}
		sum = 0;
	}
	ans += 1;
	cout << ans << endl;
	return 0;
}