#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<queue>
using namespace std;
main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
    	string str;
    	cin>>str;
    	for(int j=0;j<m;j++){
    		if(str[j] == '.'){
    			arr[i][j] = 0;
			}
			else{
				arr[i][j] = 1;
			}
		}
	}
	map<int,int> row,col;
	for(int i=0;i<n;i++){
		int flag = 0;
		for(int j=0;j<m;j++){
			if(arr[i][j] == 1){
				flag = 1;
			}
		}
		if(flag == 0){
			row[i] = 2;
		}
	}
	for(int j=0;j<m;j++){
		int flag = 0;
		for(int i=0;i<n;i++){
			if(arr[i][j] == 1){
				flag = 1;
			}
		}
		if(flag == 0){
			col[j] = 2;
		}
	}
	for(int i=0;i<n;i++){
		if(row[i] != 2){
			for(int j=0;j<m;j++){
				if(col[j] != 2){
					if(arr[i][j] == 0){
						cout<<".";
					}
					else{
						cout<<"#";
					}
				}
			}
			cout<<endl;
		}
	}
}