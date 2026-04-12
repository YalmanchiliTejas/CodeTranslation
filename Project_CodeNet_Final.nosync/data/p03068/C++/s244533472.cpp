#include <iostream>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char kth = s[k - 1];
    for(int i = 0; i < n; i++)
    {
        if(s[i] != kth)
        {
            s[i] = '*';
        }
    }
    cout << s;

    return 0;
}
