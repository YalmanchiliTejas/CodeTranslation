#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    char good;
    for (int i = 0; i < S.size(); i++){
        if (S.at(K-1) != S.at(i)){
            S.at(i)='*';
        }
        cout << S.at(i);
    }
    cout << endl;
}
