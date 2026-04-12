#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,x,y,s1=0,s2=0,s3=0,s4=0,t,z=0,d;
  vector<long long int> kire,ki,it;
    cin>>a>>b>>c>>x>>y;
    s1 = a*x + b*y;
    //cout<<s1<<endl;
    //d[0] = s1;
    if(x < y)
    {
        s2 = (x+x)*c;
        s2 += (y-x)*b;
        d = min(s1,s2);
        z = (y+y)*c;
        t = min(d,z);
        //d[1] = s2;
    }
    else if(x > y)
    {
        s3 = (y+y)*c;
        s3 += (x-y)*a;
        //cout<<s3<<endl;
        //d[2] = s3;
        d = min(s1,s3);
        z = (x+x)*c;
        t = min(d,z);
    }
    if(x == y)
    {
        s4 = (x+x)*c;
        t = min(s1,s4);
    }


    cout<<t<<endl;


}

