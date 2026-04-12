#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pi 3.1415926536
#define pb push_back
#define N 1000000007
#define M 998244353 
#define INF 1e9
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,i,j,k,t,l;
    cin>>n;
    int a[n+5];
    multiset <ll> m;
    multiset <ll> :: iterator it;
    for(i=0;i<n;i++){
    	cin>>a[i];
    	it  = m.lower_bound(a[i]);
    	if( it == m.begin()){
    		m.insert(a[i]);
		}else{
			it--;
			m.erase(it);
			m.insert(a[i]);
	   }
	}
    cout<<m.size()<<endl;
 }