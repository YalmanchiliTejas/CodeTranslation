#include <bits/stdc++.h>
using namespace std;

using i64=int64_t;

#define rep(i,x,y) for(i64 i=i64(x),i##_max_for_repmacro=i64(y); i<i##_max_for_repmacro; ++i)
#define debug(x) #x << "=" << (x)
 
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif
 
const int inf=1.01e9;
const i64 inf64=4.01e18;
const double eps=1e-9;
 
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
        os << v << ",";
    }
    os << "]";
    return os;
}

void solve(){
    int N,M;
    cin >> N >> M;
    int S,T;
    cin >> S >> T;
    --S;
    --T;

    vector<vector<pair<int,i64>>> graph(N);
    rep(i,0,M){
        int U,V;
        i64 D;
        cin >> U >> V >> D;
        --U;
        --V;
        graph[U].push_back(make_pair(V,D));
        graph[V].push_back(make_pair(U,D));
    }

    i64 mod=1000000007;
    vector<i64> dist1(N,inf64),count1(N);
    priority_queue<pair<i64,int>,vector<pair<i64,int>>,greater<pair<i64,int>>> que;
    dist1[S]=0;
    count1[S]=1;
    que.push(make_pair(0,S));
    while(!que.empty()){
        auto tmp=que.top();
        que.pop();
        int u=tmp.second;
        i64 du=tmp.first;
        if(du>dist1[u]) continue;
        for(auto &e:graph[u]){
            int v=e.first;
            i64 d=e.second;
            if(du+d==dist1[v]){
                count1[v]+=count1[u];
                count1[v]%=mod;
                continue;
            }
            if(du+d>dist1[v]) continue;
            dist1[v]=du+d;
            count1[v]=count1[u];
            que.push(make_pair(dist1[v],v));
        }
    }
    
    vector<i64> dist2(N,inf64),count2(N);
    dist2[T]=0;
    count2[T]=1;
    que.push(make_pair(0,T));
    while(!que.empty()){
        auto tmp=que.top();
        que.pop();
        int u=tmp.second;
        i64 du=tmp.first;
        if(du>dist2[u]) continue;
        for(auto &e:graph[u]){
            int v=e.first;
            i64 d=e.second;
            if(du+d==dist2[v]){
                count2[v]+=count2[u];
                count2[v]%=mod;
                continue;
            }
            if(du+d>dist2[v]) continue;
            dist2[v]=du+d;
            count2[v]=count2[u];
            que.push(make_pair(dist2[v],v));
        }
    }

    i64 ans=count1[T]*count1[T]%mod,k=dist1[T];
    rep(u,0,N){
        print(u);
        print(ans);
        for(auto& e:graph[u]){
            int v=e.first;
            i64 d=e.second;
            if(dist1[u]+d+dist2[v]!=k) continue;
            if(not(2*dist1[u]<k and k<2*(dist1[u]+d))) continue;
            ans-=count1[u]*count2[v]%mod*count1[u]%mod*count2[v]%mod;
            ans+=mod;
            ans%=mod;
        }
        print(ans);
        if(2*dist2[u]==k and 2*dist1[u]==k){
            ans-=count1[u]*count2[u]%mod*count1[u]%mod*count2[u]%mod;
            ans+=mod;
            ans%=mod;
        }
        print(ans);
    }
        
    cout << ans << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}
