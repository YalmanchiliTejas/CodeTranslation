#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N=0,X=0,Y=0,result=0;
    cin>>N;
    X=(N/15)*200;
    Y=N*800;
    result=Y-X;
    cout<<result<<"\n";
    return 0;
 
}