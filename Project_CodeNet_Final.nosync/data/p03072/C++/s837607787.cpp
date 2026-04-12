#include <bits/stdc++.h>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> H(N);

    for(int i = 0; i < N; i++){
	cin >> H.at(i);
    }

    int sum = 0;
    int prev = 0;

    for(int i = 0; i < N; i++){
	if(H.at(i) >= prev){
	    sum++;
	    prev = H.at(i);
	}else{
	    
	}
    }

    cout << sum << endl;
    
}
