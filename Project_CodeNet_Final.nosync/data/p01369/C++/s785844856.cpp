#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s;
    int n,m;
    while(1){
        cin >> s;
        n = 0;
        if(s[0] == '#')break;
         
        if(s[0] == 'y' || s[0] == 'h' || s[0] == 'n' || s[0] == 'u' || s[0] == 'j' || s[0] == 'm' || s[0] == 'i' || s[0] == 'k' || s[0] == 'o' || s[0] == 'l' || s[0] == 'p' ){
        m = 0;
        }
        else m = 1;
        for(int i = 1;i < s.size();i++){
            if(s[i] == 'y' || s[i] == 'h' || s[i] == 'n' || s[i] == 'u' || s[i] == 'j' || s[i] == 'm' || s[i] == 'i' || s[i] == 'k' || s[i] == 'o' || s[i] == 'l' || s[i] == 'p'){
                if(m == 1){
                    n++;
                    m = 0;
                }
            }
            else if(s[i] == 'b' || s[i] == 'g' || s[i] == 't' || s[i] == 'r' || s[i] == 'f' || s[i] == 'v' || s[i] == 'c' || s[i] == 'd' || s[i] == 'e' || s[i] == 'w' || s[i] == 's' || s[i] == 'x' || s[i] == 'z' || s[i] == 'a' || s[i] == 'q'){
                if(m == 0){
                    n++;
                    m = 1;
                }
            }
        }
        cout << n <<endl;
    }
    return 0;
}