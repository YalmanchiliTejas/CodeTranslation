#include <iostream>
using namespace std;
#include <algorithm>

int main() {
	int N;
	
	cin >> N;
	
	int h[N];
	
	for(int i=0; i<N; i++){
		cin >> h[i];
	}
	
	int cnt=1;
	for(int i=1;i<N;i++){
		int f =1;
		for(int j= i-1; j > -1; j--){
			if(h[i] < h[j]){
				f = 0;
				break;
			}
		}
		if(f==1) cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}