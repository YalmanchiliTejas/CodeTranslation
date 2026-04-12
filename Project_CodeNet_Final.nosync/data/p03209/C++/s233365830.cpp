#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>

using namespace std;

void ans(long long N, long long X,long long &pate) {
    //cout << pate << endl;
    if (N == 1) {
        if (X <= 0) return;
        else if (X >= 5) pate += 3;
        else  pate+= X - 1;       
    }
    else {
        if (X <= 0)return;
        if (X < pow(2, N + 1) - 1)
            ans(N - 1, X - 1,pate);
        else {
            pate += pow(2, N);
            ans(N - 1, X - (pow(2, N + 1) - 1),pate);
        }
    }
}
int main() {
    long long N, X;
    cin >> N >> X;
    long long pate = 0;

    ans(N, X, pate);
    cout << pate << endl;

}