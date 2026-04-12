#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    string s;
    ll a[n][26];
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
        cin>>s;
        int m=s.length();
        for(int j=0;j<m;j++){
            a[i][(s[j]-'a')]++;
        }
    }
    string t="";
    ll num;
    for(int i=0;i<26;i++){
        num=1e9;
        for(int j=0;j<n;j++){
            num=min(num,a[j][i]);
        }
        for(int j=0;j<num;j++){
            t+=('a'+i);
        }
    }
    cout << t<<endl;
    return 0;
}
