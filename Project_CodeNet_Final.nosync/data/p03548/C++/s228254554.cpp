#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define UNIQUE(v) v.erase(unique(all(v)),v.end());
#define fill(a,x) memset(a,x,sizeof(a))
#define zero(a) fill(a,0)
#define minus(a) fill(a,-1)
#define dbg(x) cout << #x"=" << x << endl

const int INF=INT_MAX/3;
const int LIMIT=100;

int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};

ll x,y,z;
string s;
int ans;

int main(){
    cin>>x>>y>>z;
    FOR(i,1,x){
        if(i*y+(i+1)*z<=x)ans++;
    }
    cout<<ans<<endl;
    return 0;
}