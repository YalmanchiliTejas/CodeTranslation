#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFll = 1e18;
#define put(n) cout<<(n)<<endl
#define Cout(n) cout<<(n)
#define rep(i,num,N) for(int(i)=(num);(i)<(N);++(i))
#define rrep(i,num,N) for(int (i)=(num);(i)>(N);--(i))
#define all(v) (v).begin() , (v).end()
#define rall(v) (v).rbegin() , (v).rend()
#define MP make_pair
#define pb(q) push_back(q)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin>>N;
    vector<map<char,int>> alf(N);

    rep(i,0,N){
        string s;
        cin>>s;
        rep(j,0,s.size()){
            ++alf[i][s[j]];
        }
    }
    string ans = "",abc = "abcdefghijklmnopqrstuvwxyz";
    
    rep(i,0,abc.size()){
        int cnt = INF;
        rep(j,0,N){
            cnt = min(alf[j][abc[i]],cnt);
        }
        rep(j,0,cnt) ans += abc[i];
    }

    put(ans);
}