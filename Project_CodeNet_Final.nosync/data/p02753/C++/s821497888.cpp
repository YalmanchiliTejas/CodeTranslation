#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string S;
    cin >> S;
    if (S[0] != S[1] || S[1] != S[2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}
