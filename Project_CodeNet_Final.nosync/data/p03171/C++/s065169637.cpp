#include <iostream>
#include<iomanip>
#include <cmath>
#include <climits>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long dp1[3000][3000];
long long dp2[3000][3000];
long long a[3000];

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    for(int i = 0; i < N; i++){
        dp1[i][i] = a[i];
        dp2[i][i] = -a[i];
    }

    for(int i = N - 1; i >= 0; i--){
        for(int j = i + 1; j < N; j++){
            dp1[i][j] = max(a[i] + dp2[i + 1][j], a[j] + dp2[i][j - 1]);
            dp2[i][j] = min(dp1[i + 1][j] - a[i], dp1[i][j - 1] - a[j]);
        }
    }
    cout << dp1[0][N-1] << endl;

    
    return 0;

}