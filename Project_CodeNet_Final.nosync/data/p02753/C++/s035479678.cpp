#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include <queue>
#include <set>
#include <stack>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
using namespace std;
const int MAXN=1e6+50;
const int inf=0x3f3f3f3f;
const int M=5000*4;
char ch[MAXN];
int main()
{
    cin>>(ch+1);
    int f1=0,f2=0;
    for(int i=1;i<=3;i++){
        if(ch[i]=='A')f1++;
        if(ch[i]=='B')f2++;
    }
    if(f1==0||f2==0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
/*

*/

