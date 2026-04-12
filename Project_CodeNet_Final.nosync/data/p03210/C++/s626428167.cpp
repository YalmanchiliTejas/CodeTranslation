// dile a la jardinera que traigo flores

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define sz(x) int(x.size())
#define all(v) (v).begin(),(v).end()
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define FER(i,a,b) for(int i = int(a); i < int(b); ++i)
#define IFR(i,a,b) for(int i = int(a); i >= int(b); i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;


int main(){	
	fastio;
	int n;cin>>n;
	if(n==3||n==5||n==7)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
