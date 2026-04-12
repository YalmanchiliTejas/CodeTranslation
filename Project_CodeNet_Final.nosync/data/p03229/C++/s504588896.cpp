#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 10000
#define nil -1
#define vmax 10000
#define sentinel 2000000000
constexpr long long int inf = 1000000000000;
constexpr long long int rinf = -(INT64_MAX);

int main() {
    cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin>>n;
    ll ans=0;
    vector<int> a(n,0);
    rep(i,n) {
        cin>>a[i];
    }
    SORT(a);
    if(n%2==0){
        for(int i=0;i<n/2-1;i++){
            ans-=2*a[i];
        }
        ans+=a[n/2]-a[n/2-1];
        for(int i=n/2+1;i<n;i++){
            ans+=2*a[i];
        }
    }else{
        ll temp1=0,temp2=0;
        for(int i=0;i<n/2;i++){
            temp1-=2*a[i];
        }
        temp1+=a[n/2]+a[n/2+1];
        for(int i=n/2+2;i<n;i++){
            temp1+=2*a[i];
        }
        for(int i=0;i<n/2-1;i++){
            temp2-=2*a[i];
        }
        temp2-=a[n/2-1]+a[n/2];
        for(int i=n/2+1;i<n;i++){
            temp2+=2*a[i];
        }
        ans=max(temp1,temp2);
    }
    cout<<ans<<endl;
    return 0;
}

