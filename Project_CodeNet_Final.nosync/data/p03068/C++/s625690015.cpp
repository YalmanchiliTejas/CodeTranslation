#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    char kc=s[k-1];
    for(auto c : s){
        if(c!=kc) c='*';
        cout << c;
    }
    cout << endl;
    return 0;
}
