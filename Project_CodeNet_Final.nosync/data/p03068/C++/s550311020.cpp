#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;

    char t = s[k-1];

    for(int i = 0;i < n; i++) {
        if(s[i] != t) {
            s[i] = '*';
        }
    }
    cout << s << endl;

    return 0;
}