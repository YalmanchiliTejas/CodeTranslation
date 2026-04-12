#include <bits/stdc++.h>
using namespace std;


bool in_array(const char &word, const vector< char > &data)
{
    int max=data.size(); 
    if (max==0) return false;
 
    for(int i=0; i<max; i++){
        if (data.at(i)==word) return true;
    }
    return false;
} 

int main() {
  
  int n, m; 
  cin >> n >> m;
  
  vector<vector<char>> data(n, vector<char>(m));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      char x;
      cin >> x;
      data.at(i).at(j) = x;
    }
  }
  
  for(int i=0; i<n; i++){    
    for(int j=0; j<m; j++){
      
      //横一列に # が存在する
      if(in_array('#', data.at(i))){

        //縦一列に # が存在する
        int c = 0; 
        for(int k=0; k<n; k++){
          if (data.at(k).at(j) == '#') {
            c = 1;
            break;
          }
        }

        if (c == 1) cout << data.at(i).at(j);

      }
      
    }
    if(in_array('#', data.at(i))) cout << endl;
  }
   
}