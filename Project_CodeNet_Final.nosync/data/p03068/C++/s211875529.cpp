#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int N, K;
    string S, res = "";
    
    cin >> N >> S >> K;
    
    for (int i = 0; i < N; ++i) {
        if (S[i] != S[K-1]) S[i] = '*';
    }
    cout << S << endl;
}
