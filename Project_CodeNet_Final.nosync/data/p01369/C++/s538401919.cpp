#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string r = "qwertasdfgzxcvb";

int main(){
    string str;
    while(cin >> str, str != "#"){
        int sw = 0;
        bool prev = r.find(str[0]) == string::npos;
        for(int i=1; i<str.size(); i++){
            bool now = r.find(str[i]) == string::npos;
            sw += prev ^ now;
            prev = now;
        }
        cout << sw << endl;
    }
}
                                   