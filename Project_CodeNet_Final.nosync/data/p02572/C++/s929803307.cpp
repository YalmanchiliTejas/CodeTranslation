
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    long long int N, i, sum, sq_sum, k, ans;
    cin >> N;
    long long int a[N];
    sum = 0;
    sq_sum = 0;
    
    for (i = 0; i < N; i++){
        cin >> a[i];
        
        sum += a[i];
        sum %= ((long long int)pow(10, 9) + 7);
        sq_sum += a[i] * a[i];
        sq_sum %= ((long long int)pow(10, 9) + 7);
        
    }
    
    k = (sum * sum - sq_sum) % ((long long int)pow(10, 9) + 7);
    
    if ( k % 2 == 0 ){
        ans = k / 2;
    } else {
        ans = ( k + (long long int)pow(10, 9) + 7 ) / 2;
    }
    
    cout << ans;

    return 0;
}
