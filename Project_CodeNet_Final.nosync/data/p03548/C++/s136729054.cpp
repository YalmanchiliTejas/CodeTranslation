#include<bits/stdc++.h>
#define re          return
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define hell        1000000007
#define hell2        1000000009
#define endl        '\n'
#define rep(i,a,b)  for (__typeof(b) i=(a)-((a)>(b));i!=(b)-((a)>(b));i+=1-2*((a)>(b)))
#define PI            3.141592653589793l
#define sz(x)       (int)x.size()
#define fill(c,val) memset(c,val,sizeof(c))
#define LB lower_bound
#define UB upper_bound
using namespace std;
typedef long long ll;
const int inf = (int)1e9 + 123;
const ll infl = (ll)1e18 + 123;
const ll INF=(1LL<<60)-1;
//v.resize(distance(v.begin(),unique(v.begin(),v.end())));
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){ 
	    float x,y,z;
	    cin>>x>>y>>z;
	    cout<<floor((x-z)/(y+z));
	    cout<<endl;
    }
    return 0;
}