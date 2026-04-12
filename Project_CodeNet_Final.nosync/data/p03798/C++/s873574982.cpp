#include <iostream>
#include <string>
using namespace std;
#define NMAX 100000 
bool move(int N,bool a,bool b,char *C,bool *T){
	T[0] = a;
	T[1] = b;
	bool ans = false;
	for(int i=1;i<N-1;i++){
		if((T[i-1] == T[i] && C[i] == 'o') || (T[i-1] != T[i] && C[i] == 'x')){
			T[i+1] = true;
		}else{
			T[i+1] = false;
		}
	}
	if((T[N-2] == T[N-1] && C[N-1] == 'o') || (T[N-2] != T[N-1] && C[N-1] == 'x')){
		if(T[0] && ((C[0] == 'o' && T[1] == T[N-1]) || (C[0] == 'x' && T[1] != T[N-1])) ){
			ans = true;
		}
	}else{
		if(!T[0] && ((C[0] == 'o' &&T[1] != T[N-1]) || (C[0] == 'x' && T[1] == T[N-1])) ){
			ans = true;
		}
	}
	return ans;
}

//O(n)まで
int main(){
	int N;
	cin >> N;
	char C[N];
	bool T[N];
	bool ans = false;
	cin >> C;
	if(move(N,true,true,C,T)) ans = true;
	else if(move(N,true,false,C,T)) ans = true;
	else if(move(N,false,true,C,T)) ans = true;
	else ans = move(N,false,false,C,T);
	if(ans){
		for(int i=0;i<N;i++){
			if(T[i]){
				cout << "S";
			}else{
				cout << "W";
			}
		}
		cout << endl;
	}else{
		cout << "-1" << endl;
	}

	return 0;
}