#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int map[100][100];
	int sum_h[100],sum_l[100];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
    	    char tmp;
			cin>>tmp;
			if(tmp=='.')map[i][j]=0;
			else map[i][j]=1;
			sum_h[i]+=map[i][j],
			sum_l[j]+=map[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(sum_h[i]==0 || sum_l[j]==0)continue;
			cout<<char(map[i][j]?'#':'.');
		}
		if(sum_h[i])cout<<endl;
	}
}