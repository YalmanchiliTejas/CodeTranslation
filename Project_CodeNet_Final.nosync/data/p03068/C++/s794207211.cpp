#include <iostream>
#include <string>

using namespace std;
int main(){
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char target = s[k - 1];

    for (int i = 0; i < n; i++){
        if(s[i] != target)
            s[i] = '*';
    }

    cout << s << endl;

    return 0;
}