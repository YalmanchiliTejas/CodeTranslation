#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
    string s; cin >> s;
    if(s[0] != s[1] || s[0] != s[2] || s[1] != s[2]){
        cout << "Yes";
    }else{
        cout << "No";
    }
}