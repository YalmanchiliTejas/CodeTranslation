#include<vector>
#include<iostream>

using namespace std;



vector<int> GaussJordanMod2(vector<vector<int> > a){
	int n=a.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j][i]){
				a[i].swap(a[j]);
				break;
			}
		}
		for(int j=0;j<n;j++){
			if(i==j||a[j][i]==0)continue;
			for(int k=i;k<n+1;k++){
				a[j][k] = (a[j][k]-a[i][k]+2)%2;
			}
		}
	}
	vector<int> res(n);
	for(int i=0;i<n;i++)res[i]=a[i][n];
	return res;
}


int main(){
	int dy[]={0,1,0,-1,0};
	int dx[]={0,0,1,0,-1};
	int n;
	cin>>n;
	while(n--){
		vector<vector<int> > a(100,vector<int>(101,0));
		for(int i=0;i<100;i++){
			int y=i/10,x=i%10;
			for(int j=0;j<5;j++){
				int ny=y+dy[j],nx=x+dx[j];
				if(0<=ny&&ny<10&&0<=nx&&nx<10){
					a[ny*10+nx][i]=1;
				}
			}
		}
		for(int i=0;i<100;i++){
			int c;
			cin>>c;
			a[i][100]=c;
		}
		vector<int> ans(GaussJordanMod2(a));
		for(int i=0;i<10;i++){
			cout<<ans[i*10];
			for(int j=1;j<10;j++){
				cout<<' '<<ans[i*10+j];
			}
			cout<<endl;
		}
	}
	return 0;
}