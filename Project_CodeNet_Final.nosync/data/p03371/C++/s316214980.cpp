#include<bits/stdc++.h>
using namespace std;
int ada(int a,int b){
    if(a-b/2>0){
        return a-b/2;
    }
    else{
        return 0;
    }
}
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int64_t sum=100000000000000000;
    for(int i=0;i<2*max(x,y)+1;i+=2){
        int64_t s=c*i+a*ada(x,i)+b*ada(y,i);
        sum=min(sum,s);
    }
    cout<<sum<<endl;
}
