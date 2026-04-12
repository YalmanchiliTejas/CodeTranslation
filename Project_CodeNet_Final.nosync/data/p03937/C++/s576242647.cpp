#include <bits/stdc++.h>
using namespace std;
int main(){
int counter1,counter2;
counter1=0;
counter2=0;
int b;
int c=0;
int k=0;
int H,W; cin>>H>>W;
int counter=W+H+10;
int count=-1;
char a[H][W];
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
cin>>a[i][j];}}
for(int i=0;i<H;i++){
for(int j=0;j<W;j++){
if(a[i][j]=='#'){
counter1++;
}}}
if(W+H-1==counter1){
cout<<"Possible"<<endl;}
else{
cout<<"Impossible"<<endl;}}
