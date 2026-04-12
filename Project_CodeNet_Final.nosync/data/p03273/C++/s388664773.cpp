#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    vector<vector<char>>v(h,vector<char>(w));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>v[i][j];
        }
    }
    unordered_set<int>row,column;
    for(int i=0;i<h;i++)
    {
        bool no=false;
        for(int j=0;j<w;j++)
        {
            if(v[i][j]!='.'){
                no=true;
                break;
            }
        }
        if(!no){
            row.insert(i);
        }
    }
    for(int i=0;i<w;i++)
    {
        bool no=false;
        for(int j=0;j<h;j++)
        {
            if(v[j][i]!='.'){
                no=true;
                break;
            }
        }
        if(!no){
            column.insert(i);
        }
    }
    for(int i=0;i<h;i++)
    {
        if(row.find(i)!=row.end()){
            continue;
        }
        for(int j=0;j<w;j++)
        {
            if(column.find(j)!=column.end()){
                continue;
            }
            else
            cout<<v[i][j];
        }

        cout<<endl;
    }
}