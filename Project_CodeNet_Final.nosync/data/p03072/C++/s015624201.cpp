#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define INPUT(X) cin >> X
#define OUTPUT(X) cout << X << endl

using namespace std;

int main(void) {

	int N;
	int X = 0;
	bool flag = true;
	INPUT(N);
	
	vector<int> H(N,0);
	for(int i = 0 ; i < N ; i++)
		INPUT(H[i]);

	for(int i = 0 ; i < N ; i++){
		flag = true;
		for(int j = 0 ; j < i ; j++){
			if(H[j] > H[i]) flag = false;
		}
		if(flag) X++;
	}
	
	OUTPUT(X);

}