#include<iostream>
#include<vector>

using namespace std;
long long l[51];
long long p[51];


long long calc(long long d, long long x){
    if(d == 0) return 1;
    if(x <=  1) return 0;
    else if(x <= l[d - 1] + 1) return calc(d - 1, x - 1);
    else if(x == l[d - 1] + 2) return p[d - 1] + 1;
    else if(x <= 2 * l[d - 1] + 2) return p[d - 1] + 1 + calc(d - 1, x - (l[d - 1] + 2));
    else return p[d];
}

int main(){
    long long n, x, ans = 0;
    cin >> n >> x;
    l[0] = p[0] = 1;
    for(int i = 1; i <=50; i++){
        l[i] = 2 * l[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }
    ans = calc(n, x);
    cout << ans << endl;
    return 0;
}
