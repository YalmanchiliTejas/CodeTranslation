#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;

    long long count = 0;
    for(long long b = k + 1; b <= n; b++){
        long long pivot = b - k;
        count += (n/b)*pivot;
        if(k >= 1 and n%b != 0 and n%b >= k){
            count += n%b - k + 1;
        }
        if(k == 0 and n%b != 0 and n%b >= k){
            count += n%b - k;
        }
        //printf("b %lld count %lld\n", b, count);
    }
    cout << count << endl;
    return 0;
}