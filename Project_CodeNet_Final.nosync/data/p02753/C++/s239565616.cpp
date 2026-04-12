#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<map>
#define ll long long
#define fi first
#define se second
#define INIT() std::ios::sync_with_stdio(false)
using namespace std;
const int INF=0x7fffffff;
const double EPS=1e-6;
const int MAX_N=1000000+5;
string s;
int main (void)
{
    cin>>s;
    int i;
    int flag=0;
    if((s!="AAA")&&(s!="BBB"))
        flag=1;
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


}