#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int main(){
int n;
cin>>n;
stack<char> st[n];
while(true){
string op;
int p;
cin>>op;
if(op=="quit")break;
if(op=="push"){
char c;
cin>>p>>c;
--p;
st[p].push(c);
}
if(op=="pop"){
cin>>p;
--p;
char c = st[p].top(); st[p].pop();
cout<<c<<endl;
}
if(op=="move"){
cin>>p;
--p;
char c = st[p].top(); st[p].pop();
cin>>p;
--p;
st[p].push(c);
}

}

  return 0;
}