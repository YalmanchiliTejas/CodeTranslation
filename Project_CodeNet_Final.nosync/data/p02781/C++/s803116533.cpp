#include "bits/stdc++.h"

using namespace std;

int nCk(int n, int k){
    if(k == 0){
        return 1;
    }else if(k == 1){
        return n;
    }else if(k == 2){
        return n*(n-1)/2;
    }else if(k == 3){
        return n*(n-1)*(n-2)/6;
    }else{
        return 0;
    }
}

int p9(int k){
    if(k == 0){
        return 1;
    }else if(k == 1){
        return 9;
    }else if(k == 2){
        return 81;
    }else if(k == 3){
        return 729;
    }else{
        return 0;
    }
}

int main() {
    string N;
    int K;
    cin >> N >> K;
    int ans = 0;
    int n = N.length();
    int j = n;
    for(int i = K; i >= 0; i--) {
        if(j < i)
            break;
        ans += nCk(j - 1, i) * p9(i);
        int l = N[n - j] - '0' - 1;
        ans += l * nCk(j - 1, i - 1) * p9(i - 1);
        j--;
        if(j<0)
            break;
        while(N[n - j] == '0' && j > 0) {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}