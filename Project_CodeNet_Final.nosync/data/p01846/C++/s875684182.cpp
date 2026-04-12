#include <bits/stdc++.h>
#define MOD 100000007LL
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int fie[101][101];

int main(void){
	while(1){
		string str;
		cin >> str;
		if(str=="#")break;
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int y=0,x=0;
		memset(fie,-1,sizeof(fie));
		for(int i=0;i<str.size();i++){
			if(str[i]=='b'){
				fie[y][x]=1;
				x++;
			}
			if(str[i]=='/'){
				x=0;
				y++;
			}
			if(str[i]>='0' && str[i]<='9'){
				int v=str[i]-'0';
				for(int i=0;i<v;i++){
					fie[y][x+i]=0;
				}
				x+=v;
			}
		}
		swap(fie[a-1][b-1],fie[c-1][d-1]);
		string res="";
		for(int i=0;i<9;i++){
			int cnt=0;
			int j=0;
			while(fie[i][j]>=0){
				if(fie[i][j]==0)cnt++;
				if(fie[i][j]==1){
					if(cnt>0){
						res+=('0'+cnt);
					}
					cnt=0;
					res+="b";
				}
				j++;
			}
			if(cnt>0){
				res+=('0'+cnt);
			}
			if(j>0)res+="/";
		}
		res=res.substr(0,res.size()-1);
		cout << res << endl;
	}
	return 0;
}