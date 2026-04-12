#include<iostream>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int r;
    int g;
    int b;
    cin>>r>>g>>b;
    int s=r*100+g*10+b;
    
    if (s%4==0) {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}
