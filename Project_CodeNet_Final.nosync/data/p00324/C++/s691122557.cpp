#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N;
int A[222222];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i+1],A[i+1]+=A[i];

    map<int,int>cnt;cnt[0]=0;
    int ma=0;
    for(int i=1;i<=N;i++){
        if(cnt.find(A[i])!=cnt.end()){
            chmax(ma,i-cnt[A[i]]);
        }
        else{
            cnt[A[i]]=i;
        }
    }

    cout<<ma<<endl;
    return 0;
}