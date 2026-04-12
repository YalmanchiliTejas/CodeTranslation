#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> vi;
#define endl '\n'
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--) 
#define fast_io ios_base::sync_with_stdio(0);
#define show(x) cout<<x<<endl;
#define pret(x) cout<<x<<endl; return 0;
#define disp(x) cout<<x<<" ";
#define let(x,y) cout<<x<<" "<<y<<endl;
ll MOD=1e9+7;
const int maxn=2e5+5;

int f(){
	int x;
	cin>>x;
	return (x>=30);
}

int32_t main(){
    fast_io;
    int t=1;
    // cin>>t;
    while(t--){
    	// show(f());

    	// f();

    	if(f()){
    		cout<<"Yes"<<endl;
    	}
    	else cout<<"No"<<endl;
    }
    return 0;
}