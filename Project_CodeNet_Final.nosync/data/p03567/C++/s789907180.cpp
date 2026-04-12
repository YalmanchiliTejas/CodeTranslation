#include <iostream>
using namespace std;
int main(void){
    // Here your code !
    char S[5];
    cin >> S;
    for( int i = 0; i < 5; ++i ){
        if( S[i] == 'A' && S[i+1] == 'C' ){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}
