#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
#include<set>
#include<cctype>
#include<iomanip>
using namespace std;

struct p{
int h;
int w;
int n;
bool flag=false;
};
int main(){
ios::sync_with_stdio(false);
/***
#ifdef ONLINE_JUDGE
#else
    freopen("1.txt", "r", stdin);
#endif
***/
int a,b,c,x,y;
cin>>a>>b>>c>>x>>y;
int commont_part=(x<y?x:y);
int sum=0;
if(a+b>2*c) sum+=2*c*commont_part;
else        sum+=commont_part*(a+b);
if((x-commont_part)*a+(y-commont_part)*b<2*c*(x-commont_part+y-commont_part))
{
    sum+=(x-commont_part)*a+(y-commont_part)*b;

}
else{
    sum+=2*c*(x-commont_part+y-commont_part);
}
cout<<sum;


 return 0;
}
