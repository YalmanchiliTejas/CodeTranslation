#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int N;
    int K;
    cin >> N >> S >> K;
    char remain = S.at(K - 1);
    for(int i=0; i < N; i++){
        if(S.at(i) != remain){
            S.at(i) = '*';
        }
    }
    cout << S << endl;
    return 0;
}
