#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <climits>

using namespace std;
#define inf 0x3f3f3f3f
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
//const int mod=1e9+7;
const int N=1e5+7;
int a,b;
string s[10];

int main(){
    fast;
    int t=1;
    //cin>>t;
    while(t--){
        int x=0;
        cin>>a>>b;
        forn(i,a){
            cin>>s[i];
            forn(j,b){
                x+=(s[i][j]=='#');
            }
        }
        if(x==(a+b-1)) cout<<"Possible"<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
