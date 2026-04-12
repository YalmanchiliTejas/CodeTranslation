#include<iostream>
#define int long long
using namespace std;
const int N=3005;
int f[N][N],ar[N];
signed main(){
	int n,i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		if(n%2==1){
			f[i][i]=ar[i];
		}
		else{
			f[i][i]=-ar[i];
		}
	}
	for(i=1;i<n;i++){
		for(j=1;j<=n-i;j++){
			if((n-i)%2==1){
				f[j][i+j]=max(f[j+1][i+j]+ar[j],f[j][i+j-1]+ar[i+j]);
			}
			else{
				f[j][i+j]=min(f[j+1][i+j]-ar[j],f[j][i+j-1]-ar[i+j]);
			}
		}
	}
	cout<<f[1][n];
}