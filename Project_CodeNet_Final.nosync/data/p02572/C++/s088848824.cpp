#include<iostream>
#include<string>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int N;
    int64_t sum = 0 ,ans = 0;
    int mod = 1000000000+7;
    int i,j;
    
    cin >> N;

    vector<int> a(N);

    for(i = 0;i<N;i++){
        cin >> a[i];
        sum = sum + a[i];
        sum = sum % mod;

    }

    for(i = 0;i<N;i++){
        
        sum = sum - a[i];
        if(sum < 0){
            sum = sum + mod;
        }

        ans = ans + a[i] * sum;

        ans = ans % mod;



    }


    cout << ans << endl;
         
 }