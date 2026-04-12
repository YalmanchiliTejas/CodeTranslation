#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int x=0;
    int temp;
    cin>>temp;
    x += temp*100;
    cin>>temp;
    x += temp*10;
    cin>>temp;
    x += temp;
    if (x%4) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}