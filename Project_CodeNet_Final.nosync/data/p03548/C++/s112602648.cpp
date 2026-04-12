#include <bits/stdc++.h>
#include <algorithm>
#include <limits>
#include <cmath> 
using namespace std;

int main(){
    int X,Y,Z;
    cin>>X>>Y>>Z;

    int ans;
    if(X%(Y+Z)>=Z)ans=X/(Y+Z);
    else ans=X/(Y+Z)-1;
    cout<<ans<<endl;
}