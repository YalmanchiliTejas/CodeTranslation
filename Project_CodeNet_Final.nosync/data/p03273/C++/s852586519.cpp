#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,colum;
    cin>>row>>colum;
    vector<char>rows;
    vector<char>columns;
    char field[row][colum];
    for(int i=0;i<row;i++){
        bool found=false;
        for(int j=0;j<colum;j++){
            char m;
            cin>>m;
            field[i][j]=m;
            if(m=='#'){
                found=true;
            }
        }
        if(!found){
            rows.push_back(i);
        }
    }
    for(int i=0;i<colum;i++){
        bool found=false;
        for(int j=0;j<row;j++){
            if(field[j][i]=='#'){
                found=true;
            }
        }
        if(!found){
            columns.push_back(i);
        }
    }
    sort(rows.begin(),rows.end());
    sort(columns.begin(),columns.end());
    for(int i=0;i<row;i++){
        bool dont=true;
        for(int j=0;j<colum;j++){
            if(!binary_search(rows.begin(),rows.end(),i)){
              if(!binary_search(columns.begin(),columns.end(),j)){
                cout<<field[i][j];
                dont=false;
              }
            }
        }
        if(!dont){
            cout<<endl;
        }
    }
    return 0;
}