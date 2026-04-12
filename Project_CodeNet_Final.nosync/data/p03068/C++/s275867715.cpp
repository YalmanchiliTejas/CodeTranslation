#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int N,K;
    string S;
    
    cin >> N >> S >> K;

    for(int i=0;i<S.length();i++){
        if(S[i] != S[K-1]){
            S[i] = '*';
        }
    }
    cout << S << endl;
}
