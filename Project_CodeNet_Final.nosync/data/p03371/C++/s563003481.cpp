#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pair<int,int>> vii;
typedef vector<char> vc;
typedef vector<vc> vcc;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
#define in insert
#define mina(a,b) (a)=min((a),(b));
#define maxa(a,b) (a)=max((a),(b));
const int INF = 1e9 + 7;
void solve(){
    int a, b, c, x, y;  cin>>a>>b>>c>>x>>y;
    int ans=INF;
    for(int i = 0; i <= max(x,y); i++){
        ans=min(ans,2*i*c+max(0,x-i)*a +max(0,y-i)*b);
    }
    cout<<ans;
}
int main(){
    int T=1;
    //cin>>T;
    for(int i = 0; i < T; i++) solve(); 
}