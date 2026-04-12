#include<iostream>
using namespace std;

void output(){
    cout << "vowel" << endl;
}
int main(){
    char c;
    cin >> c;
    if(c == 'a'){
        output();
    }
    else if(c == 'i'){
        output();
    }
    else if(c == 'u'){
        output();
    }
    else if(c == 'e'){
        output();
    }
    else if(c == 'o'){
        output();
    }
    else{
        cout<<"consonant"<<endl;
    }
    
}