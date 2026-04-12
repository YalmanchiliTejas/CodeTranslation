#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdexcept>
#include<stdio.h>
#include<queue>
#include <cmath>
//for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<n;i++) cin >> x[i];
#define pi pair<int,int> 
using namespace std;
using ll = long long;
 int main(){
     int q,w; 
     cin >> q >> w;
     char a[q][w]={};
     int v[q]={};
     int h[w]={};
     for(int i=0;i<q;i++){
         for(int j=0;j<w;j++){
             cin >> a[i][j];
             if(a[i][j]=='#'){ v[i]=1; h[j]=1; }
         }
     }
    for(int i=0;i<q;i++){
        for(int j=0;j<w;j++){
            if(v[i]==1&&h[j]==1) cout << a[i][j];
        }
        if(v[i]==1) cout << endl;
    }
    return 0;
     

 }