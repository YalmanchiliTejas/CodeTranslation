#include <iostream>
#include <string>
using namespace std;
int main(){
    int N,K;
    cin >> N;
    string S;
    cin >> S;
    cin >> K;
    char T = S[K-1];
    for(int i=0;i<N;i++){
        if(S[i]!=S[K-1]){
            S.replace(i,1,"*");
        }
    }
    cout << S << endl;
    return 0;
}