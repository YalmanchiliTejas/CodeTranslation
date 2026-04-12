#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define REP(i,n) for (lint i = 0; i < (n); i++)
#define REP1(i,n) for (lint i = 1; i < (n); i++)

int N, M;

int main(void){
    cin >> N >> M;
    (N == M) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}