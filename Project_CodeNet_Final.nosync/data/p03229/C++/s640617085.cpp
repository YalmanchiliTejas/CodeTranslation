#include<bits/stdc++.h>

using namespace std;
#define ll long long
deque<ll>s , f, d , k;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int p; cin >> p;
        s.push_back(p);
    }
    sort(s.begin(),s.end());
    if(n==1){
        cout << 0 << endl;
        return 0;
    }
    f.push_back(s[0]);f.push_back(s[n-1]);
    s.pop_back();s.pop_front();
    while(s.size()>0){
        ll num = f.front();
        ll num2 = f.back();
        int sz = s.size();
        ll k = s[0];
        ll k2 = s[sz-1];
        ll nm = abs(k-num);
        ll nm2 = abs(k-num2);
        ll nm3 = abs(k2-num);
        ll nm4 = abs(k2-num2);
        vector<ll>v;
        v.push_back(nm);v.push_back(nm2);v.push_back(nm3);v.push_back(nm4);
        sort(v.begin(),v.end());
        ll p = v[3];
        if(p == nm){
            f.push_front(k);
            s.pop_front();
        }
        else if(p==nm2){
            f.push_back(k);
            s.pop_front();
        }
        else if(p==nm3){
            f.push_front(k2);
            s.pop_back();
        }
        else{
            f.push_back(k2);
            s.pop_back();
        }
    }
    ll ans = 0;
    for(int i = 0; i<n-1; i++)ans += abs(f[i]-f[i+1]);
    cout << ans << endl;
    return 0;
}
