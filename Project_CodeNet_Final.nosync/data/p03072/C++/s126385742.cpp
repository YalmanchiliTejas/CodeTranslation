#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll>
#define vvl vector<vl >
#define pl pair<ll,ll>
#define vpl vector<pl >
#define vvpl vector<vp >
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define wt ll tc; cin>>tc; while(tc--)
#define ft ll tc,ti; cin>>tc; for(ti=1;ti<=tc;ti++)
#define fd(c,element) ((c).find(element)!=(c).end())
#define fdv(c,element) (find(all(c),element)!=(c).end())
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair

int main() {
    fio;
    ll i,j,n,c=0;
    cin>>n;
    ll a[n],m[n-1];
    for(i=0;i<n;i++) cin>>a[i];
    m[0]=a[0];
    for(i=1;i<n-1;i++) m[i]=max(m[i-1],a[i]);
    for(i=1;i<n;i++) {
    	if(m[i-1]<=a[i]) c++;
    }
    cout<<c+1;
}