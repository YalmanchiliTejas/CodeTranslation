#include <iostream>

using namespace std;

int main(){;
    int N, K;
    string S;

    cin >> N >> S >> K;

    char same;
    same = S[K-1];
    for(int i = 0; i < N; i++){
        if(S[i] != same) S[i] = '*'; 
    }
    cout << S;
}
