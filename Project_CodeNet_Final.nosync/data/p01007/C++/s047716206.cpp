#include<bits/stdc++.h>
using namespace std;
int n;
void rotate(int r,int c,int s,vector<vector<int> > &map){
	//cout<<r<<' '<<c<<' '<<s<<endl;
	vector<vector<int> > tmp(s,vector<int>(s));
	for(int i=0;i<s;i++)
		for(int j=0;j<s;j++){
			tmp[i][j] =map[r+s-1-j][c+i];
	//	cout<<r+s-1-j<<' '<<c+i<<endl;	
		}
       for(int i=0;i<s;i++){
	       for(int j=0;j<s;j++){
	       map[i+r][j+c] = tmp[i][j];
	       
       }
       }	       
}
void reverce(int r,int c,int s,vector<vector<int> > &map){
	for(int i=0;i<s;i++)
		for(int j=0;j<s;j++){
			int nx = i+r;
			int ny = j+c;
			//cout<<nx<<   ' '<<ny<<' '<<map[nx][ny]<<endl;
			if(map[nx][ny]==1){
				map[nx][ny]=0;

			}else{
				map[nx][ny]=1;
			}
		//cout<<map[nx][ny]<<endl;
		}

}
void left(int l,vector<vector<int> > &map){
int tmp = map[l][1];
for(int i=1;i<n;i++){
map[l][i]=map[l][i+1];
}
map[l][n]=tmp;
}
void right(int l,vector<vector<int> > &map){
int tmp = map[l][n];
for(int i =n ;i>1;i--){
map[l][i]= map[l][i-1];
}
map[l][1] = tmp;

}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
void island(int r,int c,vector<vector<int> > &map,int now){
	if(map[r][c]==now){
		map[r][c]=(now+1)%2;
	for(int i=0;i<4;i++){
		int nx =r+dx[i];
		int ny =c+dy[i];
		if(nx>=1&&ny>=1&&nx<=n&&ny<=n){
			island(nx,ny,map,now);
		}
	}
	}else{
return;
	}
	return;
}

int main(){
int m;
cin>>n>>m;
vector<vector<int> > map(n+2,vector<int>(n+2,0));
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++)cin>>map[i][j];
}

for(int i=0;i<m;i++){
int o;
cin>>o;
if(o==0){
int r,c,size,angle;
cin>>r>>c>>size>>angle;
angle/=90;
for(int j=0;j<angle;j++){
rotate(r,c,size,map);
}
}else if(o==1){
int r,c,size;
cin>>r>>c>>size;
reverce(r,c,size,map);
}else if(o==2){
int l;
cin>>l;
left(l,map);

}else if(o==3){
int l;
cin>>l;
right(l,map);
}else{
int r,c;
cin>>r>>c;
island(r,c,map,map[r][c]);
}

}
//cout<<"operand"<<endl;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
	cout<<map[i][j];
		if(j!=n)cout<<' ';
	}
	cout<<endl;
}
return 0;
}

