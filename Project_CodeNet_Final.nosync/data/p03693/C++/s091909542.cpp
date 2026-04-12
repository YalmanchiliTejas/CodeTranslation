#include<bits/stdc++.h>
using namespace std;

int main(){

    int r,g,b,i,j,k,sum;
    cin>>r>>g>>b;

    i=r*100,j=g*10,k=b;

    sum=i+j+k;

    (sum%4==0)?cout<<"YES"<<endl:cout<<"NO"<<endl;

    return 0;
}
