#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    string del = S.substr(K - 1, 1);
    string D;

    for (int i = 0; i < N; i++){
        if(S.substr(i, 1) != del){
            D += "*";
        }
        else D += S.substr(i, 1);
    }
    cout << D << endl;
    return 0;
}