#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin()) //ai>=v  x is sorted
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin()) //ai>v  x is sorted
#define NUM(x,v) (POSU(x,v)-POSL(x,v))  //x is sorted
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
#define TO(x,t,f) ((x)?(t):(f))
#define CLR(mat) memset(mat, 0, sizeof(mat))
#define FILV(x,a) fill(x.begin(),x.end(),a)
#define FILA(ar,N,a) fill(ar,ar+N,a)
#define NEXTP(x) next_permutation(x.begin(),x.end())
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(a%b==0)return b;else return gcd(b,a%b);}
ll lcm(ll a,ll b){ll c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define pb push_back
#define pri(aa) cout<<(aa)<<endl
const ll INF=1e9+7;
const ll N = 100001;
const ll W = 1;
const ll S = 0;
int n,ani[N];
string s;

void animal(int a1,int a2){
	ani[0]=a1;ani[1]=a2;
	FOR(i,2,n){
		if(ani[i-1]==W && s[i-1]=='o'){
			if(ani[i-2]==W)ani[i]=S;
			else ani[i]=W;
		}else if(ani[i-1]==W && s[i-1]=='x'){
			if(ani[i-2]==W)ani[i]=W;
			else ani[i]=S;
		}else if(ani[i-1]==S && s[i-1]=='o'){
			if(ani[i-2]==W)ani[i]=W;
			else ani[i]=S;
		}else if(ani[i-1]==S && s[i-1]=='x'){
			if(ani[i-2]==W)ani[i]=S;
			else ani[i]=W;
		}
	}
}
void priani(){
	FOR(i,0,n){
		if(ani[i]==W)cout<<'W';
		else cout<<'S';
	}
	cout<<endl;
}

bool nop(int x){
	int y=x-1;if(y<0)y=n-1;
	int z=x+1;if(z==n)z=0;
	if(s[x]=='o'&&ani[x]==S){
		if(ani[y]==ani[z])return true;
	}
	if(s[x]=='x'&&ani[x]==S){
		if(ani[y]!=ani[z])return true;
	}
	if(s[x]=='o'&&ani[x]==W){
		if(ani[y]!=ani[z])return true;
	}
	if(s[x]=='x'&&ani[x]==W){
		if(ani[y]==ani[z])return true;
	}
	return false;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>s;
	animal(W,W);
	if(nop(0)&&nop(n-1)){
		priani();
		return 0;
	}
	animal(W,S);
	if(nop(0)&&nop(n-1)){
		priani();
		return 0;
	}
	animal(S,W);
	if(nop(0)&&nop(n-1)){
		priani();
		return 0;
	}
	animal(S,S);
	if(nop(0)&&nop(n-1)){
		priani();
		return 0;
	}
	pri(-1);
	return 0;
}
