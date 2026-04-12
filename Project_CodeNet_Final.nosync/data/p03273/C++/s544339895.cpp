#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef pair<int,int> pi;
typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    int a[n][k],h[n],v[k];
    memset(h,0,sizeof(h));
    memset(v,0,sizeof(v));
    string s;
    for (int i=0;i<n;i++) {
        cin>>s;
        for (int j=0;j<k;j++) {
            a[i][j] = (s[j]=='.')?0:1;
            if (a[i][j]) h[i]++,v[j]++;
        }
    }
    for (int i=0;i<n;i++) {
        if (!h[i]) continue;
        for (int j=0;j<k;j++) {
            if (!v[j]) continue;
            if (a[i][j]) cout<<"#";
            else cout<<".";
        }
        cout<<"\n";
    }
}
