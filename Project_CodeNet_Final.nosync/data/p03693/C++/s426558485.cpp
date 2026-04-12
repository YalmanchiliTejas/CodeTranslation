#include <bits/stdc++.h>
using namespace std;
int main(){
int r,g,b;
int sum;
cin>>r>>g>>b;
sum=r*100+g*10+b;
if(sum%4)
    cout<<"NO";
    else cout<<"YES";
}

