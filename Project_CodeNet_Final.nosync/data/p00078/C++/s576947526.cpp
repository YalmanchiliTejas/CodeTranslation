#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;



int main(){
	int n, x, y, i, j, sqsize;
	while(true){
		cin>>n; if(n==0)break;
		vector< vector<int> > sq(n, vector<int>(n, 0));
		sqsize = sq.size() * sq.size();
		x = n/2.0 + 0.5 - 1.0;
		y = n/2.0 + 0.5 - 1.0;
		y = y+1;
		for(i=1;i<=sqsize;i++){
			sq[y][x]=i;
			(x+1<n)? x++: x=0;
			(y+1<n)? y++: y=0;
			if(sq[y][x]!=0){
				(x-1>=0)? x--: x=n-1;
				(y+1<n)? y++: y=0;
			}
		}
		for(i=0;i<n;i++){
			cout<<setw(4)<<sq[i][0];
			for(j=1;j<n;j++){
				cout<<setw(4)<<sq[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}