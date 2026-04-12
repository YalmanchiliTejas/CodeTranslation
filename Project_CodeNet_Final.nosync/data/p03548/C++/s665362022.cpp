#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e=0;
    cin>>a>>b>>c;
        d=(a-1)%(b+c);
    if(c-d<2) cout<<(a-1)/(b+c)<<endl;
    else cout<<(a-1)/(b+c)-1<<endl;
}
