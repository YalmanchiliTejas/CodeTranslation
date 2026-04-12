#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int r,g,b;
    cin>>r>>g>>b;
    cout<<(((g*10+b)%4==0)?"YES":"NO");
    return 0;
}