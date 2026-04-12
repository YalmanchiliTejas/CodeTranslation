#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <valarray>
#include <utility>
#include <set>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,n) for(int i=1;i<=(int)(n);i++)
#define rep3(i,n) for(int i=0;i<=(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
#define REP2(i,m,n) for(int i=m+1;i<=(int)(n);i++)
#define REP3(i,m,n) for(int i=m;i<=(int)(n);i++)
#define INF 500000000  //
#define INFLL 1000000000000000000  //
#define MOD (1e9)+7

typedef long long int ll;

// a 0x61  z 0x7a  0 0x30

int main() {
    char c;
    cin >> c;
    if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
        cout << "vowel" << endl;
    } else {
        cout << "consonant" << endl;
    }

    return 0;
}