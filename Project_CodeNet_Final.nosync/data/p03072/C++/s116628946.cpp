#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ii pair<ll,ll>;
#define vi vector<int>;
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fbo find_by_order
#define ook order_of_key
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define fo(i,a,b) for(i = a; i < b; i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void io_set() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int main(){
    IOS
    //io_set();
    ll n, i;
    cin >> n;
    ll a[n], c=1;
    fo(i, 0, n){
        cin >> a[i];
    }
    ll pk=a[0];
    fo(i,1,n){
        pk=max(a[i],pk);
        if(pk==a[i]){
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}