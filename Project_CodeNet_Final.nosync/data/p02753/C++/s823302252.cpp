#include <iostream>
using namespace std;

int main(void){
    char Sbuf;
    bool AExists = false;
    bool BExists = false;
    for(int i=0; i<3; i++){
        cin >> Sbuf;
        if(Sbuf == 'A'){
            AExists = true;
        }else{
            BExists = true;
        }
    }
    if(AExists && BExists){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}