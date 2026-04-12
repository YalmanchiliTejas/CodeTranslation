#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	int h,w;
	cin>>h>>w;
	char ch[h][w];
	rep(i,h){
		rep(j,w)cin>>ch[i][j];
	}
	bool check=true;
	rep(i,h){
		rep(j,w){
			if(ch[i][j]=='.')continue;
			if(i==0&&j==0&&h>1&&w>1){
				if(ch[1][0]=='#' && ch[0][1]=='#'){
					check=false;
					break;
				}
			}
			if(h>1&&w>1&&i==h-1&&j==w-1){
				if(ch[i-1][j]=='#' && ch[i][j-1]=='#'){
					check=false;
					break;
				}
			}
			int num=0;
			rep(k,4){
				if(i+dy[k]<0||i+dy[k]>=h)continue;
				if(j+dx[k]<0||j+dx[k]>=w)continue;
				if(ch[i+dy[k]][j+dx[k]]=='#')num++;
			}
			if(num>2){
				check=false;
				break;
			}
			if(i+1>=h && ch[i][j+1]=='.'){
				check=false;
				break;
			}else if(j+1>=w && ch[i+1][j]=='.'){
				check=false;
				break;
			}else{
				if(ch[i+1][j]=='.' && ch[i][j+1]=='.'){check=false;break;}
			}
		}
		if(!check)break;
	}
	cout<<(check?"Possible":"Impossible")<<endl;
	return 0;
}