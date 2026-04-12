#include<iostream>
#include<bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ck(a) (0<=(a)&&(a)<10)
int dx[]={-1,0,1,0,0},dy[]={0,0,0,-1,1};
void set(int *a,int b){
	bitset<10> c(b);
	string t=c.to_string<char,char_traits<char>,allocator<char> >();
	rep(i,10)a[i]=t[i]-'0';
}
void change(int t[10][10],int *a,int l){
	rep(i,10){
		rep(d,5){
			if(!ck(l+dy[d])||!ck(i+dx[d]))continue;
			t[l+dy[d]][i+dx[d]]^=a[i];
		}
	}
}
int main(){
	int n; cin>>n;
	while(n--){
		int state[10][10]={0},axion[10][10],temp[10][10];
		rep(i,10)rep(j,10)cin>>state[i][j];
		rep(d,1<<10){
			rep(i,10)rep(j,10)temp[i][j]=state[i][j];
			set(axion[0],d);
			rep(i,10){
				change(temp,axion[i],i);
				if(i<9)rep(j,10)axion[i+1][j]=temp[i][j];
			}
			rep(i,10)rep(j,10)if(temp[i][j])goto NEXT;
			rep(i,10){
				rep(j,10)cout<<axion[i][j]<<(j<9?" ":"");
				cout<<endl;
			}
			goto END;
			NEXT:;
		}
		END:;
	}
	return 0;
}