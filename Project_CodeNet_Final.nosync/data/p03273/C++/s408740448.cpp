#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
using namespace std;

int main(){
    int H,W;cin>>H>>W;
    bool white;
    char a[110][110];
    
    vector<int> v_row;
    for(int i=0;i<H;i++){
        white=true;
        for(int j=0;j<W;j++){
            cin>>a[i][j];
            if(a[i][j]=='#')white=false;
        }
        if(!white)v_row.push_back(i);
    }

    vector<int> v_col;
    for(int j=0;j<W;j++){
        white=true;
        for(int i=0;i<H;i++)
            if(a[i][j]=='#')white=false;
        if(!white)v_col.push_back(j); 
    }

    for(int i=0;i<v_row.size();i++){
        for(int j=0;j<v_col.size();j++){
            if(j==v_col.size()-1)
                cout<<a[v_row[i]][v_col[j]]<<endl;
            else cout<<a[v_row[i]][v_col[j]]; 
        }
    }
    return 0;
}