#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+10;
ll N,X,M;
set<ll> s;
map<ll,ll> m;
ll Add[MAXN];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>X>>M;
    ll A,i;
    for(A=X,i=1;s.find(A)==s.end();A=A*A%M,i++)
        Add[i]=Add[i-1]+A,s.insert(A),m[A]=i;
    ll Pos=m[A];
    ll T=i-Pos,Sum=Add[i-1]-Add[Pos-1];
    ll Ans=(N-Pos+1)/T*Sum+Add[(N-Pos+1)%T+Pos-1];
    cout<<Ans<<endl;
    return 0;
}