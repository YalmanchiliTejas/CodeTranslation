#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int n; string s;
//0...羊 1..狼
void solve(int s0, int s1){
    vector <int> ans(n);
    ans[0] = s0, ans[1] = s1;
    for(int i=2;i<n;i++){
        if(ans[i-1]==0){
            if(s[i-1] == 'o') ans[i] = ans[i-2];
            else ans[i] = 1 - ans[i-2];
        }else{
            if(s[i-1] == 'o') ans[i] = 1 - ans[i-2];
            else ans[i] = ans[i-2];
        }
    }
    for(int i=0;i<n;i++){
        int mae, next;
        if(i==0) mae = n-1, next = 1;
        else if(i==n-1) mae = n-2, next = 0;
        else mae = i-1, next = i+1;
        if(ans[i]==0){
            if(s[i] == 'o'){
                if(ans[mae] != ans[next]) return;
            }else{
                if(ans[mae] == ans[next]) return;
            }
        }else{
            if(s[i] == 'o'){
                if(ans[mae] == ans[next]) return;
            }else{
                if(ans[mae] != ans[next]) return;
            }
        }
    }
    rep(i,n){
        if(ans[i] == 0) cout<<'S';
        else cout<<'W';
    }
    exit(0);
}
signed main(void){
    cin>>n>>s;
    
    solve(0,0); solve(0,1); solve(1,0); solve(1,1);
    cout<<-1<<endl;
}
