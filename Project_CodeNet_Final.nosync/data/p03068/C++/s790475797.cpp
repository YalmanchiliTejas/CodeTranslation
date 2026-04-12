#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;


int main(int argc, char** argv){
    int N, K;
    string S;
    cin >> N >> S >> K;

    for (int i=0; i<N; i++)
        if (S[i] != S[K-1])
            S[i] = '*';

    cout << S << "\n";

    return 0;
}
