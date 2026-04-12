#include <bits/stdc++.h>
using namespace std;

int main(void){
    long n, k;
    cin >> n >> k;
    long ret = 0;
    for(long b=k+1; b<=n; b++){
        long c = n/b;
        if(k==0){
            ret--;
        }
        ret += c*(b-k);
        long t = n-(c*b+k-1);
        ret += t>0 ? t : 0;
        //printf("%ld %ld\n", b, ret);
    }
    cout << ret << endl;
    return 0;
}
