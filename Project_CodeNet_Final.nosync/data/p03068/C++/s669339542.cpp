#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void){
    long long N,K;
    string S,result;
    cin >> N >> S >> K;
    char tmp = S[K - 1];
    for (int i = 0; i < S.size(); i++){
        if(S[i] != tmp){
            S[i] = '*';
        }
    }
    cout << S << endl;
    return 0;
}
