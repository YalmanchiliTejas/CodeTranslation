#include<iostream>
#include<string>
#include <numeric>
using namespace std;
string str;
int main() {
    cin >> str;
    bool flag=false;
    for(int i=0; i<str.size()-1; ++i){
        if(str[i]=='A'&&str[i+1]=='C'){
            cout << "Yes" << endl;
            flag = true;
        }
        if(flag) break;
    }
    if(!flag) cout << "No" << endl;
    return 0;
}