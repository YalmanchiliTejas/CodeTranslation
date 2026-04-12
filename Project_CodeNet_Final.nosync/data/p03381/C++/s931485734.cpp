#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void READ() {
#define R READ();
#define INFI 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define MEMX(x,num) memset(x,num,sizeof(x))
#define prln(x) cout<<#x<<"="<<x<<endl
#define prt(x) cout<<x<<endl
#define prk(x) x<<" "
#define sz(x) int(x.size())
#define PB(x) push_back(x)
#define LINK(x,y) G[x].PB(y),G[y].PB(x)
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(3);
}
///////////////////////////
const int N=5 +2e5;


int n;
int a[N],b[N];
int main() {
    
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    int m1=b[n/2-1],m2=b[n/2];
    for(int i=0;i<n;i++)
    {
        if(a[i]>m1)cout<<m1<<endl;
        else cout<<m2<<endl;
    }



    return 0;
}
