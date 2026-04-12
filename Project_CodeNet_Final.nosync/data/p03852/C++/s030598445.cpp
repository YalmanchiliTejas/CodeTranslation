#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main(){
    string str;
    while(cin >> str){
        if(str[0] == 'a' || str[0] == 'e' ||str[0] == 'i' ||str[0] == 'o'||str[0] == 'u'){
            cout << "vowel" << endl;
        }else cout << "consonant" << endl;
    }
    return 0;
}
