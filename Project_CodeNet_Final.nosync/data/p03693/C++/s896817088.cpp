#include<iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int n = a * 10;
    n += b;
    n *= 10;
    n += c;
    if(n % 4 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
