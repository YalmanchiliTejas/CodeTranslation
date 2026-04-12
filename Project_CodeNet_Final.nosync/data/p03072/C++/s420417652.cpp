#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	int n, ans=1; cin>>n;
	int alt[n]; 
	for (int i = 0; i<n; i++){
		cin>>alt[i];
	}
	int m = alt[0];
	for(int i=1; i<n; i++){
		if(alt[i]>=m){
			ans++;
			m=alt[i];
		}
	}
	cout<<ans<<endl;
}
