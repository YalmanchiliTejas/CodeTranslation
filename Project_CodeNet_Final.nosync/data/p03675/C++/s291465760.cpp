#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+9;
const double eps=1e-6;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
deque<int>q;
VI ans;
int main(){
//    freopen("C-small-attempt1.in","r",stdin);
//    freopen("output.txt","w",stdout);
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(i&1) q.push_back(a);
        else q.push_front(a);
    }
    while(!q.empty()){
        ans.pb(q.back());
        q.pop_back();
    }
    if(n&1) reverse(all(ans));
    for(auto i:ans) cout<<i<<" ";
	return 0;
}
/*
*/
