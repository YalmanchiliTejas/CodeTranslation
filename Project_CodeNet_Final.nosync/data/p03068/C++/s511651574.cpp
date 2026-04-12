#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int N,K;
    string S;
    cin >> N >>S >>K;
    
    for (int i=0; i<N; i++) {
        if (S[i]!=S[K-1]) {
            S[i]='*';
        }
    }
    cout << S << endl;
}
