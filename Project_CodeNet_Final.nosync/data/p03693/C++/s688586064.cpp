#include <algorithm>
#include <cstdlib>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
int r,g,b;

int main(int argc, char const *argv[])
{
    cin>>r>>g>>b;
    if((g*10+b)%4==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
