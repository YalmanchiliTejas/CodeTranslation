#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

#define CIN_ONLY if(1)
struct cww{cww(){
    CIN_ONLY{
        ios::sync_with_stdio(false);cin.tie(0);
    }
}}star;
#define fin "\n"
#define FOR(i,bg,ed) for(int i=(bg);i<(ed);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define DEBUG if(0)
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l,T r)
{bool a=l>r;if(a)l=r;return a;}
template <typename T>inline bool chmax(T &l,T r)
{bool a=l<r;if(a)l=r;return a;}
template <typename T>
istream& operator>>(istream &is,vector<T> &v){
    for(auto &it:v)is>>it;
    return is;
}

LL f(vector<LL> a){
    LL top=-114514;
    for(auto &it:a)chmax(top,it);
    return top;
}
int main(){
    int N;
    cin>>N;
    vector<LL> a(N);
    cin>>a;
    LL K=0;
    while(f(a)>1000){
        //cout<<f(a)<<" ";
        LL p=0;
        vector<LL> q(N);
        REP(i,N){
            LL nxt=a[i]%N;
            q[i]=(a[i]-nxt)/N;
            p+=q[i];
            a[i]=nxt;
        }
        REP(i,N){
            a[i]+=p-q[i];
        }
        K+=p;
        //cout<<f(a)<<endl;
    }
    while(f(a)>=N){
        sort(ALL(a));
        a.back()-=N+1;
        REP(i,N)a[i]++;
        K++;
    }
    cout<<K<<endl;
    return 0;
}
