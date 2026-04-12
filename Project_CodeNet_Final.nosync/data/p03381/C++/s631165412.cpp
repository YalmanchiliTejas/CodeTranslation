#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1e9+7;
const LL LINF=1LL<<62;

int main(){
    int N;
    cin >> N;
    vector<LL> X;
    for(int i=0;i<N;i++){
        LL x;
        cin >> x;
        X.pb(x);
    }
    vector<LL> t;
    t=X;
    sort(ALL(X));
    map<LL,LL> ma;
    for(int i=0;i<N;i++){
        if(i<N/2) ma[X[i]]=X[N/2];
        else ma[X[i]]=X[N/2-1];
    }
    for(int i=0;i<N;i++){
        cout << ma[t[i]] << endl;
    }
    return 0;
}