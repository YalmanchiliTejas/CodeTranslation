#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,max=0,m,c=0;
    cin>>n;
    while(n--){
        cin>>m;
        if(m>=max){
            max=m;
            c++;
        }
    }
    cout<<c<<"\n";
}