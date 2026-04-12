#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

#define int long long

#define override_rep(i, l, r, mes, ...) mes
#define rep1(i, n) for (int i = 0; i < n; i++)
#define rep2(i, l, r) for (int i = l; i < r; i++)
#define rep(...) override_rep(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

using namespace std;

using P = std::pair<int, int>;
using ll = long long;
using ld = double;

using bint = boost::multiprecision::cpp_int;


template<typename T, typename U>
std::istream& operator>>(std::istream& in, std::pair<T, U>& p) {
    in >> p.first >> p.second;
    return in;
}

const int MOD = 998244353;

// https://twitter.com/vane11ope ←フォローしましょう
// (ノ)>◡<(ヾ)ﾓﾁﾓﾁ
signed main(signed argc, char* argv[]) {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n,x,m;
    cin>>n>>x>>m;
    vector<int> a(m+1,0);
    a[0]=x;
    int memo,sum=x;
    map<int,int> mp;
    mp[x]=0;
    rep(i,1,1+m){
        a[i]=a[i-1]*a[i-1]%m;
        if(mp[a[i]]){
            memo=i;
            break;
        }
        if(a[i]==0){
            cout<<sum<<endl;
            return 0;
        }
        sum+=a[i];
        mp[a[i]]=i;
    }

    int ans=0;
    rep(i,min(mp[a[memo]],n)){
        ans+=a[i];
    }
    sum=0;
    rep(i,mp[a[memo]],memo){
        sum+=a[i];
    }
    if(memo==mp[a[memo]]){
        ans+=max(0ll,n-mp[a[memo]])*a[memo];
    }
    else{
    ans+=(max(n-mp[a[memo]],0ll))/(memo-mp[a[memo]])*sum;
        rep(i, max(n - mp[a[memo]], 0ll) % (memo - mp[a[memo]] )) {
            ans += a[i + mp[a[memo]]];
        }

    }
    cout<<ans<<endl;
}
