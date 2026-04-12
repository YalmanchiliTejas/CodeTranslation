#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;
char c;


int main() {
    cin >> n >> s >> k;

    c = s.at(k-1);

    for (int i = 0; i < n; ++i)
    {
        if (s.at(i) != c)
        {
            s.at(i) = '*';
        }
    }

    cout << s << endl;
}