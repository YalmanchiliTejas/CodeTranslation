#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)

const ll INF=1e9+7;
bool d1[5]={0,1,1,0,0};
bool d2[5]={0,1,0,1,0};
bool f[100001];
int n;
string s;
void prin(){
	rep(i,n){
		if(f[i]){
			cout<<'S';
		}
		else{
			cout<<'W';
		}
	}
	return;
}
int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n>>s;
	rep(i,4){
		memset(f,0,sizeof(f));
		f[1]=d1[i];
		f[2]=d2[i];
		for(int j=3;j<=n;j++){
			if((s[j-2]=='o'&&f[j-1])||(s[j-2]=='x'&&!f[j-1])){
				f[j]=f[j-2];
			}
			else{
				f[j]=!f[j-2];
			}
		}
		if((s[0]=='o'&&f[1])||(s[0]=='x'&&!f[1])){
			if(f[2]==f[n]){
				if((s[n-1]=='o'&&f[n])||(s[n-1]=='x'&&!f[n])){
					if(f[1]==f[n-1]){
						prin();
						return 0;
					}
				}
				else{
					if(f[1]!=f[n-1]){
						prin();
						return 0;
					}
				}
			}
		}
		else{
			if(f[2]!=f[n]){
				if((s[n-1]=='o'&&f[n])||(s[n-1]=='x'&&!f[n])){
					if(f[1]==f[n-1]){
						prin();
						return 0;
					}
				}
				else{
					if(f[1]!=f[n-1]){
						prin();
						return 0;
					}
				}
			}
		}
	}
	cout<<-1;
	return 0;
}