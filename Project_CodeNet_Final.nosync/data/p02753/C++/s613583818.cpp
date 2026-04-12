#include <iostream>
#include <string>
using namespace std;

int main() {

    string S;

    cin >> S;

    for (int i = 1; i < S.size(); i++)
    {
        if(S[i-1]!=S[i]){
            cout << "Yes" << endl;
            return 0; 
        }
    }

    cout << "No" << endl;
    return 0;
}
