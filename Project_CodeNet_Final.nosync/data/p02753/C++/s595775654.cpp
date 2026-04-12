#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define rev(a) (a).rbegin(),(a).rend()
#define pll pair<ll,ll>
#define rep(i,a,b) for(long long i = (a); i <= (b); i++)

const int mod = 1e9+7;
const int N = 1e5+5; 

int main(){
	fast;
	ll t = 1; 
	//cin >> t;
	while(t--){
	    string s; cin >> s;
	    set<char> st;
	    for(auto x : s){
	        st.insert(x);
	    }
	    
	    if(st.size() > 1) cout << "Yes\n";
	    else cout << "No";
	}
}