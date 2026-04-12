#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector <vector<int> >A;
int magic(int n){
	int c=1,x=n/2,y=x+1;
	while(1){
		A[y][x]=c;
		if(c== n*n)break;
		while(1){
			x=(x+1)%n;
			y=(y+1)%n;
			if(A[y][x]==0)break;
			x=(x+n-1)%n;
			y=(y+1)%n;
			if(A[y][x]==0)break;
		}
		c++;
	}
	return 0;
}
int main(){
	int n,i,j;
	while(cin>>n,n!=0){
		A.resize(n);
		for(i=0;i<n;i++)A[i].resize(n,0);
		magic(n);
		stringstream buf;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)buf<<setw(4)<<setfill(' ')<< A[i][j];
			cout<<buf.str()<< endl;
			buf.str("");
		}
		A.clear();
	}
}