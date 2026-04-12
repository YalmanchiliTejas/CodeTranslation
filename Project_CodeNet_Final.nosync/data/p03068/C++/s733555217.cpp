#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    int N, K, i;
    string S, T;

    cin >> N >> S >> K;

    T = S.at(K-1);

    for(i=0; i<N; i++){
        if(S.at(i) != T.at(0)) cout << '*';
        else cout << S.at(i);
    }
    cout << endl;

    return 0;
}