#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<long long> d(55, 0);

long long clamp(long long a, long long b, long long c){
    return min(max(a, b), c);
}

long long  patty(int n, long long b, long long e){
    if (b == e)    return 0;
    if (n == 0)    return 1;
    long long l=1;
    l = (l << (n+2)) - 3;

    if (b == 0 && e == l){
        if (d[n] != 0)    return d[n];
    }

    long long ans = 0;
    ans += patty(n-1, clamp(b-1, 0, (l-3)/2-1), clamp(e-1, 0, (l-3)/2));
    ans += (b <= (l-1)/2 && (l-1)/2 < e) ? 1 : 0;
    ans += patty(n-1, clamp(b-(l-1)/2-1, 0, (l-3)/2-1), clamp(e-(l-1)/2-1, 0, (l-3)/2));

    if (b == 0 && e == l){
        d[n] = ans;
    }
    
    return ans;
}

int main(){
    long long n, x;
    cin >> n >> x;
    cout << patty(n, 0, x) << endl;
}