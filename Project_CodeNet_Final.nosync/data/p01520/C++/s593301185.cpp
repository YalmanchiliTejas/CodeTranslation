#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; i++)
using namespace std;

int T,E;
int f(int x){
	for(int i = 1 ; x * i <= T+E ; i++){
		if( T-E <= x * i && x * i <= T+E ){
			return 1;
		}
	}
	return 0;
}
int main(){
	int N;
	while(cin >> N >> T >> E){
		rep(i,N){
			int x;
			cin >> x;
			if( f(x) ){
				cout << i + 1 << endl;
				return 0;
			}
		}
		cout << -1 << endl;
	}
}