#include <bits/stdc++.h>
using namespace std;

int main() {
    int K,N;
    string S;
    cin >> N >> S >> K;
    char x = S.at(K-1);
    for(int i = 0;i<N;i++){
        if(S.at(i)!=x){
            S.at(i)='*';
        }
    }
    cout << S << endl;
    return 0;
}