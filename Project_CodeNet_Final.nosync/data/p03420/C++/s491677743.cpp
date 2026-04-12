#include <iostream>
#include <string>
using namespace std;
int main(void){
    long n, k;
    cin >> n >> k;
    
    long i, sum = 0;
    
    if(!k){cout << n*n << endl; return 0;}
    
    for(i = k+1; i <=n; i++){
        sum += (n/i)*(i - k);
        if(n%i >= k) sum += n%i - k + 1;
    }
    
    cout << sum <<endl;
    return 0;
}
