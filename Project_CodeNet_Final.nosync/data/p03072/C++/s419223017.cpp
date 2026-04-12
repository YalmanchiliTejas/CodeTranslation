#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, N, M ,K;
    int sum = 0;
    int t = 0;
    string s, s1;
    cin >> A;

    vector<int> H(A);
    for(int i = 0; i < A; i++){
        cin >> H.at(i);
    }
    K = H.at(0);
    for(int i = 0; i < A; i++){
        if(K <= H.at(i)) {
            t++;
            K = H.at(i);
        }
    }
//    for(int i = 0; i < ; i++){}
//    for(int j = 0; j < ; j++){}

    cout << t << endl;
}