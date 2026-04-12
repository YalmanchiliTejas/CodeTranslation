#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace::std;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int sum;
    sum=r*100+g*10+b;
    if(sum%4==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;

}