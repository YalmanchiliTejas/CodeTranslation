#include<iostream>
#include<cstdlib>
using namespace std;
const int max_n=100;
int main()
{
    int n,h[max_n],tmp,num;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    tmp = h[0];
    num= 1;
    for (int i=1;i<n ;i++ )
    {
        if(h[i]>=tmp)
            num++;
        if(h[i]>tmp)
            tmp = h[i];
    }
    cout<<num;


    //system("pause");


}
