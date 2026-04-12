#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);

    for(long long i =  0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<long long>());
    long long sum = 0;
    if(n % 2 != 0){
        long long sum1 = 0;

        for(long long i = 0; i < n; i++){
            if(i < (n-1)/2){
                sum1 += 2*a[i];
            }
            else if((n-1)/2 <= i and i <= (n+1)/2){
                sum1 -= a[i];
            }
            else{
                sum1 -= 2*a[i];
            }
        }
        long long sum2 = 0;
        for(long long i = 0; i < n; i++){
            if(i < (n-3)/2){
                sum2 += 2*a[i];
            }
            else if((n-3)/2 <= i and i <= (n-1)/2){
                sum2 += a[i];
            }
            else{
                sum2 -= 2*a[i];
            }
        }
        sum = max(sum1, sum2);
    }
    else{
        for(long long i = 0; i < n; i++){
            if(i < (n-2)/2){
                sum += 2*a[i];
            }
            else if((n-2)/2 == i ){
                sum += a[i];
            }
            else if(n/2 == i){
                sum -= a[i];
            }
            else{
                sum -= 2*a[i];
            }
        }
    }
    cout << sum << endl;
    return 0;
}