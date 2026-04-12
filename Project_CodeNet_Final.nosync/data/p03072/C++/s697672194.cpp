#include <iostream>
#include <cstdio>
#define PI 3.14159267
using namespace std;
int main() {
    int x,h,max,num=1;
    cin>>x;
    cin>>h;
    max=h;
    for(int i=1;i<x;++i)
    {
        cin>>h;
        if(h>=max)
        {
            ++num;
            max=h;
        }
    }
    cout<<num<<endl;
}