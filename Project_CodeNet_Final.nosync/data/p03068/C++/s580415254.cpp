#include <iostream>
using namespace std;
int main(void){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int K;
    cin >> K;
    string ans = "";
    
    for(int i = 0;i < N;i++){
        if(S[i] == S[K - 1]){
            ans += S[K - 1];
        }else{
            ans += "*";
        }
    }
    cout << ans << endl;
}
