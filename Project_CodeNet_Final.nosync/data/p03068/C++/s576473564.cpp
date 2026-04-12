#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int ans, i, j, N, K, l;
    string S, T;
    char k;

    cin >> N >> S >> K;

    ans = 0;
    k = S[K-1];
    l = S.length();

    for (i=0; i<l; i++){
        if (S[i] != k) S[i] = '*';
    }

    cout << S << '\n';
}