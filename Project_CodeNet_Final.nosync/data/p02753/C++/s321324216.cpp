#include <stdio.h>

#include <iostream>
#include <vector>
#include <string.h>

#pragma warning (push)
#pragma warning (disable : 4996)
#define mod 1000000007;

using namespace std;

int main()
{
    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}

#pragma warning (pop)