#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;

int main(){
	int n,m;cin>>n>>m;int a[m],b[m];vector<int> s(n);
	for(int i=0;i<m;i++) cin>>a[i]>>b[i];
	for(int i=0;i<n;i++) s[i]=i+1;
	int ans=0;
	do{
		//for(int i=0;i<n;i++) cout<<s[i];
		//cout<<endl;
		bool cnt=0;
		for(int j=0;j<n-1;j++){
			bool ans_j=0;
			for(int i=0;i<m;i++){
				if((s[j]==a[i]&&s[j+1]==b[i])||(s[j]==b[i]&&s[j+1]==a[i])){
					ans_j=1;
				}
			}
			if(!ans_j){
				cnt=0;
				break;
			}
			else cnt=1;
		}
		if(cnt) {
			//for(int i=0;i<n;i++) cout<<s[i];
			//cout<<endl;
			ans++;
		}
	}while(next_permutation(s.begin()+1,s.end()));

	cout<<ans<<endl;
}