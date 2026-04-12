#include <iostream>
using namespace std;
int main(void){
    char c,C[5]={'a','i','u','e','o'};
    int flag=0;
    cin >> c;
    for(int i=0;i<5;i++){
        if(C[i]==c){
            flag=1;
            break;
        }
    }
    if(flag) cout<<"vowel";
    else cout<<"consonant";
}
