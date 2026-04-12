#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int k=r*100+g*10+b;
    if(k%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

