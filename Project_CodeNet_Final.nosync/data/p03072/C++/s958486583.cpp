#include<iostream>
using namespace std;

int main(){
	int N;
	cin >> N;

	int unit[N];

	for(int i = 0; i < N; i++){
		cin >> unit[i];
	}
	int ans = 0, min = 0;
	for(int i = 0; i < N; i++){
		min = 0;
		for(int j = 0; j < i; j++){
			if(unit[j] > unit[i]) min = 1;
		}
		if(min == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}
