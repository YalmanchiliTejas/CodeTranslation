#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<char>> matrix(N, vector<char>(N,'#'));

  rep(i, N)
  	rep(j,M)
    	cin >> matrix[i][j];
  
   vector<int> sum1(M,0), sum2(N,0);
  int newN=N, newM=M;
  
  // check in row direction
  rep(i, N)
  	rep(j,M){
  	if (matrix[i][j]=='.')
      	sum2[i]++;
    
    if (sum2[i]==M)
      	newN--;
  	}
  
  // check in column direction
   rep(j, M)
  	rep(i,N){
  		if (matrix[i][j]=='.')
      		sum1[j]++;
     
    	if (sum1[j]==N)
          newM--;     
  	}
  
  // empty the x rows and columns
    rep(i, N){
    	if (sum2[i]==M){
        //  cout << "Eliminating rows..." << endl;
        	rep(j, M)
          	matrix[i][j]='x';
        }
    }
      
    rep(j, M){
    	if (sum1[j]==N){
        //  cout << "Eliminating columns..." << endl;
        	rep(i, N)
          	matrix[i][j]='x';
        }
    }
   /*   
   rep(i, N){
     cout << endl;
  	rep(j,M){
   		cout << matrix[i][j];
   	}
   }
  cout << endl;  
  
  cout << newN << 'x' << newM << "matrix" << endl;
  */         
  rep(i,N){
     if (sum2[i]!=M){
  		    rep(j,M){
  				if (matrix[i][j]!='x'){
          		cout << matrix[i][j];
        		}
    			}
     		cout << endl;	  
     }
  }
    
  
    	
  
  
}
