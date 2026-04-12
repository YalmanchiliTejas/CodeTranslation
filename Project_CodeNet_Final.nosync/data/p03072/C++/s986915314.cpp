#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;
const long double EPS = 1e-9;
const ll mod = 1e9 + 7;

#define rep(i, n) for(int i = 0; i < n ; i++ )
#define For(i, a, b) for(int i = (a); i < (b) ; i++ )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int MAX_N = 20;

int main(void){
    int N;
    int H[MAX_N];
    int max_H[MAX_N];
    int answer = 0;

    cin >> N;
    
    rep(i, N){
        cin >> H[i];
        if (i == 0){
            max_H[i] = H[i];
        }else{
            max_H[i] = max(max_H[i - 1], H[i]);
        }
        
    }

    rep(i, N){
        if (max_H[i] == H[i]){
            answer ++;
        }
    }


    cout << answer << endl;

    return 0;
}