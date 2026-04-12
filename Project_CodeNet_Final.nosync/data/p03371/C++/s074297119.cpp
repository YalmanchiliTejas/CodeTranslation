#include<bits/stdc++.h>
using namespace std;
int a,b,x,y,c;
int checks,pa,pb;
int main(){
    cin>>a>>b>>c>>x>>y;
    pa=x;pb=y;
    if(c*2<a+b){
        checks+=c*min(x,y)*2;
        pa-=min(x,y);
        pb-=min(x,y);
    }

    if(c*2>a&&pa>0){
        checks+=a*pa;
        pa=0;
    }

    if(c*2>b&&pb>0){
        checks+=b*pb;
        pb=0;
    }
    if(pb>0||pa>0){
        checks+=c*max(pa,pb)*2;
    }
    cout<<checks<<endl;





}
