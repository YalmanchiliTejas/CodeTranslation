#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;

	int ans = 1, max;
	cin >> max;

	for (int i = 1, temp; i < N; i++){
		cin >> temp;
		if(temp >= max){
			ans++;
			max = temp;
		}
	}

	cout << ans << endl;
	return 0;
}
