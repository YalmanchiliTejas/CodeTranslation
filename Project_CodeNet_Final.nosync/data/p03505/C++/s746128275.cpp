#include<bits/stdc++.h>
using namespace std;
long long a,b,k;
int main(){
    cin>>k>>a>>b;
    if(k<=a){
        cout<<"1"<<endl;return 0;
    }
    else if(a<=b){
        cout<<"-1"<<endl;return 0;
    }
    else cout<<(((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1)<<endl;
    return 0;
}