#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)

using namespace std;
typedef pair<int, int> ipair;

int main(int argc, char **argv) {
    int N, K;
    string S;
    cin >> N >> S >> K;

    for(int i = 0; i < N; ++i)
        if(S[i] != S[K - 1])
            S[i] = '*';
    
    cout << S << endl;
}