#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> inline bool chmin(T&x,T y){if(x>y){x=y;return true;}return false;}
template<class T> inline bool chmax(T&x,T y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

struct tree{
    size_t n,r,md;
    vector<vector<int>> e;
    vector<int> pa,d,sz;
    explicit tree(int n):n(n),e(n),d(n){}
    explicit tree(string&s):n(s.length()/2+1),e(n),pa(n),d(n),sz(n,1){
        pa[0]=-1;
        int i{};
        stack<int> p;
        p.push(0);
        for(auto c:s){
            if(c=='('){
                pa[++i]=p.top();
                d[i]=p.size();
                e[p.top()].push_back(i);
                p.push(i);
            }
            else{
                sz[pa[p.top()]]+=sz[p.top()];
                p.pop();
            }
        }
        assert(i==n-1);
    }
    void built(bool f=true){
        static int a,b;
        fr(i,n-1){
            cin>>a>>b;
            if(f) --a,--b;
            ++d[a],++d[b];
            add(a,b);
        }
    }
    void pbuilt(bool f=true){
        static int a;
        Fr(i,n-1){
            cin>>a;
            if(f) --a;
            add(a,i,false);
        }
    }
    void add(int a,int b,bool f=true){
        e[a].emplace_back(b);
        if(f) e[b].emplace_back(a);
    }
    template<class T>
    vector<T> square(int i){
        vector<T> ans(3,1);
        ans[1]=2;
        for(auto j:e[i]){
            auto a=move(square<T>(j));
            auto m0=ans.size(),m1=a.size();
            ans.resize(m0+m1-1,0);
            ifr(i0,m0){
                iFr(i1,m1-1) ans[i0+i1]+=ans[i0]*a[i1];
                ans[i0]*=a[0];
            }
        }
        return ans;
    }
    void r_dfs(int i,int p=-1,int D=0){
        pa[i]=p;d[i]=D;md=max(md,(size_t)D);++D;
        for(auto j:e[i]) if(j!=p) r_dfs(j,i,D),sz[i]+=sz[j];
    }
    void r_i(int r_){
        pa.resize(n);d.resize(n);sz.resize(n,1),r=r_;md=0;
        r_dfs(r);
    }
    int r2(){
        r_i(0);
        int m=0,M=0;
        fr(i,n) m=max(m,d[i]);
        fr(i,n) if(d[i]==m) M=i;
        pa.clear(),d.clear();
        r_i(M);
        m=0;
        fr(i,n) m=max(m,d[i]);
        return m;
    }
    bool solve(){
        queue<int> q;
        vector<bool> v(n);
        fr(i,n) if(d[i]==1) q.emplace(i);
        while(!q.empty()){
            int i=q.front(),k{-1},c{};q.pop();
            for(auto&j:e[i]) if(!v[j]) k=j;
            v[k]=true;
            for(auto&j:e[k]){
                --d[j];
                if(d[j]==1) q.emplace(j);
                if(!d[j]) ++c;
            }
            if(c>1) return true;
        }
        return false;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    tree t(n);
    t.built(n);
    puts(t.solve()?"First":"Second");
}