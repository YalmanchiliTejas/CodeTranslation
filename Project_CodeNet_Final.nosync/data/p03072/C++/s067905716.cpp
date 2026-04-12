#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

using namespace std;

typedef long long ll;

int N, H[100];

int main() {
    cin >> N;
    REP(i,N) {
        cin >> H[i];
    }
    int result = 0;
    int max = 0;
    REP(i,N) {
        if (i == 0) {
            result++;
            max = H[i];
            continue;
        }
        if ((H[i - 1] <= H[i]) && max <= H[i]) {
            result++;
            max = H[i];
        }
    }
    
    cout << result << endl;
    
}
