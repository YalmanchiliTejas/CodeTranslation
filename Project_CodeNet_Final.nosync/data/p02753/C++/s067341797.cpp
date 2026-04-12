#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    string str="";
    cin >> str;
    if(str[1]==str[0] && str[2]==str[0]){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }
    return 0;
}




