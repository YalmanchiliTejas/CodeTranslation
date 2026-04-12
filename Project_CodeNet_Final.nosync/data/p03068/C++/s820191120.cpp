#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N,K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    char c = S[K - 1];

    for (int i = 0; i < N; ++i){
        if(S[i] != c){
            S[i] = '*';
        }
    }

    cout << S << endl;
}
