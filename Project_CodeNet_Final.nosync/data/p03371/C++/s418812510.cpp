#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define downque(que)  priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;
typedef long long ll;
const int MOD = 1e9+7;



int main(){
 ll a,b,c,x,y; cin>>a>>b>>c>>x>>y;
 ll p=a+b;
 ll res=0;
 if(p<=2*c)res+=a*x+b*y;
 else{
 res=min(x,y)*2*c;
 res+=(x-min(x,y))*min(a,2*c);
 res+=(y-min(x,y))*min(b,2*c);
 }
 cout<<res<<endl;
 
}