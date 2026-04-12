#include <iostream>
#include <string>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main(){
    string s;
    int n = 0, m = 0;
    cin >> s;
    rep(i,3){
        if(s[i] == 'A') n++;
        else if (s[i] == 'B') m++;
    }   
    if(n > 0 && m > 0){
        cout << "Yes" << endl;
    } else if (n == 0 || m == 0){
        cout << "No" << endl;
    }
}