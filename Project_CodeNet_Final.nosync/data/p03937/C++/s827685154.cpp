#include<iostream>
#include<vector>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool dfs(int x,int y,int h,int w,vector<vector<bool> >& map){

for(int i=2;i<=3;i++){
	if(map[x+dx[i]][y+dy[i]]){
		return false;
	}
}

map[x][y]=false;
if(x==h&&y==w){
		return true;
	}
if(map[x+dx[0]][y+dy[0]]&&map[x+dx[1]][y+dy[1]]){
	return false;
}else if(map[x+dx[0]][y+dy[0]]){
	return dfs(x+dx[0],y+dy[0],h,w,map);
}else{
	return dfs(x+dx[1],y+dy[1],h,w,map);
}
	

}
int main(void){
	int h,w;
	cin>>h>>w;
	vector<vector<bool> > map(h+2,vector<bool>(w+2,false));
	char a;
for(int i=1;i<=h;i++){
	for(int j=1;j<=w;j++){
cin>>a;
if(a=='#'){
	map[i][j]=true;
}
	}
}
if(dfs(1,1,h,w,map)){
	cout<<"Possible"<<endl;
}else{
	cout<<"Impossible"<<endl;
}
	return 0;
}