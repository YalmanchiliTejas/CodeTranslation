#include <bits/stdc++.h>
using namespace std;
int main(){
long long i;
long long counter=0;
long long A,B,C,X,Y;
cin>>A>>B>>C>>X>>Y;
if(A>=2*C&&B>=2*C){
long long i=2*C*max(X,Y);
cout<<i<<endl;
}
else if(A+B<2*C){
i=A*X+B*Y;
cout<<i<<endl;
}
else{
while(X>0&&Y>0){
X=X-1;
Y=Y-1;
counter=counter+2;}
if(2*C<=A&&X>0){
cout<<C*(counter+2*X)<<endl;}
if(2*C<=B&&Y>0){
cout<<C*(counter+2*Y)<<endl;}
else
cout<<C*counter+X*A+Y*B<<endl;}}



