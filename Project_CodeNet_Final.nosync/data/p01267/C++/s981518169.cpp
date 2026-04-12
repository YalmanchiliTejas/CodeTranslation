#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,A,B,C,X;
	int Y[101];
	int i;
	while(1){
		int count = 0;
		cin >> N >> A >> B >> C >> X;
		if(N+A+B+C+X==0) break;
		for(i = 0 ;  i < N ;i++){
			cin >> Y[i];
			}
		for(i = 0 ; i < 10001 ; i++){
			if(X==Y[count]) count++;
			if(count == N) break;
			X = (A*X+B)%C;
			}
		if(i != 10001) cout << i << endl;
		else cout << "-1" << endl;
		}
	return 0;
	}