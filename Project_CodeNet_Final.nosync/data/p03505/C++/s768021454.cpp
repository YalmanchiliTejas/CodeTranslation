#include<bits/stdc++.h>
using namespace std;
#define itn int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) a.begin(),a.end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int INF=1e9;
int main(){
	long K,A,B;cin>>K>>A>>B;
	if(A>=K) cout<<1<<endl;
	else if(A>B) cout<<2*((K-B-1)/(A-B))+1<<endl;
	else cout<<-1<<endl;
}