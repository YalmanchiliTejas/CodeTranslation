#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    int K;

    cin >> N;
    cin >> S;
    cin >> K;

    char SK = (char)S[K-1];

    for(int i;i<S.size();i++)
    {
        if(S[i] == SK);
        else S[i] = '*';
    }

    cout << S << endl;

    return 0;
}