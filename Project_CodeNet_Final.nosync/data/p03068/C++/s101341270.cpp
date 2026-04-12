#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> s >> k;
    char c = s.at(k-1);
    string ans = "";
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) != c) {
            ans += "*";
        } else {
            ans += s.at(i);
        }
    }
    cout << ans << endl;
    return 0;
}