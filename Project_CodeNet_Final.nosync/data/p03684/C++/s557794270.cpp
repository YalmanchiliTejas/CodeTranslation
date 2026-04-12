#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int INF=1001001001;
const int INFLL=1001001001001001001ll;
const int mod=1000000007;
inline void am(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

set<pint>xs,ys;
bool used[111111];
signed main(){
    int N;
    cin>>N;
    vint X(N),Y(N);
    rep(i,N){
        cin>>X[i]>>Y[i];
        xs.insert({X[i],i});
        ys.insert({Y[i],i});
    }

    int sum=0;
    priority_queue<pint,vector<pint>,greater<pint>>que;
    que.push({0,0});
    while(que.size()){
        int d,v;
        tie(d,v)=que.top();
        que.pop();
        if(used[v])continue;
        sum+=d;
        used[v]=true;
        xs.erase({X[v],v});
        ys.erase({Y[v],v});

        auto it=xs.lower_bound({X[v],-1});
        if(it!=xs.end()){
            que.push({it->fi-X[v],it->se});
        }
        if(it!=xs.begin()){
            it--;
            que.push({X[v]-it->fi,it->se});
        }

        it=ys.lower_bound({Y[v],-1});
        if(it!=ys.end()){
            que.push({it->fi-Y[v],it->se});
        }
        if(it!=ys.begin()){
            it--;
            que.push({Y[v]-it->fi,it->se});
        }
    }

    cout<<sum<<endl;
    return 0;
}
