 #include "bits/stdc++.h"

using namespace std;

#define sp(x) cout<<setprecision(x);
#define all(a) (a).begin(), (a).end()
#define inf 10000000
#define linf INT64_MAX*0.99
#define print(s) cout<<(s)<<endl
#define lint long long
#define FOR(i,a,b) for(lint i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define yes "Yes"
#define no "No"
#define divs 1000000007
#define dive 1000000009

typedef pair<int, int> P;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    lint n, m; cin>>n>>m;
    if(n==m) print(yes);
    else print(no);
    return 0;
}