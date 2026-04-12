#include<iostream>
using namespace std;
int main(){
        int r,g,b,sum=0;
        cin>>r>>g>>b;
        sum=r*100+g*10+b;
        if((r*100+g*10+b)%4==0)cout<<"YES"<<endl;
        else{
                cout<<"NO"<<endl;
        }
}

                                                                            