#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;
    int sum = 0;
    int t = 0;
    char s, s1;
    cin >> N;
    vector<char> S(N);
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }
    cin >> K;

    s1 = S.at(K-1);
    for(int i = 0; i < N; i++){
        if(S.at(i) != s1) S.at(i) = '*';
    }
    for(int i = 0; i < N; i++){
    cout << S.at(i);
    }
    cout << endl;
//    vector<int> X();

//    for(int i = 0; i < ; i++){}
//    for(int j = 0; j < ; j++){}

//    cout <<  << endl;
}