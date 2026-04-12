#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
    long long int x,y,i,j,k,n,z,a,b,c;
    vector<long long int>v,u,w;
    //string s;
    map<long long int ,long long int>m;
    cin>>a>>b>>c>>x>>y;
    if(2*c>a+b)
    {
        cout<<a*x+b*y<<endl;
    }
    else
    {
        i=min(x,y);
        j=max(x,y);
        if(x>y)
        cout<<min(j*c*2,i*c*2+(j-i)*a)<<endl;
        else
            cout<<min(j*c*2,i*2*c+(j-i)*b);
    }

    return 0;

}
