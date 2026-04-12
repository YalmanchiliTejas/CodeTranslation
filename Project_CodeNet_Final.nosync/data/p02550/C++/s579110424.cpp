#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=998244353;
int main(){
    int64_t n,x,m;
    cin>>n>>x>>m;
    int64_t a=x;
    set<int64_t> s;
    s.insert(a);
    vector<int64_t> ans(100001,0);
    ans[0] = a;
    map<int64_t,int> p;
    p[a] = 0;
    int cycle =-1;
    int64_t cycle_value;
    int k;
    for(int64_t i=1;i<n;i++){
        a = (a*a)%m;
        //cout<<a<<endl;
        ans[i]= ans[i-1] + a;
        if(s.count(a)){
            k = p[a];
            cycle = i - p[a];
            cycle_value = ans[i] - ans[p[a]];
            //cout<<k<<" "<<cycle<<" "<<cycle_value<<endl;
            break;
        }
        s.insert(a);
        p[a]=i;
    }
    if(cycle==-1){
        //cout<<"a"<<endl;
        cout<<ans[n-1]<<endl;
    }
    else{
        int64_t reala=0 ;
        if(k!=0){
            reala = ans[k-1];
        } 
        //cout<<reala<<endl;
        reala += (n-k)/cycle * cycle_value;
        int amari = (n-k)%cycle;
        if(amari!=0){
        reala += a;
        }
        rep(i,amari-1){
            a = (a*a)%m;
            reala += a;
        }
        cout<<reala<<endl;
    }
}