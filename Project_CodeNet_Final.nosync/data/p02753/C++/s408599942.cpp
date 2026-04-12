#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    cin >> S;
    char C = S[0];

    bool ok = true;
    for (int i = 1; i < S.size(); i++)
    {
        if(S[i] != C){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}