#include <iostream>
#include <string>
using namespace std;

int main(){
    int len;
    string S;
    int K;
    char t;
    
    cin >> len;
    cin >> S;
    cin >> K;
    
    // get k-1 char
    t = S[K-1];
    
    for(int i = 0; i < len; i++){
        if(S[i] != t){
            S[i] = '*';
        }
    }
    
    cout << S << endl;
    return 0;
}
