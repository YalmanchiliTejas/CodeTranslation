#include <iostream>
#include <string>

using namespace std;

int main(){

    string S; cin >> S;
    bool f = false;
    for (int i = 0; i < S.length() - 1; i++){
        if (S[i] == 'A' && S[i + 1] == 'C'){
            f = true;
            cout << "Yes" << endl;
            break;
        }
    }

    if (f == false){
        cout << "No" << endl;
    }
    
    

    return 0;
}