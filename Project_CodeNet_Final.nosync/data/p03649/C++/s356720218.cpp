#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 100005
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 998244353;
int main(){
    int n;
    cin>>n;
    vector<ll>a(n);
    REP(i,n)cin>>a[i];
    sort(ALL(a));
    ll cnt=0;
    while(n<=a[n-1]){
        ll tmp=a[n-1]/n;
        a[n-1]-=(ll)tmp*n;
        REP(i,n-1)a[i]+=tmp;
        for(int i=n-1;i>=1;i--){
            if(a[i-1]>a[i])swap(a[i-1],a[i]);
        }
        cnt+=tmp;
    }
    OUT(cnt);
    return 0;
}