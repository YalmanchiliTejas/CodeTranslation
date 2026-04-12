#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;

    ll ans=x;
    ll num=x;
    set<int> s;
    s.insert(x);

    rep(i, n-1){
        num=(num*num)%m;
        // cout<<num<<endl;
        if(num==0){
            cout<<ans<<endl;
            return 0;
        }

        if(s.count(num)==1){
            //count
            // cout<<"in"<<endl;
            ans+=num;
            int cnt=0;
            int st=num;
            ll sum=num;
            while(true){
                cnt++;
                num=(num*num)%m;
                if(num==st) break;
                sum+=num;
            }
            ans+=(sum)*((n-i-2)/cnt);
            ll di=(n-i-2)%cnt;
            rep(j, di){
                num=(num*num)%m;
                ans+=num;
            }
            break;
        }
        s.insert(num);
        ans+=num;
    }

    cout<<ans<<endl;
    return 0;
}