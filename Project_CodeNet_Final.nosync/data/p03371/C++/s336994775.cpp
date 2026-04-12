#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,x,y; cin>>a>>b>>c>>x>>y;

    long long int min=100000000000;
  
    long long int s;
    for(int i=0;i<=max(x,y)*2;i+=2){
        
        s=c*i+a*max(0,x-i/2)+b*max(0,y-i/2);

        if(s<min){
            min=s;
        }
    }    

    cout<<min<<endl;
}