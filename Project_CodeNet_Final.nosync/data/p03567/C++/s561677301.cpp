#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    string ans = "No";

    for(int i=0;i<S.length()-1;i++){
        if((S.at(i)=='A')&&(S.at(i+1)=='C')){
            ans="Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}