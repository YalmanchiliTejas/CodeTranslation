#include <iostream>
using namespace std;

int main(){
    string s;cin>>s;
    bool judge = false;
    for (int i=0;i<s.size() - 1;i++){
        if (s[i] == 'A' && s[i+1] == 'C'){
            judge = true;
            break;
        }
    }
    if (judge){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}