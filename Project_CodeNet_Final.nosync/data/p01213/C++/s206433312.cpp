#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

typedef pair<int,int> pii;

int dp[301][301];
pii nxt[301][301];
char s1[501];
char s2[501];
int s1s;
int s2s;

char res[501];
int main(){
	string str;
	while(cin>>str&&str!="#END"){
		int ms=0;
		for(int i=0;i<(int)str.size()-1;i++){
			s1s=i+1;
			s2s=str.size()-i-1;
			for(int j=0;j<i+1;j++)s1[j]=str[j];
			for(int j=i+1;j<(int)str.size();j++)s2[j-i-1]=str[j];
			memset(dp,0,sizeof(dp));
			for(int j=s1s;j>=0;j--){
				for(int k=s2s;k>=0;k--){
					int res=0;
					int a=j;
					int b=k;
					if(a==s1s||b==s2s)res=0;
					else if(s1[a]==s2[b]){
						int tmp=dp[a+1][b+1]+1;
						if(tmp>res){
							nxt[a][b].first=a+1;
							nxt[a][b].second=b+1;
							res=tmp;
						}
					}
					else{
						int tmp=dp[a][b+1];
						if(tmp>res){
							nxt[a][b].first=a;
							nxt[a][b].second=b+1;
							res=tmp;
						}
						tmp=dp[a+1][b];
						if(tmp>res){
							nxt[a][b].first=a+1;
							nxt[a][b].second=b;
							res=tmp;
						}
					}
					dp[a][b]=res;
				}
			}
			//int tmp=dfs(0,0);
			int tmp=dp[0][0];
			if(tmp>ms){
				ms=tmp;
				int ca,cb;
				ca=cb=0;
				int cnt=0;
				while(1){
					if(ca==s1s||cb==s2s)break;
					int na=nxt[ca][cb].first;
					int nb=nxt[ca][cb].second;
					if(na-ca==1&&nb-cb==1){
						res[cnt]=s1[ca];
						cnt++;
					}
					ca=na;
					cb=nb;
				}
				res[cnt]='\0';
			}
		}
		cout<<res<<endl;
	}
	return 0;
}