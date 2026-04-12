#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e18+7;

ll N,X;
ll brg[55];
ll pat[55];
ll ans;

ll eat(ll level,ll x){

	if(level==1){
		if(x<=1){
			return 0;
		}
		if(x==2){
			ans++;
			return 0;
		}
		if(x==3){
			ans+=2;
			return 0;
		}
		if(x>=4){
			ans+=3;
			return 0;
		}
	}
	ll m=brg[level];
	ll b=(m+1)/2;
	if(x==m){
		ans+=(2*pat[level-1]+1);
		return 0;
	}
	if(x==m-1){
		ans+=(2*pat[level-1]+1);
		return 0;
	}
	if((x<m-1)&&(x>b)){
		ans+=(pat[level-1]+1);
		return eat(level-1,x-b);
	}
	if(x==b){
		ans+=(pat[level-1]+1);
		return 0;
	}
	if(x==b-1){
		ans+=pat[level-1];
		return 0;
	}
	if(x<b-1){
		return eat(level-1,x-1);
	}
	return 0;

}

int main(){ 

cin.tie(0);
ios::sync_with_stdio(false);

cin>>N>>X;

brg[0]=1;
for(int i=1; i<=N; i++){
	brg[i]=2*brg[i-1]+3;
}
pat[0]=1;
for(int i=1; i<=N; i++){
	pat[i]=2*pat[i-1]+1;
}

eat(N,X);

cout<<ans<<endl;

}
