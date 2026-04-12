#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <locale>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int num = 0;
    for(int i=0;i < n-1;i++){
        if(s[i]=='A' && s[i+1]=='C'){
            num++;
        }
    }
    if(num >= 1){cout << "Yes" << endl;}
    else cout << "No" << endl;

    return 0;
}