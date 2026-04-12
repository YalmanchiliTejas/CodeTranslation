#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    string S;

    cin >> N;
    cin >> S;
    cin >> K;

    char Si = S.at(K-1);

    for(int i=0; i<N; i++){
        if(S[i] != Si){
            S[i] = '*';
        }
    }

    cout << S << endl;

    return 0;
}