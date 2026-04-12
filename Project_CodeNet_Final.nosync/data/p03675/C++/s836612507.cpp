#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;
ll MOD = 1e9+7;
//LLONG_MIN



int main(void){
	int n;
	ll a[200002];
	cin>>n;
	reg(i,1,n){
		cin>>a[i];
	}
	int cnt=n;
	bool go=false;
	while(1){
		if(cnt>n)break;
		cout<<a[cnt]<<" ";
		if(cnt==2 && !go){
			cnt=1;
			go=true;
		}else if(cnt==1 && !go){
			cnt=2;
			go=true;
		}else{
			if(go){
				cnt+=2;
			}else{
				cnt-=2;
			}
		}
	}
	cout<<endl;
	return 0;
}