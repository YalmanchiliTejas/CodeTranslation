#include <iostream>
using namespace std;
int main() {
    int n , a = 0;
    string s;
    cin >> n;
    cin >> s;
    cin >> a;
    char ex = s[a -1];
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] != ex){
            s[i] = '*';
        }
    }
    cout << s;
    return 0;
}