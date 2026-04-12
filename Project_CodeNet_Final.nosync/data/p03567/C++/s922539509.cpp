#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    string str;
    int flag=0;
    cin >> str;
    for(int i=1; i<str.size(); i++){
        if(str[i-1]=='A'&&str[i]=='C')flag=1;
    }
    cout << (flag?"Yes":"No") << endl;
    return 0;
}