#include <iostream>
using namespace std;

int main(void){
    
    string k_l = "qwertasdfgzxcvb";
    string k_r = "yuiophjklnm";
    while(1) {
        string s;
        cin >> s;
        int result = 0;
        int mode = -1;
        if (s == "#") break;
        for(int i=0; i<s.length(); i++) {
            if ((int)k_r.find(s[i]) >= 0) {
                if (mode==0) result += 1;
                mode = 1;
            } else {
                if (mode==1) result += 1;
                mode = 0;
            }
        }
        cout << result << endl;
    }
    
}