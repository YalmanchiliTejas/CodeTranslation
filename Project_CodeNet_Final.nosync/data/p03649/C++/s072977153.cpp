#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int N;
ull A[100];

bool judge(){
    REP(i,N){
        if(A[i] >= N) return false;
    }
    return true;
}

int main(){
    cin >> N;
    REP(i,N){
        ull a;
        cin >> a;
        A[i] = a;
    }

    ull ans = 0;
    while(!judge()){
        vector<ull> num(N);
        ull sum = 0;
        REP(i,N){
            ll a = A[i];
            if(a < N) continue;
            num[i] = (a+1)/N + ((a+1)%N != 0) - 1;
            sum += num[i];
        }
        REP(i,N){
            A[i] = A[i] - num[i]*N + (sum - num[i]);
        }
        ans += sum;
    }

    cout << ans << endl;

    return 0;
}
