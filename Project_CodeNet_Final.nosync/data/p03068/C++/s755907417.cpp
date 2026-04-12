#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    string str;
    cin >> n >> str >> k;
    char ch = str[k-1];
    for (int i = 0; (i < n); ++i) {
        if (str[i] != ch)
            str[i] = '*';
    }
    cout << str << endl;
    return 0;
}
