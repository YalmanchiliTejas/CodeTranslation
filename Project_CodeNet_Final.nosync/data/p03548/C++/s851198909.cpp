#include <bits/stdc++.h>
using namespace std;
int main(){
    int X,Y,Z;
    cin>>X>>Y>>Z;
    X-=Z;
    X=X/(Y+Z);
    cout<<X<<endl;
}