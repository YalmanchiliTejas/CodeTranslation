#include <iostream>
using namespace std;

int main()
{
    string S; cin >> S;
    for (int i = 0; i < S.size()-1; i++) {
        for (int j = i+1; j < S.size(); j++) {
            if (S[i] != S[j]) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;

}