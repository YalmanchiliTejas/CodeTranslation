#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;

    char target = S[K-1];
    for(int i = 0; i < N; i++){
        if(S[i] != target){
            S[i] = '*';
        }
    }
    cout << S << endl;

    return 0;
}