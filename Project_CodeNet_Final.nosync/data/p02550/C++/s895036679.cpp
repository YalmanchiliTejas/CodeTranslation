#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    vll a(m*2);

    if(n<10000000){
        ll kani=0;
        vll b(n+2);
        b[0]=x;
        for(int i=0;i<n;i++){
            b[i+1]=b[i]*b[i]%m;
        }
        for(int i=0;i<n;i++){
            kani+=b[i];
        }
        cout << kani << endl;
        return 0;
    }

    a[0]=x;
    rep(i,m*2){
        a[i+1]=a[i]*a[i]%m;
    }

    map<ll,ll> mp;
    int loop_num;
    int loop_end;
    rep(i,m*2){
        if(mp[a[i]]==1){
            loop_num=a[i];
            loop_end=i;
        }
        mp[a[i]]++;
    }

    int loop_start;
    rep(i,m*2){
        if(a[i]==loop_num){
            loop_start=i;
            break;
        }
    }
    ll loop_sum=0;
    for(int i=loop_start;i<loop_end;i++){
        loop_sum+=a[i];
    }

    ll ans=0;
    for(int i=0;i<loop_start;i++){
        ans+=a[i];
    }

    int loop_cnt=loop_end-loop_start;

    ans+=loop_sum*((n-loop_start)/loop_cnt);

    int nokori=(n-loop_start)%loop_cnt;

    for(int i=0;i<nokori;i++){
        ans+=a[loop_start+i];
    }
    
    cout << ans << endl;
}