#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define f first
#define s second
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>> 
#define pb push_back

void solve() {
	int x;
	cin>>x;
	if(x>=30) {
		cout<<"Yes\n";
	}
	else cout<<"No\n";
}
 
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("ou.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc=1;
    //cin>>tc;
    for(int t=1;t<=tc;t++) {
        //cout<<"Case #"<<t<<": ";
        solve();
    }
    return 0;
}