#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n; cin>>n;
	int ans=n*800;
	int r=n/15;
	cout<<ans-r*200<<endl;
}