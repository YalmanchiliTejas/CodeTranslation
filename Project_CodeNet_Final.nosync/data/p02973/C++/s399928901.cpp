#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << "NO" << endl;return 0
#define MM <<" "<<
#define Endl endl

int LIS(vector<int> A){
    int N=A.size();
    vector<int> D;
    for(int i=0;i<N;i++){
        int pos=distance(D.begin(),lower_bound(D.begin(), D.end(),A[i]+1));
        if(pos==D.size()){
            D.push_back(A[i]);
        }else{
            D[pos]=A[i];
        }
    }
    return D.size();
}

signed main(void){
    int N,a;
    vector<int> A;
    cin >> N;
    REP(i,N){
        cin >> a;
        A.push_back(a);
    }
    reverse(A.begin(),A.end());
    cout << LIS(A) << endl;
    return 0;
}
