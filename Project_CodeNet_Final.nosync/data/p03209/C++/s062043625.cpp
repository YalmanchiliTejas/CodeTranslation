#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

ll f(int n, ll x){
    if(n==0) return 1;
    else{
        if(x>=pow(2, n+1)) return pow(2,n)+f(n-1, x-pow(2, n+1)+1);
        if(x==pow(2, n+1)-1) return f(n-1,x-2)+1;
        if(x==1) return 0;
        else return f(n-1,x-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    ll X;
    cin>> N>>X;
    cout << f(N,X)<<"\n";
}
