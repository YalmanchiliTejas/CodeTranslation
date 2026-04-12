#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {    
    int n,k;
    string s;
    cin >> n >> s >> k;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[k-1]) cout << '*';
        else cout << s[i];
    }
    cout << endl;
    return 0;
}
