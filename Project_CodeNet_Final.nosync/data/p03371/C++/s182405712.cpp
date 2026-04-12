#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
ll a,b,c,x,y;
cin >>a>>b>>c>>x>>y;
ll sum=0;
if(a>=2*c){
sum+=2*c*x;
y=y-x;
if(b>=2*c){
if(y>0){
sum+=2*c*y;
}
}
}
else if(b>=2*c){
sum+=2*c*y;
x=x-y;
if(x>0){
sum+=a*x;
}
}
else if(a+b>=2*c){
if(x<y){
sum+=2*c*x;
y=y-x;
sum+=b*y;
}
else{
sum+=2*c*y;
x=x-y;
sum+=a*x;
}
}
else{
sum=a*x+b*y;
}
cout<< sum;
return 0;

}