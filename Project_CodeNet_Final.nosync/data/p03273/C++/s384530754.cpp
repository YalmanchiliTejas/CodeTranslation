#include <bits/stdc++.h>
using namespace std;


bool color2bool(char color){
    if(color=='.'){
        return false;
    }else{
        return true;
    }
}


std::vector<int> delete_row(std::vector<char>& grid, int column_size, int row_size){

    bool allthesame;
    std::vector<int> row_to_delete(column_size, 0);
    for(int i=0; i < column_size; i++){
        // printf("32");

        allthesame = true;
        for(int j=0; j < row_size; j++){
            if(color2bool(grid.at(i*row_size + j))){
                allthesame = false;
                break;
            }
        }
        if(allthesame){
            row_to_delete.at(i)=1;

        }
    }
    return row_to_delete;
}

std::vector<int> delete_column(std::vector<char>& grid, int column_size, int row_size){

    bool allthesame;
    std::vector<int> column_to_delete(row_size, 0);
    int dense_size = 0;
    for(int i=0; i < row_size; i++){

        allthesame = true;
        for(int j=0; j < column_size; j++){
            if(color2bool(grid.at(i + j*row_size))){
                allthesame = false;
                break;
            }
        }
        if(allthesame){
            column_to_delete.at(i) = 1;
        }
    }
    return column_to_delete;
}


int main() {
    int column_size, row_size;
    cin >> column_size >> row_size;
    std::vector<char> grid(column_size * row_size);
    string row;
    for(int i = 0; i < column_size; i++){
        cin >> row;
        for(int j=0; j < row_size; j++){
            grid.at(i*row_size + j) = row.at(j);
        }
    }
    std::vector<int> column_to_delete(row_size);
    std::vector<int> row_to_delete(column_size);

    row_to_delete = delete_row(grid, column_size, row_size);
    column_to_delete = delete_column(grid, column_size, row_size);
    for(int i=0; i < column_size; i++){
        if(row_to_delete.at(i)){
                continue;
        }else{
            for(int j=0; j < row_size; j++){
                if(column_to_delete.at(j)){
                    continue;
                }else{
                    cout << grid.at(i*row_size+j);
                }

            }
            cout << endl;
        }
    }

    return 0;
  // リンゴ・パイナップルをそれぞれ1つずつ購入するとき合計S円になるような買い方が何通りあるか
  // ここにプログラムを追記
}
