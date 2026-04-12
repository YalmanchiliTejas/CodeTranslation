#include<iostream>
#include<string>
using namespace std;


int main(){
	int N, K;
	string S;
	cin >> N >> S >> K;
	char s = S[K-1];
	for(int i=0;i<N;i++){
		if(S[i] != s){
			cout << '*';
		}
		else{
			cout << s;
		}
	}
    return 0;
}