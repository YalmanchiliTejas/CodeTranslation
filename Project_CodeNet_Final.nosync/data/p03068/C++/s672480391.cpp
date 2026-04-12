#include <bits/stdc++.h>

using namespace std;

int main(){

    int N, K;
    string S;

    cin >> N;
    cin >> S;
    cin >> K;

    char c = S.at(K-1);

    for(int i = 0;i < N; i++){
	if(c != S.at(i)){
	    S.at(i) = '*';
	}
    }
    cout << S << endl;
    
}
