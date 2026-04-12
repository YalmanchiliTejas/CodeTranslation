#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define pii pair<int, int>
#define vii vector< pair<int,int> >
#define vi vector<int>
#define vvi vector< vector< int> >
#define ss second
#define mod 998244353
#define pb push_back
#define mp make_pair
#define int long long
#define all(a) a.begin(), a.end()
#define inf (1LL<<61)
#define ull unsigned long long
#define trace1(x)                cout<<#x<<": "<<x<<endl
#define trace2(x, y)             cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace4(x, y, z, d)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<" | "<<#d<<": "<<d<<endl

#define trace3(x, y, z)          cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define debug1(x) cerr << #x << ": " << x <<'\n'
#define debug2(x, y) cerr << #x << ": " << x << '\t' << #y << ": " << y <<'\n'
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z <<'\n'
using namespace std;
//int dx[]={1,0,-1, 0};int dy[]={0,1,0, -1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
bool compare(const pair<int,int> &a, 
              const pair<int,int> &b) 
{   
    if(a.ff == b.ff){
        return (b.ss < a.ss);
    }
    return (a.ff<b.ff); 
}

int32_t main()
{
    IOS;
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin); 
    // freopen("output.txt","w",stdout);
    // #endif
    /********************* From here ***********************/
    int n;
    cin >> n;
    vi v;
    rep(i, 0, n){
        int a;
        cin >> a ;
        v.pb(a);
    }
    int cnt = 0;
    for(int i=1;i<n;i++){
        bool fg = true;
        for(int j=0;j<i;j++){
            if(v[j] > v[i]){
                fg = false;
                break;

            }
        }
        if(fg){
            cnt++;
        }

    }
    cout << cnt+1;

}
