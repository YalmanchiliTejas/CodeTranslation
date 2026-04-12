#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};

int main(){
    int x;
    cin>>x;
    if(x==3 or x==5 or x==7) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
