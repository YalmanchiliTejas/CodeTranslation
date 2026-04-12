#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
char s[200][200];
int h_flag[200];
int w_flag[200];
int main(){
	int h,w;
	//cin>>h>>w;
	scanf("%d%d",&h,&w);
	//cout<<h<<" "<<w<<endl;
	for(int i=0;i<h;i++){
		
		for(int j=0;j<=w;j++){
			scanf("%c",&s[i][j]);
			
			if(s[i][j]=='.'){
				h_flag[i]++;
				w_flag[j]++;
			}
		}
	}
	/*for(int i=0;i<=h;i++){
		for(int j=0;j<=w;j++){
			printf("%c",s[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<h;i++)cout<<h_flag[i]<<" ";
	cout<<endl;*/
	for(int i=0;i<h;i++){
		if(h_flag[i]==w)continue;
		for(int j=0;j<=w;j++){
			if(w_flag[j]==h)continue;
			printf("%c",s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
