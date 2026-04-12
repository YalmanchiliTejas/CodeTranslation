#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    ll res=0;
    if(x==0||m==1){
        cout << 0 << endl;
        return 0;
    }
    if(n==1){
        cout << x << endl;
        return 0;
    }
    ll memo1;
    map<ll,ll> mp;
    vector<ll> cal;
    cal.push_back(x);
    mp[x]++;
    res+=x;
    for(ll i=2;i<=min(n,1000000LL);i++){
        ll count=(cal[cal.size()-1]*cal[cal.size()-1])%m;
        cal.push_back(count);
        res+=count;
        mp[count]++;
        if(count==0||i==n){
            cout << res << endl;
            return 0;
        }
        if(mp[count]>=2){
            memo1=i;
            memo1--;
            break;
        }
    }
    ll memo2=cal[memo1];
    ll memo3;
    for(ll i=0;i<ll(cal.size());i++){
        if(cal[i]==memo2){
            memo3=i;
            break;
        }
    }
    ll count1=0,count2=0,count3=0;
    for(ll i=0;i<=memo3;i++){
        count1+=cal[i];
    }
    for(ll i=memo3+1;i<=memo1;i++){
        count2+=cal[i];
    }
    ll memo4=(n-memo3-1)/(memo1-memo3);
    ll memo5=(n-memo3-1)%(memo1-memo3);
    for(ll i=memo3+1;i<memo3+1+memo5;i++){
        count3+=cal[i];
    }
    cout << count1+count2*memo4+count3 << endl;
    return 0;
}  
