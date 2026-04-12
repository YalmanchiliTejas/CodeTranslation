#include<bits/stdc++.h>

using namespace std;

int main() {
	int n,m;
    cin>>n>>m;
    int arr[109][109];
 	vector<int> vecr;
 	vector<int> vecc;
    for(int i=1;i<=n;i++) {
      int temp_cnt = 0;
    	for(int j=1;j<=m;j++) {
            char a;
            cin>>a;
            if(a == '.') arr[i][j] = 1;	
        	else arr[i][j] = 0;
        	
            if(arr[i][j] == 1) temp_cnt++;
        }
        if(temp_cnt == m) {
        	vecr.push_back(i);
        }
    }
  
  	for(int i=1;i<=m;i++) {
      int temp_cnt = 0;
    	for(int j=1;j<=n;j++) {
            if(arr[j][i] == 1) temp_cnt++;
        }
        if(temp_cnt == n) {
        	vecc.push_back(i);
        }
    }
    
    for(int r=0;r<vecr.size();r++) {
            for(int i=1;i<=m;i++) {
            	arr[vecr[r]][i] = -1;
            }	
            }
            
                for(int r=0;r<vecc.size();r++) {
            for(int i=1;i<=n;i++) {
            	arr[i][vecc[r]] = -1;
            }	
            }
    
  	for(int i=1;i<=n;i++) {
    	for(int j=1;j<=m;j++) {
            
          	if(arr[i][j] != -1) {
            	if(arr[i][j] == 1) cout<<'.';
                else cout<<'#';
            } 
        }
        cout<<endl;
    }	

	return 0;
}