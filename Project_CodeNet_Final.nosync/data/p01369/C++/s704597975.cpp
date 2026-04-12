#include <iostream>
#include <string>

using namespace std;

const string L = "qwertasdfgzxcvb";

int main(){
    string s;
    while(cin >> s, s != "#"){
        int ans = 0;
        bool prev = L.find(s[0]) != string::npos; 
        for(int i=1; i<(int)s.size(); ++i){
            bool cur = L.find(s[i]) != string::npos;
            ans += cur != prev;
            prev = cur;
        }
        cout << ans << '\n';
    }
    return 0;
}