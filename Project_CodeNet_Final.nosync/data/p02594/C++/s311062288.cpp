#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

void solve(int cn) {
    int a,b,c,d,e;
    string s,t,u;
    cin>>a;

    cout<<((a>=30)?"Yes":"No")<<endl;


}


#define SINGLE
int main() {
#ifdef SINGLE
    solve(1);
#else
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        solve(i);
    }
#endif
    return 0;
}
