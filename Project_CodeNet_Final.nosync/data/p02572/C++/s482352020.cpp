// ABC177-C
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define e_b emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll n,mod=pow(10,9)+7,ans=0;
    cin>>n;
    vector<ll> a(n);
    vector<ll> rui(n,0);
    rep(i,n){
        cin>>a[i];
    }
    for(int i=n-1;i>=1;i=i-1){
        rui[i-1]=rui[i]+a[i];
        rui[i-1]%=mod;
    }
    rep(i,n){
        ll cur=rui[i]*a[i];
        cur%=mod;
        ans+=cur;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}