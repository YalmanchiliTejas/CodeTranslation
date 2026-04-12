#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int h,w;cin>>h>>w;
	char g[h][w];
	rep(i,h) rep(j,w) cin>>g[i][j];

	int root[h+w-2];
	rep(i,h+w-2){
		if(i<w-1) root[i]=0;//左に向かう動き
		else root[i]=1;//下に向かう動き
	}
	char ans_real[h+w-1];
	bool bans=0;
	do{
		char ans[h+w-1];ans[0]=g[0][0];
		int hnt=0,wnt=0;
		rep(i,h+w-2){
			if(root[i]==0){
				wnt++;
				ans[i+1]=g[hnt][wnt];
			}
			else{
				hnt++;
				ans[i+1]=g[hnt][wnt];
			} 
		}
		bool chk=1;
		/*
		rep(i,h+w-1) cout<<ans[i];
		cout<<"\n";
*/
		rep(i,h+w-1){
			if(ans[i]=='.'){
				chk=0;
				break;
			}
		}
		if(chk){
			rep(i,h+w-2) ans_real[i]=root[i];
			bans=1;
			break;
		}
	}while(next_permutation(root,root+h+w-2));

	if(bans){
		char ans[h][w];
		rep(i,h) rep(j,w) ans[i][j]='.';
		ans[0][0]='#';
		int hnt=0,wnt=0;
		rep(i,h+w-2){
			if(ans_real[i]==0){
				wnt++;
				ans[hnt][wnt]='#';
			}
			else{
				hnt++;
				ans[hnt][wnt]='#';
			} 
		}
	/*	rep(i,h){
			rep(j,w) cout<<ans[i][j];
			cout<<"\n";
		}
*/
		rep(i,h){
			rep(j,w){
				if(ans[i][j]!=g[i][j]){
					cout<<"Impossible"<<"\n";
					return 0;
				}
			}
		}
		cout<<"Possible"<<"\n";
		return 0;
	}
	cout<<"Impossible"<<"\n";
}