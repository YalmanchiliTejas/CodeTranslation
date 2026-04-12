#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    long long n; cin>>n;
    long long x,y;
    x= n*800;
    y= (n/15)*200;
    cout<<x-y;
}
