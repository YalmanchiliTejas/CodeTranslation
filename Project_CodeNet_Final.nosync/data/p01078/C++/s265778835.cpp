#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back

using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using ld=long double;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int main(){
	ld n=read(),k=read();
	ld ans=sin(M_PI*2.0/n)/2;
	ld a=sin(M_PI/n);
	ld b=a/tan(M_PI*(0.5-(k-1)/n));
	ans-=a*b;
	cout<<fixed<<setprecision(10)<<ans*n<<endl;
}