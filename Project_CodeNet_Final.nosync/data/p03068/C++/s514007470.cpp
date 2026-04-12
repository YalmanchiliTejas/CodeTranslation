#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;    
    string S;
    cin >> N;
    cin >> S;
    cin >> K;        
    for(int i=0; i<N; i++){
	if(S[K-1] != S[i])
	    S[i] = '*';
    }
    
    cout << S << endl;
}
