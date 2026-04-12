#include <iostream>
using namespace std;

long long ns[51], ps[51];

long long count(int n, long long x){
    if(n == 0) return (x > 0) ? 1 : 0;

    if(x <= 0) return 0;
    if(x < ns[n-1] + 1) return count(n-1, x-1);
    if(x == ns[n-1] + 1) return ps[n-1];
    if(x == ns[n-1] + 2) return ps[n-1] + 1;
    if(x < 2*ns[n-1] + 2) return ps[n-1] + 1 + count(n-1, x-ns[n-1]-2);
    return ps[n];
}


int main(void){
    ns[0] = 1, ps[0] = 1;
    for(int i = 1; i <= 50; i ++){
        ns[i] = 2*ns[i-1] + 3;
        ps[i] = 2*ps[i-1] + 1;
    }
    
    int n;
    long long x;
    cin >> n >> x;
    cout << count(n, x) << "\n";
}
