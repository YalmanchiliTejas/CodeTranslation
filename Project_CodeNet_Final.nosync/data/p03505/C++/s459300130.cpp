#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	long long a,b,c,mls=0,j=0;
    cin>>a>>b>>c;
    if(b>=a){
        cout<<1<<endl;
        return 0;
    }
    if(c>=b){
        cout<<-1<<endl;
        return 0;
    }
    if((a-b)%(b-c)>=1) mls=1;
    j=((a-b)/(b-c)+mls)*2+1;
    cout<<j<<endl;
}