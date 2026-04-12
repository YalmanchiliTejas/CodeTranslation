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
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    int N;cin >> N;
    int A[N];
    REP(i,N) cin >> A[i];
    vector<int> V;
    V.pb(A[0]);
    REPP(i,1,N){
        int left = -1,right = V.size(),tmp;
        while(right - left > 1){
            int mid = left + (right - left) / 2;
            if(mid == V.size()-1 && V[mid] >= A[i]){
                V.pb(A[i]);
                tmp = -1;
                break;
            }
            else if(V[mid] >= A[i]){
                left = mid;
            }
            else if(V[mid] < A[i]){
                right = mid;
                tmp = mid;
            }
        }
        if(tmp != -1) V[tmp] = A[i];
    }
    cout << V.size() << endl;
}