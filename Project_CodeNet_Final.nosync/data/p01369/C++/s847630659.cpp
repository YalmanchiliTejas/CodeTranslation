#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    while(cin >> str, str != "#") {
        int flag = -1;
        int ans=0;
        for(int i=0; i<str.size(); ++i) {
            char c = str[i];
            if(c <= 'g' || ('q' <= c && c <= 't') || ('v' <= c && c <= 'x') || c == 'z') {
                if(flag == 1) {
                    ans++;
                }
                flag = 0;
            } else {
                if(flag == 0) {
                    ans++;
                }
                flag = 1;
            }
        }
        cout << ans << endl;
    }
}
