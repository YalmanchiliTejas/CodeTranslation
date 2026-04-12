#include<bits/stdc++.h>
using namespace std;

int ans[100000];

int main(){
	int n;
	string s;
	cin>>n>>s;

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans[0] = i;
			ans[1] = j;
			bool f = 0;

			for(int it=1;it<n-1;it++){
				if((ans[it] && s[it]=='o') || (!ans[it] && s[it]=='x')){
					ans[it+1] = ans[it-1];
				} else {
					ans[it+1] = !ans[it-1];
				}
			}

			if((ans[n-1] && s[n-1] == 'o') || (!ans[n-1] && s[n-1] == 'x')){
				if(ans[0] != ans[n-2]) f = 1;
			}
			else if(ans[0] == ans[n-2]) f = 1;

			for(int it=0;it<n;it++){
				if(ans[it] && s[it]=='o') if(ans[(it-1+n)%n] != ans[(it+1)%n]) f = 1;
				if(!ans[it] && s[it]=='x') if(ans[(it-1+n)%n] != ans[(it+1)%n]) f = 1;
				if(ans[it] && s[it] =='x') if(ans[(it-1+n)%n] == ans[(it+1)%n]) f = 1;
				if(!ans[it] && s[it] =='o') if(ans[(it-1+n)%n] == ans[(it+1)%n]) f = 1;
			}

			if(!f){
				for(int it=0;it<n;it++){
					cout<<(ans[it] ? 'S' : 'W');
				}
				return 0;
			}
		}
	}
	cout<<"-1";
}