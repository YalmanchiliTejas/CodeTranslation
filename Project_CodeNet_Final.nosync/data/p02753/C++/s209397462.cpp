#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string S;
    cin >> S;
    bool A = false;
    bool B = false;
    for(int i = 0; i < S.length(); i++)
    {
        if(S[i] == 'A') A = true;
        else    B = true;
    }
    if(A && B) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}