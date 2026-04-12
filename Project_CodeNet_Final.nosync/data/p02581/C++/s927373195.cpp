#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ALL(obj) (obj).begin(),(obj).end()
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T> inline void chmax(T& a, const T b){a=max(a,b);}

array<int,6000> A;
array<int,2000> B;
array<int,2000*2000> dp;

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    constexpr int inf = 12345678;
    int N; cin >> N;
    for(int i = 0; i < 3*N; ++i) cin >> A[i],A[i]--;
    corner(N==1,A[0]==A[1]&&A[1]==A[2]);

    for(int i=0;i<N*N;++i) dp[i]=-inf;
    for(int i=0;i<N;++i) B[i]=-inf;
    int ans=0,maxi=0;
    array<int,5> v;
    for(int i = 0; i < 5; ++i) v[i]=A[i];
    sort(ALL(v));
    do{
        int u = (v[2]==v[3]&&v[3]==v[4]);
        chmax(dp[v[0]*N+v[1]],u);
        chmax(maxi,u);
        chmax(B[v[0]],u);
        chmax(B[v[1]],u);
    } while(next_permutation(ALL(v)));

    for(int i=5; i+2 < 3*N; i+=3) {
        int& a=A[i];
        int& b=A[i+1];
        int& c=A[i+2];
        if(a==b&&b==c) {
            ans++;
            continue;
        }
        stack<pair<int,int>> vp;
        if(a==b) {
            for(int j=0;j<N;++j) {
                vp.emplace(c*N+j,max(dp[a*N+j]+1,B[j]));
            }
        }
        else {
            for(int j=0;j<N;++j) {
                vp.emplace(c*N+j,B[j]);
            }
        }
        if(b==c) {
            for(int j=0;j<N;++j) {
                vp.emplace(a*N+j,max(dp[b*N+j]+1,B[j]));
            }
        }
        else{
            for(int j=0;j<N;++j) {
                vp.emplace(a*N+j,B[j]);
            }
        }
        if(c==a) {
            for(int j=0;j<N;++j) {
                vp.emplace(b*N+j,max(dp[c*N+j]+1,B[j]));
            }
        }
        else{
            for(int j=0;j<N;++j) {
                vp.emplace(b*N+j,B[j]);
            }
        }
        {
            vp.emplace(b*N+c,max(dp[a*N+a]+1,maxi));
        }
        {
            vp.emplace(c*N+a,max(dp[b*N+b]+1,maxi));
        }
        {
            vp.emplace(a*N+b,max(dp[c*N+c]+1,maxi));
        }
        while(vp.size()) {
            auto p = vp.top(); vp.pop();
            int s=p.first/N,t=p.first%N,u=p.second;
            chmax(dp[s*N+t],u);
            chmax(dp[t*N+s],u);
            chmax(maxi,u);
            chmax(B[s],u);
            chmax(B[t],u);
        }
    }
    int& l=A[3*N-1];
    chmax(maxi,dp[l*N+l]+1);
    ans += maxi;
    cout << ans << endl;
    return 0;
}
