#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr int INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

/*
g++ code.cpp
./a.out
*/

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N,M;cin >> N >> M;
    int A[M],B[M];
    vector<int> V[N];
    REP(i,M){
        cin >> A[i] >> B[i];--A[i];--B[i];
        V[A[i]].pb(B[i]);V[B[i]].pb(A[i]);
    }
    vector<int> num(N);
    iota(num.begin(),num.end(),0);
    int ans = 0;
    do{
        int C = 1;
        while(C <= N-1){
            REP(i,V[num[C-1]].size()){
                if(V[num[C-1]][i] == num[C]){
                    C++;
                    break;
                }
                else if(i == V[num[C-1]].size()-1){C = INF;break;}
            }
        }
        if(C != INF) ans++;
    }while(next_permutation(num.begin() + 1,num.end()));
    cout << ans << endl;
}