#include <iostream>
using namespace std;
char ch[5]={'a','e','i','o','u'};
int main(){
    char c;
    cin >> c;
    for(int i=0;i<5;i++){
        if(c==ch[i]){
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}