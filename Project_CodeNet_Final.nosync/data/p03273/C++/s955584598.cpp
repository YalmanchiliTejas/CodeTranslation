#include <bits/stdc++.h>
using namespace std;

int main() {
int H,W;
cin>>H>>W;
vector <vector<char>>table(H,vector<char>(W));
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
cin>>table.at(i).at(j);
}
}
vector<int> wrow;
vector <int>wcolumn;
for(int i=0;i<H;i++){
bool x =true;
for(int j=0;j<W;j++){
if(table.at(i).at(j)=='#'){
x=false;
break;
}
}
if(x){
wrow.push_back(i);
}
}
for(int i=0;i<W;i++){
bool x =true;
for(int j=0;j<H;j++){
if(table.at(j).at(i)=='#'){
x=false;
break;
}
}
if(x){
wcolumn.push_back(i);
}
}

for(int i=0;i<H;i++){
bool p=true;
bool q = true;
for(int k:wrow){
if(i==k){
p=false;
break;
}}
if(p){for(int j=0;j<W;j++){
q=true;
for(int k:wcolumn){
if(j==k){
q=false;
break;}
}
if(p&&q){cout<<table.at(i).at(j);}}}
if(p){cout<<endl;}
}
}