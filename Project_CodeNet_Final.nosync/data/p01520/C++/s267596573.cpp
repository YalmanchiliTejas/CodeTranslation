#include <iostream>
using namespace std;

int main(){
	int N, T, E, x[101];
	cin >> N >> T >> E;
	for(int i=0 ; i < N ; i++ ){
		cin >> x[i];
	}
	for(int t=T ; t <= T+E ; t++ ){
		for(int i=0 ; i < N ; i++ ){
			if( t % x[i] == 0 ){
				cout << i+1 << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}