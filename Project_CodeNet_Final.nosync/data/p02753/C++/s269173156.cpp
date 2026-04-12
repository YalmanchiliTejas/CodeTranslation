///******* In the name of Allah *******///

#include <bits/stdc++.h>
using namespace std;

long int gcd(long int a, long int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void Ok()
{
    long long int a,b,c,d,e,f,g,h,t,i,j,k,l,m,n,sum,ans_1,ans_2,ans_3,cnt = 0,Max,Min,flag,div,rcv,temp;
    long double aa,bb,cc,dd,ee,ff,gg;
    char aaa[1013],bbb[1013],ccc[1013],alpbt;
    long long int sum_again;
    string spc;

    cin>>aaa;
    if(aaa[0]=='A' && aaa[1]=='B' && aaa[2]=='B')
        cout<<"Yes"<<endl;
    else if(aaa[0]=='B' && aaa[1]=='A' && aaa[2]=='A')
        cout<<"Yes"<<endl;
    else if(aaa[0]=='B' && aaa[1]=='A' && aaa[2]=='B')
        cout<<"Yes"<<endl;
    else if(aaa[0]=='A' && aaa[1]=='B' && aaa[2]=='A')
        cout<<"Yes"<<endl;
    else if(aaa[0]=='B' && aaa[1]=='B' && aaa[2]=='A')
        cout<<"Yes"<<endl;
    else if(aaa[0]=='A' && aaa[1]=='A' && aaa[2]=='B')
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return;
}

int main()
{
    Ok();

    return 0;
}
