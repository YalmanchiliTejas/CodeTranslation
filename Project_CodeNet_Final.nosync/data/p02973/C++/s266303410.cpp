#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define vii vector<int>
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define pldld pair<long long double, long long double>
#define ff first
#define ss second
#define pb push_back
#define read freopen("alu.txt","r",stdin);
#define write freopen("vorta.txt","w",stdout);
#define fastio ios::sync_with_stdio(false); cin.tie(NULL);
#define PI 2*acos(0.0)
#define DEBUG(x) cerr << #x << " = " << x << endl

const int MAX = 3e5 + 5, MOD = 1e9 + 7, MAXLG = log2(MAX)+1;
const ll inf = 1e18 + 5;

int arr[MAX];
int mx = 0;
void compress(int n){
    vii v;
    for(int i=0;i<n;i++) v.pb(arr[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<n;i++){
        int zipped=lower_bound(v.begin(),v.end(),arr[i])-v.begin()+1;
        arr[i]=zipped;
        mx=max(mx,zipped);
    }
}

int bit[MAX];
void update(int pos, int val){
    while(pos <= mx){
        bit[pos] = max(bit[pos], val);
        pos += (pos & (-pos));
    }
}

int get(int pos){
    int ret = 0;
    while(pos > 0){
        ret = max(ret, bit[pos]);
        pos -= (pos & (-pos));
    }
    return ret;
}

int col[MAX];
int main(){

    fastio;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>arr[i];
    compress(n);

    for(int i=n-1; i>=0; i--){
        int g = get(arr[i]);
        col[i] = g + 1;
        update(arr[i], g + 1);
//        cout<<g<<" "<<col[i]<<" "<<get(arr[i])<<"\n";
    }

    int ans = 0;
    for(int i=0; i<n; i++){
//        cout<<col[i]<<" ";
        ans = max(ans, col[i]);
    }
//    cout<<"\n";
    cout<<ans<<"\n";

}
