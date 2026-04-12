#include<iostream>

using namespace std;

int main()
{
    int result=0;
    int r,g,b;

    cin>>r>>g>>b;


    result=result*10 + r;

    result=result*10 + g;

    result=result*10 + b;


    if(result%4==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}
