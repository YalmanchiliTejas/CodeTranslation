#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    int N, K;
    string S;
    cin >> N >> S >> K;
    for(auto aaa: S){
        if(aaa!=S[K-1]) cout << '*';
        else cout << aaa;
    }
    cout << endl;
    return 0;
}
