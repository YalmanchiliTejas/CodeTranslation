#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
#include <search.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include<stack>
#include <utility>
using namespace std;
int main()
{
int h,w;
int col[100]={0},row[100]={0};
char g[100][100];
cin>>h>>w;
for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
        cin>>g[i][j];
    }
}
for(int i=0;i<h;++i){
    int check=0;
    for(int j=0;j<w;++j){
        if(g[i][j]!='.') check++;
    }
    if(check==0) row[i]=1;
}
for(int i=0;i<w;++i){
    int check=0;
    for(int j=0;j<h;++j){
        if(g[j][i]!='.') check++;
    }
    if(check==0) col[i]=1;
}

for(int i=0;i<h;++i){
     if(row[i]==0)
       {
           for(int j=0;j<w;++j){
              if(col[j]==0){
                cout<<g[i][j];
              }
           }
           cout<<endl;
       }
    }

return 0;
}
