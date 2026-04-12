#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2000000007
#define LINF 100000000000000007
#define MOD 1000000007
//#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 0
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cost;};
int ceil2(int a,int b){if(a%b){return a/b+1;}else{return a/b;}}
using namespace std;

int ans[111111],n;
string s;
signed main(){
	cin>>n>>s;
	int sw[111111];
	//if(true){
		rep(d1,2)rep(d2,2){
			fill(sw,sw+n,-1);
			sw[0]=d1;
			sw[1]=d2;
			for(int i=1;i<n-1;i++){
				if(sw[i]==1){//羊
					if(s[i]=='o')sw[i+1]=sw[i-1];
					else sw[i+1]=1-sw[i-1];
				}
				else{//狼
					if(s[i]=='o')sw[i+1]=1-sw[i-1];
					else sw[i+1]=sw[i-1];
				}
			}
			/*
			for(int i=1;i<n;i+=2){
				if(sw[i]==1){//羊
					if(s[i]=='o')sw[i+1]=sw[i-1];
					else sw[i+1]=1-sw[i-1];
				}
				else{//狼
					if(s[i]=='o')sw[i+1]=1-sw[i-1];
					else sw[i+1]=sw[i-1];
				}
			}
			for(int i=0;i<n;i+=2){
				if(i==0){
					if(sw[i]==1){//羊
						if(s[i]=='o')sw[n-1]=sw[i-1];
						else sw[n-1]=1-sw[i-1];
					}
					else{//狼
						if(s[i]=='o')sw[n-1]=1-sw[i-1];
						else sw[n-1]=sw[i-1];
					}
				}
				
				if(sw[i]==1){//羊
					if(s[i]=='o')sw[i+1]=sw[i-1];
					else sw[i+1]=1-sw[i-1];
				}
				else{//狼
					if(s[i]=='o')sw[i+1]=1-sw[i-1];
					else sw[i+1]=sw[i-1];
				}
			}
			*/
			int f=1;
			if(sw[0]!=d1 || sw[1]!=d2)f=0;
			rep(i,n){
				if(sw[i]==1){//ひつじ
					if(i==0){
						if(s[i]=='o'){if(sw[n-1]!=sw[1])f=0;}
						else {if(sw[n-1]==sw[1])f=0;}
					}
					else if(i==n-1){
						if(s[i]=='o'){if(sw[n-2]!=sw[0])f=0;}
						else {if(sw[n-2]==sw[0])f=0;}
					}
					else{
						if(s[i]=='o'){if(sw[i-1]!=sw[i+1])f=0;}
						else {if(sw[i-1]==sw[i+1])f=0;}
					}
				}
				else{//犬
					if(i==0){
						if(s[i]=='o'){if(sw[n-1]==sw[1])f=0;}
						else {if(sw[n-1]!=sw[1])f=0;}
					}
					else if(i==n-1){
						if(s[i]=='o'){if(sw[n-2]==sw[0])f=0;}
						else {if(sw[n-2]!=sw[0])f=0;}
					}
					else{
						if(s[i]=='o'){if(sw[i-1]==sw[i+1])f=0;}
						else {if(sw[i-1]!=sw[i+1])f=0;}
					}
				}
			}
			//rep(i,n)cout<<sw[i];
			//cout<<endl;
			if(f==1){
				rep(i,n){
					if(sw[i]==1)cout<<"S";
					else cout<<"W";
				}
				return 0;
			}
		}
	//}
	/*else{
		rep(d1,2)rep(d2,2){
			fill(sw,sw+n,-1);
			sw[0]=d1;
			sw[1]=d2;
			for(int i=1;i<n;i+=2){
				if(sw[i]==1){//羊
					if(s[i]=='o')sw[i+1]=sw[i-1];
					else sw[i+1]=1-sw[i-1];
				}
				else{//狼
					if(s[i]=='o')sw[i+1]=1-sw[i-1];
					else sw[i+1]=sw[i-1];
				}
			}
			for(int i=0;i<n;i+=2){
				if(i==0){
					if(sw[i]==1){//羊
						if(s[i]=='o')sw[i+1]=sw[n-1];
						else sw[i+1]=1-sw[n-1];
					}
					else{//狼
						if(s[i]=='o')sw[i+1]=1-sw[n-1];
						else sw[i+1]=sw[n-1];
					}
					continue;
				}
				if(sw[i]==1){//羊
					if(s[i]=='o')sw[i+1]=sw[i-1];
					else sw[i+1]=1-sw[i-1];
				}
				else{//狼
					if(s[i]=='o')sw[i+1]=1-sw[i-1];
					else sw[i+1]=sw[i-1];
				}
			}
		
			int f=1;
			if(sw[0]!=d1 || sw[1]!=d2)f=0;
			rep(i,n){
				if(sw[i]==1){//ひつじ
					if(i==0){
						if(s[i]=='o'){if(sw[n-1]!=sw[1])f=0;}
						else {if(sw[n-1]==sw[1])f=0;}
					}
					else if(i==n-1){
						if(s[i]=='o'){if(sw[n-2]!=sw[0])f=0;}
						else {if(sw[n-2]==sw[0])f=0;}
					}
					else{
						if(s[i]=='o'){if(sw[i-1]!=sw[i+1])f=0;}
						else {if(sw[i-1]==sw[i+1])f=0;}
					}
				}
				else{//犬
					if(i==0){
						if(s[i]=='o'){if(sw[n-1]==sw[1])f=0;}
						else {if(sw[n-1]!=sw[1])f=0;}
					}
					else if(i==n-1){
						if(s[i]=='o'){if(sw[n-2]==sw[0])f=0;}
						else {if(sw[n-2]!=sw[0])f=0;}
					}
					else{
						if(s[i]=='o'){if(sw[i-1]==sw[i+1])f=0;}
						else {if(sw[i-1]!=sw[i+1])f=0;}
					}
				}
			}
			rep(i,n)cout<<sw[i];
			cout<<endl;
			if(f==1){
				rep(i,n){
					if(sw[i]==1)cout<<"S";
					else cout<<"W";
				}
				return 0;
			}
		}
	}*/
	cout<<-1<<endl;
}