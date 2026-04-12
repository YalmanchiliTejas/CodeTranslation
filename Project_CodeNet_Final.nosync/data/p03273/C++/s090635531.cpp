#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> table(H,vector<char>(W));
  
  for(int i=0 ; i<H ; i++){
  	for(int j=0 ; j<W ; j++){
    	cin >> table.at(i).at(j);
    }
  }
  
  for(int i=0 ; i<H ; i++){
    int count = 0;
    	for(int j=0 ; j<W ; j++){
        	if(table.at(i).at(j)=='.'){
            	count++;
            }
        }
    if(count==W){
      	for(int j=0 ; j<W ; j++){
        table.at(i).at(j)='x';
        }    	
    }
  }

  for(int j=0 ; j<W ; j++){
    int count = 0;
    	for(int i=0 ; i<H ; i++){
        	if(table.at(i).at(j) != '#'){
            	count++;
            }
        }
    if(count==H){
      	for(int i=0 ; i<H ; i++){      
    	table.at(i).at(j)='x';
        }
    }
  }
  
  for(int i=0 ; i<H ; i++){
  	for(int j=0 ; j<W ; j++){
    	if(table.at(i).at(j) != 'x'){
        	cout << table.at(i).at(j);
        }
        if(j==W-1){
        	cout << endl;
        } 
    }
  }
}