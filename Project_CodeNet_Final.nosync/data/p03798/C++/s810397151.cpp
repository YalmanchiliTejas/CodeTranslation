#include <iostream>
using namespace std;
#define M 100009

int N;
string s;
char ox[M];
char sw[M];

char inv(char c){
	return c == 'S' ? 'W' : 'S';
}
int main(){
	cin >> N >> s;
	for(int i=0; i<N; i++){
		ox[i] = s.at(i);
	}
	ox[N] = ox[0];
	ox[N+1] = ox[1];
	char init[2][4] = {
		{'S', 'S', 'W', 'W'},
		{'S', 'W', 'S', 'W'}
	};
	for(int I=0; I<4; I++){
		sw[0] = init[0][I];
		sw[1] = init[1][I];
		for(int i=2; i<=N+1; i++){
			sw[i] = (sw[i-1] == 'S')?(
					ox[i-1] == 'o' ? sw[i-2] : inv(sw[i-2])
				):(
					ox[i-1] == 'o' ? inv(sw[i-2]) : sw[i-2]
				);
		}
		if(sw[0] == sw[N] && sw[1] == sw[N+1]){
			for(int i=0; i<N; i++){
				cout << sw[i];
			}
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}