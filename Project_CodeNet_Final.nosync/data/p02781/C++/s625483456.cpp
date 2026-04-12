#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int S(int d, int k){
    int ans = 1;
    if(k != 0){
        ans *= pow(9, k);
    }
    if(k == 1){
        ans *= d;
    }else if(k == 2){
        ans *= d*(d-1)/2;
    }else if(k == 3){
        ans *= d*(d-1)*(d-2)/6;
    }
    if(d < 0){
        ans = 0;
    }
    return ans;
}

int main(void){
    string N;
    int K;
    cin >> N >> K;
    int d = N.size();
    int a[K], D[K];
    for(int i = 0; i < K; i++){
        a[i] = -1;
        D[i] = -1;
    }
    int count = 0;
    for(int i = 0; i < d; i++){
        if(N.substr(i, 1) != "0"){
            a[count] = stoi(N.substr(i, 1));
            D[count] = d-1-i;
            count++;
            if(count >= K){break;}
        }
    }
    
    int ans = 0;
    for(int i = 0; i < K; i++){
        ans += S(D[i], K-i) + (a[i]-1)*S(D[i], K-1-i);
    }
    if(D[K-1] != -1){
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}