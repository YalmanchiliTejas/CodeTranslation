#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    ll N,X,M; cin >> N >> X >> M;
    vector<ll> tmp;
    tmp.push_back(X);
    bool used[M+10]={};
    used[X]=true;
    ll res=X;
    ll next;
    while(true){
        next=(res*res)%M;
        if(used[next]) break;
        tmp.push_back(next);
        res=next;
        used[next]=true;
    }
    vector<ll> cur;
    bool flag=false;
    ll ans=0;
    int ind;
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]==next){
            ind=i;
        }
    }
    for(int i=0;i<tmp.size();i++){
        if(i<ind) ans+=tmp[i];
        else cur.push_back(tmp[i]);
    }
    for(int i=1;i<cur.size();i++){
        cur[i]+=cur[i-1];
    }
    ans+=((N-ind)/cur.size())*cur[cur.size()-1];
    ll m=(N-ind)%cur.size();
    if(m!=0) ans+=cur[m-1];
    cout << ans << endl;
}