#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef tuple<ll, ll, ll> T;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x,y,z;
    cin>>x>>y>>z;
    int l=z,ans=0;
    while(l<=x-z){
        if(l+y<=x-z){
            ans++;
            l+=y+z;
        }
        else break;
        //cout<<l<<endl;
    }
    cout<<ans<<endl;
}