#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    string S;
    cin >> S;
    cin >> k;
    for (int i = 0; i < n; i++) {
        if(S[i] != S[k - 1])
            S[i] = '*';
    }
    cout << S << endl;
    return (0);
}