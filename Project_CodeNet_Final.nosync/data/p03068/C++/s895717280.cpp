#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){

    int N = 0, M = 0 ,K;
    string S;

    cin >> N;
    cin >> S;
    cin >> K;

    string a;
    for(int i = 0; i < S.size() ; i++){
        if(S[i] == S[K - 1]){
            a += S[i];
        }
        else {
            a += "*";
        }
    }
    cout << a << endl;
    return 0;
}