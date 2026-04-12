#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    string s ;
    cin >> s ;
    if(s[0]=='B'&&s[1]=='B'&&s[2]=='B'){
        cout<< "No" << endl;
    }else if(s[0]=='A'&&s[1]=='A'&&s[2]=='A'){
        cout<< "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    
    return 0;
}