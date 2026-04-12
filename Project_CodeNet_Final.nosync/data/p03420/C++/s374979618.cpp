#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<28;
const long long MOD =1000000000+7;
int main(){
	int n,k;
	cin >>n>>k;
	long long ans=0;
	long long turn=0;
	int ruse;
	/*
	find amout of b%a >=k 

	-->a >k and b =>k 

	max::10^10/2
	*/
	for(int i=n;i>k;i--){
		turn=(long long)n/i;
		ruse=n-(int)(turn*i);
		if(ruse >=k ){
			ans+=1+ruse-k;
			if(k==0){
				ans-=1;
			}
		}
		ans+=turn*(i-k);
		//cout<<turn<<"  "<<ruse;
		//cout<<"-"<<ans<<endl;
	}
	cout << ans<< endl;
}
