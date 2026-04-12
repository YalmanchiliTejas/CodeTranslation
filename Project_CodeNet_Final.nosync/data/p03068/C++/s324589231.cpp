#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;

    char a = S[K-1];
    string ans;

    for(int i = 0; i < N; i++){
        if(S[i] != a)ans.push_back('*');
        else ans.push_back(S[i]);
    }
    cout << ans << endl;
    return 0;
}