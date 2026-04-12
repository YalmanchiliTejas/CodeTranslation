#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)

int Result_int;
long Result_lng;
string Result_str = "";
//int A,B,C;
int N,K,n;
string S;

int main() {
    int r_min,r_max;
    char target;
    cin >> N >> S >> K;
    n = N;
    target = S[K-1];
    REP(i,n) {
        if (S[i] != target) {
            Result_str += "*";
        } else {
            Result_str += S[i];
        }
    }

    cout << Result_str << endl;
}



