#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    string S;
    cin >> S;
    
    int K;
    cin >> K;
    
    char s = S[K - 1];
    
    string ans = "";
    
    for (int i = 0; i < N; i++){
        if (S[i] == s){
            ans += S[i];
        }
        else {
            ans += '*';
        }
    }
    
    cout << ans << endl;
}