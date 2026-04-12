#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    long long int N, i, sum, ans;
    cin >> N;
    long long int a[N], b[N];
    sum = 0;
    
    for (i = 0; i < N; i++){
        cin >> a[i];
        if (i == 0){
            b[i] = a[i];
        } else {
            b[i] = (b[i - 1] + a[i]) % ((long long int)pow(10, 9) + 7);
        }
   }
    
    for (i = 1; i < N; i++){
        sum += a[i] * b[i - 1];
        sum %= ((long long int)pow(10, 9) + 7);
    }
    
    
    cout << sum;

    return 0;
}
