#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c=0,d,e,f,g,i,j,k;
    cin>>a>>b>>c;
    d=(a*100)+(b*10)+c;
    if(d%4==0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
