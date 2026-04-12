#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926

typedef long long int ll;

//ll num[50];
//ll num2[50];
ll num[10];
//set<ll> sll;
//map<string,ll> mp,mp1;
//map<string,ll>::iterator iter;


int main(void)
{
    long long int sum=0,range=0,ceiling;
    double ans=0.0,d;
    long long int m,n,o,i,j,k=1,money;
    long long int a,a1=0,a2=0,a3=0,ar=1,as=1,at1;
    string s;
    char c;
    a=a1=a2=a3=0;
    //vector <int> v;
    //float f,g,h;
    //int c,d,big=0;
    cin>>s;
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}



