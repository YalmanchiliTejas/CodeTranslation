#include <iostream>

using namespace std;

int main(){
    int N;
    int K;
    string S;
    cin >> N >> S >> K;

    string ans;
    for(int i = 0;i < N;i++){
        if(S[i] != S[K-1]) ans += "*";
        else ans += S[K-1];
    }

    cout << ans << endl;

    return 0;
}