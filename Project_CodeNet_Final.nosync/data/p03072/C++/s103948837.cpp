#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;


int main(){
int n;cin>>n;vector<int>v(n);
for(int i=0;i<n;i++){
int a;cin>>a;
v[i]=a;
}
int count =0,max=0;
for(int i=0;i<n;i++){
    if(v[i]>=max){
        max=v[i];
        count ++;
    }
}
cout<<count;

}