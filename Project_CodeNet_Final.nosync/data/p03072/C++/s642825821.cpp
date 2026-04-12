#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i = 0; i < N; i++)
		cin >> H.at(i);
	int max = H.at(0), sum = 0;
	for(int i = 0; i < N; i++){
		if(H.at(i) >= max){
			sum++;
			max = H.at(i);
		}
	}
	cout << sum << endl;
}