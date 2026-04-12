#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
//#include <chrono> //1e+9で割る auto end= chrono::system_clock::now()-st;  cout<<end.count()%1e+9<<endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
typedef long double db;

#define fr first
#define sc second
#define pb push_back
#define rep(i,x) for(int i=0;i<x;i++)
#define rep1(i,x) for(int i=1;i<=x;i++)
#define rrep(i,x) for(int i=x-1;i>=0;i--)
#define rrep1(i,x) for(int i=x;i>0;i--)

ll N,K;
ll ans;
ll x;
int main()
{
	cin>>N>>K;
	if(K==0){
		ans=N*N;
	}
	else{
		ans=N*N;
		ll a=0,r=0;
		rep1(m,N){
			r=0;
			x=min((ll)(m-1),K-1); //N以下で mでわった あまり x以下
			if(x==0){
				r=N/m;
			}
			else{
				r+=(N/m)*(x+1);
				r+=min(N%m,x);
			}
			a+=r;
		}
		ans-=a;
		
	}
	cout<<ans<<endl;
}