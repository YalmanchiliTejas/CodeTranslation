#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

long long n,a[55],cnt=1,t,p;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    while(cnt){
        cnt=0;
        for(int i=1;i<=n;i++){
            p=a[i]/n;
            a[i]%=n;
            for(int j=1;j<=n;j++){
                if(j!=i) a[j]+=p;
            }
            cnt+=p;
        }
        t+=cnt;
    }
    cout << t;
}
