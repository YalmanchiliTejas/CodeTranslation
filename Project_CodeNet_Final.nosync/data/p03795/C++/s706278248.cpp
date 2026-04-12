#include<iostream>
using namespace std;
int main(){
     int w,x;
    cin>>w;
    if(w<15){cout<<w*800;}
    else if(w>15){x=w/15;cout<<(w*800)-(x*200);}
    else if(w==15){cout<<(w*800)-200;}


    return 0;

}
