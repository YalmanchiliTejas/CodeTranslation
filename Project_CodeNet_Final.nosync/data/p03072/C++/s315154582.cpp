#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
#define era(t) t.erase(unique(be(t)),t.end())
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
typedef long long ll;
using namespace std;
const ll mod=1000000007,mod9=1000000009;
template <class T>inline T lcm(T a,T b){return (a*b/__gcd(a,b));}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(i){
            if(a[i]>=m){
                m=a[i];
                ans++;
            }
        }
        else{
            ans++;
            m=a[i];
        }
    }
    cout << ans<<endl;
    return 0;
}
