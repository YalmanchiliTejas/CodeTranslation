#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <math.h>
#include <tuple>
#include <queue>
#include <set>

using namespace std;
#include <bits/stdc++.h>

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int N, K;
    string S;

    cin >> N >> S >> K;

    char S_K;
    S_K = S[K-1];

    for(int i = 0; i < S.length(); i++){
        if(S[i] != S_K){
            S[i] = '*';
        }
    }

    cout << S << endl;

    return 0;
}
