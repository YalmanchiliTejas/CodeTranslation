#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    string S;
    cin >> S;
    if(S[0] == S[1] && S[1]== S[2])fin("No");
    else fin("Yes");
    return 0;
}