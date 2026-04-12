
#include <iostream>

using namespace std;

int main()
{
    int n, k;
    string s, ss;

    cin >> n >> s >> k;

    for (int i=0; i<n; i++)
    {
        if (s[k-1] != s[i])
            ss += "*";
        else
            ss += s[i];
    } 

    cout << ss << endl;

    return 0;
}
