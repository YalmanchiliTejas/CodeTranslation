#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;
int main(void){
 int h,w;
 cin>>h>>w;
 vector<vector<char>>a(h,vector<char>(w));
 for(int i=0;i<h;i++){
     for(int j=0;j<w;j++){
         cin>>a[i][j];
     }
 }
 bool col[101]={false};
 bool row[101]={false};
 for(int i=0;i<h;i++){
     for(int j=0;j<w;j++){
         if(a[i][j]=='#'){
             row[i]=true;
             break;
         }
     }
 }
 for(int j=0;j<w;j++){
     for(int i=0;i<h;i++){
         if(a[i][j]=='#'){
             col[j]=true;
             break;
         }
     }
 }

 bool exe=false;
 for(int i=0;i<h;i++){
     exe=false;
     for(int j=0;j<w;j++){
         if(row[i]==true&col[j]==true){
             cout<<a[i][j];
             exe=true;
         }
     }
     if(exe){
             cout<<endl;
         }
 }
 }