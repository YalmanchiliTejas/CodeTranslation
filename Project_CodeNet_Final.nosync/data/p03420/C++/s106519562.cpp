#include <iostream>
using namespace std;
int main(void){
    int n, k;
    cin >> n >> k;
    
    long long i, sum = 0;
    
    for(i = k+1; i <=n; i++){
        sum += (n/i)*(i - k);
        if(!k) sum--;
        if(n%i >= k) sum += n%i - k + 1;
    }
    
    cout << sum <<endl;
    return 0;
}
