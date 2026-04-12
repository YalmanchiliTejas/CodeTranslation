#include<bits/stdc++.h>
using namespace std;
int main()
{
    //ifstream cin("input.in");
   // ofstream cout("output2.out");
    ios::sync_with_stdio(0);cin.tie(0);
    long A,B,C;
    cin>>A>>B>>C;
    A*=100;
    B*=10;
    C+=(A+B);
    if(C%4)
        cout<<"NO";
    else
        cout<<"YES";
}