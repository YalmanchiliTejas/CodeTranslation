#include <iostream>

using namespace std;

int main()
{
    int N,sum,Y;
    cin>>N;
    Y=(N/15)*200;
    sum = (N * 800)-Y;
    cout<<sum;
    return 0;
}
