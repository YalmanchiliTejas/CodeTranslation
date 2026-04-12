#include<iostream>
using namespace std;
int main()
{
    long long n,sum;
    while(cin>>n)
    {
        sum=800*n-200*(n/15);
        cout<<sum<<endl;
    }
    return 0;
}
