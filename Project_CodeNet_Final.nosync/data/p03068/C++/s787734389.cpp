#include <iostream>
using namespace std;

int main() {
    int n,k;
    string s;
    string asterisk = "*";
    cin >> n;
    cin >> s;
    cin >> k;
    string target = s.substr(k-1,1);

    for(int i=0;i<n;i++){
       if(s.substr(i, 1) != target){
           s.replace(i,1, asterisk);
       }
    }
    cout << s << endl;
    return 0;
}