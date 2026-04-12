#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, M;
  cin >> N >> M;

 	vector<vector<char>> data(N, vector<char>(M));
  for (int i=0;i<N;i++){
    for(int j=0;j<M;j++){   
     cin >> data.at(i).at(j);
    }
  }
  vector<int> check_i(N,0);
  vector<int> check_j(M,0);
  for(int i=0;i<N;i++){
    for (int j=0;j<M;j++){
    	if(data.at(i).at(j)=='#'){
          check_i.at(i) = 1;
          check_j.at(j) = 1;
        }
   	 }
  }
	for(int i=0;i<N;i++){
  		if (check_i.at(i)==1){
    		for (int j=0;j<M;j++){
    			if(check_j.at(j)==1){
      				cout<< data.at(i).at(j);
                }
            }
        }
    	cout<< endl;
    
  }
    
  
  return 0;
}