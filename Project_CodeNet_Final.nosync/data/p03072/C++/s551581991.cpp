#include <iostream>
using namespace std;

int main(){
	int N;
	cin >> N;
	int H[N];
	for(int i = 0; i < N; i++) cin >> H[i];
	int res = 1;
	int j;
	for(int i = 1; i < N; i++){ 
		for(j = i - 1; j > 0; j--)
			if(H[j] > H[i]) break;
		if(j == 0 && H[0] <= H[i]) res++;
	}
	cout << res << endl;
}
