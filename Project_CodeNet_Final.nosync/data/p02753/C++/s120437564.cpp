#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<string>
using namespace std;
typedef pair<int,int> P;
typedef long long LL;
typedef unsigned long long ULL;
const LL mod=1e9+7;
const LL LL_MAX=9223372036854775807;
const LL maxn=4e5+10;
const double eps=1e-9;
LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int read1()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
    set<char> se;
    se.clear();
    string s;
    cin>>s;
    se.insert(s[0]);se.insert(s[1]);se.insert(s[2]);
    if(se.size()==1){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}

