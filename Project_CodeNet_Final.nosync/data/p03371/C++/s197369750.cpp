#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main(){
    long long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    long num=min(X,Y);
    long sum=0;
    sum += min(2*(C),A+B)*num;
    if(X-num>0){
        sum += min(A,2*C)*(X-num);
    }
    if(Y-num>0){
        sum += min(B,2*C)*(Y-num);
    }
  cout<<sum<<endl;
}