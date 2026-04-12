#include <iostream>
#include <string>
using namespace std;

int N;
string S,T;

bool equal(int n, char animal){
	if(animal=='S' && S[n]=='o' || animal=='W' && S[n]=='x') return true;
	else return false;
}

char is_it(int n){
	if(equal(n,T[n])) return T[n-1];
	else{
		if(T[n-1] == 'S') return 'W';
		else return 'S';
	}
}

int main(){
	cin >> N;
	cin >> S;
	T = S;
	T[0] = 'S';
	bool judge = false;
	if(S[0]=='o'){
		for(int i=1;i<=2;i++){
			if(i==1){
				T[1] = 'S';
				T[N-1] = 'S';
			}else{
				T[1] = 'W';
				T[N-1] = 'W';
			}
			for(int j=2;j<=N-2;j++){
				T[j] = is_it(j-1);
			}
			if(T[N-1]==is_it(N-2) && T[0]==is_it(N-1)){
				judge = true;
				break;
			}
		}
	}else{
		for(int i=1;i<=2;i++){
			if(i==1){
				T[1] = 'S';
				T[N-1] = 'W';
			}else{
				T[1] = 'W';
				T[N-1] = 'S';
			}
			for(int j=2;j<=N-2;j++){
				T[j] = is_it(j-1);
			}
			if(T[N-1]==is_it(N-2) && T[0]==is_it(N-1)){
				judge = true;
				break;
			}
		}
	}
	if(!judge){
		T[0] = 'W';
		if(S[0]=='x'){
			for(int i=1;i<=2;i++){
				if(i==1){
					T[1] = 'S';
					T[N-1] = 'S';
				}else{
					T[1] = 'W';
					T[N-1] = 'W';
				}
				for(int j=2;j<=N-2;j++){
					T[j] = is_it(j-1);
				}
				if(T[N-1]==is_it(N-2) && T[0]==is_it(N-1)){
					judge = true;
					break;
				}
			}
		}else{
			for(int i=1;i<=2;i++){
				if(i==1){
					T[1] = 'S';
					T[N-1] = 'W';
				}else{
					T[1] = 'W';
					T[N-1] = 'S';
				}
				for(int j=2;j<=N-2;j++){
					T[j] = is_it(j-1);
				}
				if(T[N-1]==is_it(N-2) && T[0]==is_it(N-1)){
					judge = true;
					break;
				}
			}
		}
	}
	if(judge) cout << T << endl;
	else cout << -1 << endl;
}