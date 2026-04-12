using namespace std;
#include<iostream>
#include<stdio.h>

int main(){
    string s;
    cin >> s;

    bool ans = false;

    for(int i = 0; i < s.length()-1; i++){
        string tmp = s.substr(i,2);
        if (tmp == "AC"){
            ans = true;
        }
    }

    if (ans == true){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    return 0;
}