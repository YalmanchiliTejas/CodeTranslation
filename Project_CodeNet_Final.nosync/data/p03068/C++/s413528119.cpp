#include <iostream>
using namespace std;

int main(void)
{
    string s;
    int n, k;
    char c;

    cin >> n >> s >> k;
    c = s[k-1];
    for (int i = 0; i < n; i++) {
        if (s[i] != c) s[i] = '*';
    }
    cout << s << endl;
}
