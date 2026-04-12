#include <bits/stdc++.h>


using namespace std;


int number_of_row,number_of_column;
int g,h,i,j,count_dotto,k,l;

int main() {
  cin >> number_of_row>>number_of_column;
  vector<vector<char>> data(number_of_row,vector<char>(number_of_column));
  
  
  for ( i = 0; i < number_of_row; i++) {
    for ( j = 0; j < number_of_column; j++) {
      
        cin >> data.at(i).at(j);
      }
    }
	
  
 

  for ( i = 0; i < number_of_row; i++) {
  
    
    count_dotto = 0;
    for ( j = 0; j < number_of_column; j++) {
      
        if (data.at(i).at(j) == '.') {
          count_dotto++;
        }
	
      }
      if (count_dotto == number_of_column){
        for (k = i;k < number_of_row-1;k++){
          data.at(k) = data.at(k+1);  
        }
        i=i-1;
        number_of_row--;
      }
    
    }
  for ( j = 0; j < number_of_column; j++) {
   
    count_dotto = 0;
    for ( i = 0; i < number_of_row; i++) {
      if (data.at(i).at(j) == '.') {
          count_dotto++;
        }
    }
    if(count_dotto == number_of_row){
      for(l = 0;l< number_of_row;l++){
        for(k = j;k< number_of_column-1;k++){
          data.at(l).at(k) = data.at(l).at(k+1);
          }
      }
     number_of_column --;
     j=j-1;
    }
  }
    for ( g = 0; g < number_of_row; g++) {
    
      for ( h = 0; h < number_of_column; h++) {
        cout << data.at(g).at(h) ;
      }
      cout << endl;
    }
}