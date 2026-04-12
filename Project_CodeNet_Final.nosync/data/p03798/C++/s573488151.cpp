#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

int n;
string s;

void solve(){
	cin>>n;
	cin>>s;
	map<int,char> huh;
	huh[0] = 'S';
	huh[1] = 'W';

	for(int i=0;i<=1;i++){
		for(int j=0;j<=1;j++){
			string ans;
			ans += huh[i];
			ans += huh[j];
			int pprev = i;
			char pprevc = s[0];
			int prev = j;
			char prevc = s[1];

			for(int p=2;p<n+2;p++){
				int k = p%n;
				int my;
				char myc = s[k];
				if(prev == 0){
					if(prevc == 'o'){
						my = pprev;
					}
					else{
						my = 1-pprev;
					}
				}
				if(prev == 1){
					if(prevc == 'o'){
						my = 1-pprev;
					}
					else{
						my = pprev;
					}
				}
				
				if(k == 0){
					// cout<<my<<" "<<i<<endl;
					if(my != i) break;
					else{
						pprev = prev;
						pprevc = prevc;
						prev = my;
						prevc = myc;
					}
				}
				else if(k == 1){
					// cout<<my<<" "<<j<<endl;
					if(my != j) break;
					else{
						cout<<ans<<endl;
						return;
					}
				}
				else{
					pprev = prev;
					pprevc = prevc;
					prev = my;
					prevc = myc;
					
					ans += huh[my];
				}
			}
		}
	}

	cout<<-1<<endl;
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
