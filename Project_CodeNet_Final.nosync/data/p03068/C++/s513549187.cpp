#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
typedef long long ll;
using namespace std;

int main () {
    ll N, K;
    string S;
    cin >> N >> S >> K;
    char c = S[K-1];
    for(int i = 0; i < N; i++)
    {
        if(S[i] == c) {
            cout << S[i];
        }else {
            cout << '*';
        }
    }
    cout << endl;
}