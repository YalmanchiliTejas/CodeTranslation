#include <iostream>
#include <string>

using namespace std;

int main(void){
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;
    for(int i = 0; i < n; ++ i) s[i] = ((s[i] == s[k - 1])? s[i] : '*');
    cout << s << endl;
    
    return 0;
}
