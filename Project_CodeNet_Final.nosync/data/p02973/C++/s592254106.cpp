#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

int LIS(vector<int> A){
    int N=A.size();
    vector<int> D;
    for(int i=0;i<N;i++){
        int pos=distance(D.begin(),upper_bound(D.begin(), D.end(),A[i]));
        if(pos==D.size()){
            D.push_back(A[i]);
        }else{
            D[pos]=A[i];
        }
    }
    return D.size();
}

signed main(void){
    int N;
    int a[114514];
    vector<int> A;
    cin >> N;
    REP(i,N){
        cin  >> a[i];
    }
    REP(i,N){
        A.push_back(a[N-1-i]);
    }
    int Ans=LIS(A);
    cout << Ans << endl;
    return 0;
}

