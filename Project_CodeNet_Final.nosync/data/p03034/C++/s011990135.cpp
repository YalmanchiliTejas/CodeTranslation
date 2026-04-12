#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<ll,ll> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
ll n,ans=0,x[100005],s,a,b;
int main(void){
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i];
    for(int i=1;i<n;i++){
		s=0,a=0,b=n-1;
		while(a<n-i){
			if(a==b||a-i==b)break;
			s+=x[a];
			s+=x[b];
			ans=max(ans,s);
			a+=i;
			b-=i;
		}
	}
	cout<<ans<<endl;
}