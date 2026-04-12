#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int gcd(int a,int b){
    if(a%b==0){
        return b;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    cout<<(x-z)/(y+z)<<endl;
  return 0;
}