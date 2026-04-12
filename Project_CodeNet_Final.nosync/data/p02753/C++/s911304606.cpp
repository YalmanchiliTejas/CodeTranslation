#include <iostream>
using namespace std;

int main(){
    const int i = 3;
    char S[i];

    for(int j=0; j<i; j++){
        cin >> S[j];
    }

    if(S[0] == 'A' && S[1] == 'A' && S[2] == 'A' ){
        cout << "No" << endl;
    }else if(S[0] == 'B' && S[1] == 'B' && S[2] == 'B'){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }


    return 0;
}