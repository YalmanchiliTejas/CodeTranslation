#include<vector>
#include<iostream>

using namespace std;


vector<int> GaussJordanMod2(vector<vector<unsigned int> > a){
	int n=a.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j][i/32]>>(i&31)&1){
				a[i].swap(a[j]);
				break;
			}
		}
		unsigned int rev=a[i][i/32]&~((1<<(i&31))-1);		
		for(int j=0;j<n;j++){
			if(i==j||!(a[j][i/32]>>(i&31)&1))continue;
			a[j][i/32] ^= rev;
			for(int k=i/32+1;k<(n+1+32-1)/32;k++){
				a[j][k] ^= a[i][k];
			}
		}
	}
	vector<int> res(n);
	for(int i=0;i<n;i++)res[i]=a[i][n/32]>>n%32&1;
	return res;
}


int main(){
	int dy[]={0,1,0,-1,0};
	int dx[]={0,0,1,0,-1};
	int n;
	cin>>n;
	while(n--){
		vector<vector<unsigned int> > a(100,vector<unsigned int>((101+31)/32,0));
		for(int i=0;i<100;i++){
			int y=i/10,x=i%10;
			for(int j=0;j<5;j++){
				int ny=y+dy[j],nx=x+dx[j];
				if(0<=ny&&ny<10&&0<=nx&&nx<10){
					a[ny*10+nx][i/32] |= 1<<(i&31);
				}
			}
		}
		for(int i=0;i<100;i++){
			int c;
			cin>>c;
			a[i][100/32] |= c<<(100&31);
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