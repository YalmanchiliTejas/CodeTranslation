#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
 int h,w;
 cin>>h>>w;
 vector<vector<char>> data(h,vector<char>(w));
 rep(i,h){
     rep(j,w){
        cin>>data.at(i).at(j);
     }
 }
 vector<int> a(0),b(0);
 rep(i,h){
     int check=0;
     rep(j,w){    
         if(data.at(i).at(j)=='#') check++;
      }
    if(check>0) a.push_back(i);
 }
 rep(i,w){
     int check=0;
     rep(j,h){   
         if(data.at(j).at(i)=='#') check++;
     }
    if(check>0) b.push_back(i);
 }
 int n = a.size();
 int m = b.size();
 rep(i,n){
     rep(j,m){
         cout<<data.at(a.at(i)).at(b.at(j));
     }
     cout<<""<<endl;
 }

}