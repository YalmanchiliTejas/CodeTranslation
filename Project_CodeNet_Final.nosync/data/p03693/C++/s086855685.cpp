#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include<vector>
#include<stack>
#include<cstdlib>
#include<queue>
#include<list>
using namespace std;

int main(){
    int r, g, b;
    cin>>r>>g>>b;
    if((g*10+b)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
