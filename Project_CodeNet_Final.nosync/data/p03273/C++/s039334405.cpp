#include <iostream>
#include <vector>

int main(void){
  int row, col;
  std::cin >> row >> col;
  std::vector<std::vector<char>> table(row, std::vector<char>(col));
  std::vector<bool> rowB(row);
  std::vector<bool> colB(col);
  
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      std::cin >> table.at(i).at(j);
      if(table.at(i).at(j) == '#') rowB.at(i) = colB.at(j) = true;
    }
  }
  
  for(int i=0; i<row; i++){
    if(rowB.at(i)){
      for(int j=0; j<col; j++){
        if(colB.at(j)){
          std::cout << table.at(i).at(j);
        }
      }
      std::cout << '\n';
    }
  }
  return 0;
}
      