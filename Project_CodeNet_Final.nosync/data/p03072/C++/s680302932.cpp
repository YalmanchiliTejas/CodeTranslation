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

const int N=1e5+5;
int mm[N];

int main(){	
	fastio;
	int n;cin>>n;
	FER(i,0,n)cin>>mm[i];
	int mx=-1,c=0;
	FER(i,0,n){
		if(mm[i]>=mx){
			c++;
			mx=mm[i];
		}
	}
	cout<<c<<endl;
	return 0;
}
