#include <cstdio>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

long long n;
long long a[52];
int main(){
    scanf("%d", &n);
    long long Sum = 0, ok = 0, Sol = 0;
    for(int i = 1; i <= n ; ++i)
        scanf("%lld", &a[i]);
    while(ok == 0){
        ok = 1; Sum = 0;
        for(int i = 1; i <= n ; ++i){
            if(a[i] >= n){
                Sum = Sum + a[i] / n;
                a[i] = a[i] % n - a[i] / n;
                ok = 0;
            }
        }
        for(int i = 1; i <= n ; ++i)
            a[i] = a[i] + Sum;
        Sol += Sum;
    }
    printf("%lld", Sol);
    return 0;
}
