#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int a,b,c;
    cin>>a>>b>>c;
    int d=a-c;
    int e=0;
    while(d>=b+c){
        d-=b+c;
        e++;
    }
    cout<<e;
    return 0;
}
