#include<bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define debug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define IN freopen("in.txt", "r", stdin);
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define int long long
#define se second
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;

const int N = 2e5+10;
int a[N],f[N];

int32_t main(){
    IOS;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n%2==0){
        f[1]=a[1],f[2]=a[2];
        for(int i=2;i<=n/2;i++){
            f[i*2-1]=f[(i-1)*2-1]+a[i*2-1];
            f[i*2]=max(f[(i-1)*2],f[(i-1)*2-1])+a[i*2];
        }
        cout<<max(f[n],f[n-1])<<endl;
        return 0;
    }
    f[1]=a[1],f[2]=a[2],f[3]=a[3];
    for(int i=2;i<=n/2;i++){
        f[i*2+1]=max(f[(i-1)*2-1],max(f[(i-1)*2],f[(i-1)*2+1]))+a[i*2+1];
        f[i*2]=max(f[(i-1)*2-1],f[(i-1)*2])+a[i*2];
        f[i*2-1]=f[(i-1)*2-1]+a[i*2-1];
    }
    cout<<max(f[n-2],max(f[n-1],f[n]))<<endl;
    return 0;
}