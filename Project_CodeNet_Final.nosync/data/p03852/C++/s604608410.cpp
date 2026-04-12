#include<iostream>
#include<string>

using namespace std;

int main(){
    char c;
    string s="aeiou";
    cin >> c;
    bool ans=false;
    for(int i=0;i<=4;i++){
        if(s[i]==c){
            ans=true;
        }
    }
    if(ans){
        cout << "vowel" << endl;
    }
    else{
        cout << "consonant" << endl;
    }
}