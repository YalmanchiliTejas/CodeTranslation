#include<iostream>
using namespace std;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int total=0;
    if(a+b>2*c){
        int pizza=min(x,y);
        x-=pizza;
        y-=pizza;
        total+=pizza*2*c;
    }
    if(x>0)
    {
        if(a>2*c)
        {
            total+=x*2*c;
        }
        else
        {
            total+=x*a;
        }
    }
    if(y>0)
    {
        if(b>2*c)
        {
            total+=y*2*c;
        }
        else
        {
            total+=y*b;
        }
    }
    cout<<total;
}