#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Here your code !
    string S;
    cin >> S;
    
    
    bool flg = false;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'A'){
            if(S[i + 1] == 'C')
                flg = true;
                break;
        }
    }
    
    if(flg){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}
