#include<bits/stdc++.h>
using namespace std;

int main(){
int H,W;
  cin>>H>>W;
  char a[H][W];
  for(int i=0; i<H; i++){
   for(int j=0; j<W; j++){
    cin>>a[i][j];}}
  
  vector<bool>high(H, false), wide(W, false);
  for(int i=0; i<H; i++){
   for(int j=0; j<W; j++){
    if(a[i][j]=='#'){high[i]=true;}
   }}
  
  for(int i=0; i<W; i++){
   for(int j=0; j<H; j++){
    if(a[j][i]=='#'){wide[i]=true;}
   }}
  
  for(int i=0; i<H; i++){
    bool flag=false; 
   for(int j=0; j<W; j++){
    if(high[i]==true && wide[j]==true){
      cout<<a[i][j];
      flag=true;}
   }
    if(flag){cout<<endl;}
  }
  
}