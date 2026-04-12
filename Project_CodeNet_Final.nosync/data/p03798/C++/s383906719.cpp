#include<bits/stdc++.h>
using namespace std;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define range(a) (a).begin(),(a).end()
#define print(A,n) rep(i,0,n){cout<<(i ? " ":"")<<A[i];}cout<<endl;
#define pprint(A,m,n) rep(j,0,m){print(A[j],n);}
const long mod=1e9+7;
const int size=1e5;
const int INF=1e9;
int N;string s,t;
bool d[size];// hituji:0 ookami:1
map<bool,string> trans;
bool judge(bool a,bool b){
	bool r[N];r[0]=a;r[1]=b;
	t=trans[a]+trans[b];
	rep(i,2,N+2){
		r[i%N]=r[(i-2)%N]^r[(i-1)%N]^d[(i-1)%N];
        if(i>=N) continue;
		t+=trans[r[i%N]];
	}
	if(r[0]==a&&r[1]==b) return 1;
	else return 0;
}
int main(){
	cin>>N>>s;
	rep(i,0,N) d[i]=(s[i]=='x');
	trans[0]="S";trans[1]="W";
	rep(i,0,2)rep(j,0,2){
		if(judge(i,j)){
			cout<<t<<endl;
			return 0;
		}
	}cout<<-1<<endl;
}