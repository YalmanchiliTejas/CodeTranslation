  /*  HARD WORK FOREVER PAYS  */
#include<bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define turbo(){	\
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL); \
}
using namespace std;
typedef long long ll;
typedef pair<int,int> PII; 
int main() 
{ 
	turbo();
	int j,i,n,l;
	cin>>n;
	vector<char> v;
	string s[n];
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	for(i=0;i<s[0].size();i++){
		int cnt=1;
		char c=s[0][i];
		for(j=1;j<n;j++){
			for(l=0;l<s[j].size();l++){
				if(s[j][l]==c){
					cnt++;
					s[j][l]='0';
					break;
				}
			}
		}
		if(cnt==n){
			v.pb(c);
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++){
		cout<<v[i];
	}
	cout<<"\n";
	return 0; 
} 