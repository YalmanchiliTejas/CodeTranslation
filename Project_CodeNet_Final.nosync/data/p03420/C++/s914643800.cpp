#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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

/*

*/

ll n,k,ans=0;

int main(void){
	cin>>n>>k;
	reg(b,k+1,n){
		if(k==0){
			ans+=(b-k)*(n/b)+max(n-n/b*b-k+1,(ll)0)-1;//0はダメ
		}else{
			ans+=(b-k)*(n/b)+max(n-n/b*b-k+1,(ll)0);
		}
	}
	cout<<ans<<endl;
	return 0;
}