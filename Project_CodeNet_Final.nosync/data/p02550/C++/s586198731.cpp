#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define full(a) a.begin(),a.end()
#define rfull(a) a.rbegin(),a.rend()

using namespace std;
const double pi=acos(-1.0);
const double pii=2*pi;
const double eps=1e-6;
const long long MOD=1e9+7;

void solve(){
    long long n,x,m;
    cin>>n>>x>>m;
    if(x==0){
        cout<<"0\n";
        return;
    }
    if(x==1){
        cout<<n<<"\n";
        return;
    }
    vector<bool> prev(m,false);
    queue<int> rem;
    long long ax=x,rep=-1,sm=0;

    while(!prev[ax] && n>0){
        n--;
        sm+=ax;
        prev[ax]=true;
        rem.push(ax);
        ax=(ax*ax)%m;
    }
    rep=ax;
    if(n<=0){
        cout<<sm<<"\n";
        return;
    }
    
    while(rem.front()!=rep)
        rem.pop();
    rep=n/(1ll*int(rem.size()));
    n%=(1ll*int(rem.size()));
    long long sm_rem=0,sm_div=0;
    while(!rem.empty()){
        if(n>0){
            sm_rem+=rem.front();
            n--;
        }
        sm_div+=rem.front();
        rem.pop();
    }
    sm+=rep*sm_div+sm_rem;
    cout<<sm<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    solve();
    return 0;
}