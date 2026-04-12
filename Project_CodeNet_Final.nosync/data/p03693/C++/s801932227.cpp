#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int t=100*r+10*g+b;
    cout<<(t%4?"NO":"YES")<<endl;
}