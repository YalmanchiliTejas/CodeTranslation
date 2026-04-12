#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

bool kaibun(string s){
    size_t len = s.length();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] and s[1]==s[2]){
        cout << "No" <<endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}