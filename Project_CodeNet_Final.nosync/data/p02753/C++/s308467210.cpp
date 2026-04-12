#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <functional>
using namespace std;
#define rep(i, a, b) for (int(i) = a; (i) < (int)(b); (i)++)

int main()
{
    string S;
    cin >> S;
    if (S[0] == S[1] && S[0] == S[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}