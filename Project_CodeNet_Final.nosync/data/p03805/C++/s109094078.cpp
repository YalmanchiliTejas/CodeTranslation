#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
#define endl '\n'
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int N,M;
int ab[10][10];

signed main(){
    cin>>N>>M;
    deque<int> ar(N-1);
    rep(i,N-1)ar.at(i)=i+1;//1~N-1
    rep(i,M){
        int a,b; cin>>a>>b;
        a--; b--;
        ab[a][b]++;
        ab[b][a]++;
    }
    int ans=0;
    do{
        ar.push_front(0);
        bool b=true;
        rep(i,N-1){
            if(ab[ar.at(i)][ar.at(i+1)]==0){
                b=false;
                break;
            }
        }
        ar.pop_front();
        if(b)ans++;
    }while(next_permutation(all(ar)));
    cout<<ans<<endl;
}