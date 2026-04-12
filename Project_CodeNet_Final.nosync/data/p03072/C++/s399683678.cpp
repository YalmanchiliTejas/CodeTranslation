#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, H;
	int Highest = 0;
	int count = 0;
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> H;
		if(Highest <= H){
			Highest = H;
			count++;
		}
	}
	cout << count << endl;
}