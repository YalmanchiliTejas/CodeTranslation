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

signed main(){
    int L;
    string S,T;
    cin>>L>>S>>T;

    if(S>T)swap(S,T);

    if(S.size()<=T.size()&&T.substr(0,S.size())==S){
        if(S+T>T+S)swap(S,T);
    }


    int ma=0;
    for(int i=0;i*S.size()<=L;i++){
        int tmp=L-(int)S.size()*i;
        if(tmp%T.size()==0)ma=i;
    }

    rep(i,ma)cout<<S;
    int tmp=L-ma*(int)S.size();
    tmp/=T.size();
    rep(i,tmp)cout<<T;
    cout<<endl;
    return 0;
}
