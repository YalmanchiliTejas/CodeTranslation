#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
using namespace std;
int main() {
    int r,g,b;
    cin>>r>>g>>b;
    if((10*g+b)%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}   


