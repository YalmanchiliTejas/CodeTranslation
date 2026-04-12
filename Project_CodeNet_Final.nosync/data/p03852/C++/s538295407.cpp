#include <iostream>
using namespace std;

int main(){
    char c,table[5]={'a','i','u','e','o'};
    cin >> c;
    for(int i=0;i<5;i++){
        if(table[i]==c){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}