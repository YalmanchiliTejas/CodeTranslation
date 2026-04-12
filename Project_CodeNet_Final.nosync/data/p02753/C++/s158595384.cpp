#include <iostream>
#include <string>
using namespace std;
int main(){
    string S;
    cin >> S;
bool aok = false;
bool bok = false;
    for(int i= 0; i < S.size(); i++){
       if(S[i] == 'A' ){
           aok = true;
       }
       if(S[i] == 'B'){
           bok = true;
       }
    }

    if(aok && bok){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;

}
