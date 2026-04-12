#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iomanip>
#include <tuple>

using namespace std;

int main(){
   int h,w;
   cin>>h>>w;
   vector<vector<char>> a(h,vector<char>(w));
   vector<vector<char>> b(h,vector<char>(w));
   
   for(int i=0;i<h;i++){
       for(int j=0;j<w;j++)cin>>a[i][j];
   }

   int k=0;
   for(int i=0;i<h;i++){
       bool flag=true;
       for(int j=0;j<w;j++){
           if(a[i][j]=='#')flag=false;
       }
       
       if(!flag){
           for(int j=0;j<w;j++)b[k][j]=a[i][j];
           k++;
       }
   }
   
   int l=0;
   for(int j=0;j<w;j++){
       bool flag=true;
       for(int i=0;i<k;i++){
           if(b[i][j]=='#')flag=false;
       }
       
       if(!flag){
           for(int i=0;i<k;i++)b[i][l]=b[i][j];
           l++;
       }
   }
     
   for(int i=0;i<k;i++){
       for(int j=0;j<l;j++)cout<<b[i][j];
       cout<<endl;
   }
   

}

   
