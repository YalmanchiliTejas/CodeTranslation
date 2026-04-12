#include<iostream>
#include<string>
using namespace std;
int main(){
    string c;
    string v("aiueo");
    cin >> c;
    if(v.find(c) != -1){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}