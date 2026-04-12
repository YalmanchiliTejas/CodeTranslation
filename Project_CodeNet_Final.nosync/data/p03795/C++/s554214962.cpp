#include<bits/stdc++.h>
using namespace std;
#define str string
#define rep(x) for(int y=0;y<x;y++)
#define all(x) begin(x),end(x)
int main(){
    int A,B,C,D;
    vector<char>s(19);
    cin>>A;
    B=A/15;
    if(A<15)B=0;
    cout<<800*A-200*B<<endl;
}
