#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	string st[n];
	for(int i=0;i<n;i++){
		cin>>st[i];
	}
	vector<int> row(n),col(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(st[i][j] =='.'){
				row[i]++;
				col[j]++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		int flag=0;
		for(int j=0;j<m;j++){
			//cout<<row[i]<<col[j]<<endl;
			if(row[i]==m||col[j]==n){
				continue;
			}
			flag = 1;
			cout<<st[i][j];
		}
		if(flag ==1)
			cout<<endl;
	}
	return 0;	
}
