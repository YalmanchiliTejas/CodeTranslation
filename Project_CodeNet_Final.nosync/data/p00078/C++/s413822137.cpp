#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		vector<vector<int> > magi(n,vector<int>(n,0));
		int a=(n-1)/2;
		int b=(n+1)/2;
		magi[a][b]=1;
		for(int i=2;i<=n*n;i++){
			while(1){
				a++;
				b++;
				if(a>=n) a=0;
				if(b>=n) b=0;
				if(magi[a][b]==0){
					magi[a][b]=i;
					break;
				}else{
					while(magi[a][b]!=0){
						a--;
						b++;
						if(a<0) a=n-1;
						if(b>=n) b=0;
					}
					magi[a][b]=i;
					break;
				}
			}
		}

		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(magi[i][j]>=1 && magi[i][j]<=9) cout<<"   ";
				else if(magi[i][j]>=10 && magi[i][j]<100) cout<<"  ";
				else cout<<" ";
				cout<<magi[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}