#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
const int MAX=1e5+10;
 
 
 
int main(){
	int N;
	cin>>N;
	ll s[MAX];
	rep(i,N)cin>>s[i];
	
	ll ans=0;
	
	rep1(d,N-2){
		ll pa=0;
		int l=0,r=N-1;
		if((N-1)%d){
			while(r>d){
				pa=pa+s[l]+s[r];
				ans=max(ans,pa);
				l+=d;
				r-=d;
			}
		}
		else{
			while(l<r){
				pa=pa+s[l]+s[r];
				ans=max(ans,pa);
				l+=d;
				r-=d;
			}
		}
	}
	cout<<ans<<endl;
}