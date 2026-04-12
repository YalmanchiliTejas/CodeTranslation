#include <iostream>
#include <string>
using namespace std;

int main (){
    string str;
    cin >> str;
    int num = (int)(str.length());

    int i,flag=0;
    for(i=1;i<num;i++){
        if( str[i-1] != str[i]){
            flag = 1;
            break;
        }
    }

    if(flag == 0) cout << "No" << endl;
    if(flag == 1) cout << "Yes" << endl;
    
    return 0;
    
}