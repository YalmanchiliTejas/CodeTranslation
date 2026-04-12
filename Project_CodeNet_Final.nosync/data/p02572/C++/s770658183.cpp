#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<iomanip>
#include<map>
#include<queue>
#include<cmath>
#include<cstdio>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define pai 3.1415926535897932384

using namespace std;
using ll =long long;
using P = pair<int,int>;

#define MOD 1000000007;

int main(int argc, const char * argv[]) {
    
    int N;
    ll A[200000];
    ll AA[200000];
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(i==0) AA[i] = A[i];
        else AA[i] = (A[i] + AA[i-1]) % MOD;
    }
    
    ll Ans=0;
    for(int i=0; i<N; i++){
        Ans += (AA[i] * A[i]) % MOD;
        Ans = (Ans - A[i] * A[i]) % MOD;
        if(Ans < 0) Ans += MOD;
    }
    
    cout << Ans << endl;
    
    return 0;
}
