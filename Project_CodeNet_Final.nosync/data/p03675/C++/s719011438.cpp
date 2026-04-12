#include<iostream>
using namespace std;
int main(){
int i;
cin >> i;
int a[i];
int j;
for(j=0;j<i;j++){
cin >> a[j];
}
int b[i];
int k;
k=i/2;
int n;
n=i-1;
if(i==1){
b[0]=a[0];
}
else if((i%2)==1){
for(j=0;j<k;j++){
b[j]=a[n];
n=n-2;
}
int s;
s=j;
b[s]=a[0];
s++;
n=1;
for(j=0;j<k;j++){
b[s]=a[n];
n=n+2;
s++;
}
}
else{
for(j=0;j<k;j++){
b[j]=a[n];
n=n-2;
}
int s;
s=j;
b[s]=a[0];
s++;
n=2;
for(j=0;j<k-1;j++){
b[s]=a[n];
s++;
n=n+2;
}
}
for(j=0; j<i ; j++){
cout << b[j] <<" ";
}
return 0;
}