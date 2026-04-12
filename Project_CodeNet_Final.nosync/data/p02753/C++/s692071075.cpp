#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    char tmp;

    int flag = 0;

    tmp = s[0]; 
    for(int i = 0; i < 3; i++){
        if(tmp != s[i]){
            flag = 1;
        }
    }

    if(flag == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }


}