#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <bits/stdc++.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <functional> 
#include<math.h> 
using namespace std;
int main(void){
    // Your code here!
    long long int N,K;
    cin >> N >> K;
    long long int count = 0;
    for(int i = 1;i <= N; i++){
        if(i > K){
            count += (i - K) * (N / i) ;
            if(K == 0){
                count--;
            }
            if(N % i - K +1 > 0){
                count += N % i - K + 1;
            }
        }
        //cout << count << endl;
    }
    cout << count << endl;
}
