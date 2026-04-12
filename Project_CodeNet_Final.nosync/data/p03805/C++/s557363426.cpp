#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
#include <map>
#include <stack>
using namespace std;

#define mod 1000000007
#define ten5 100005
#define ten52 200005
#define ten6 1000005
#define PI 3.1415926
#define pb(x) push_back(x)

typedef long long int ll;

ll general,total;
//ll chk[55];
//ll num[55];
//ll num2[55];
//ll num[ten5];
//ll num2[ten5];
//char cmap[10][10];
//priority_queue<long long int> pq;   //big at front
//stack<int> stk;
//vector<pair<ll,ll>> vpll;
vector<ll> vll[9];
//deque<ll> deq[55];
//list<int> li;
//set<int> sint;
set<ll> sll;
map<ll,ll> mp;

ll dfs(ll);

int main()
{
    //double ans=0.0,half;
    //float f,g,h;
    long long int sum,sum2,n1,n2,n3;
    long long int m,n,o,i,j,k=1;
    long long int a,a1,a2,a3,a4,a5,a6;
    sum=sum2=n1=n2=n3=0;
    a=a1=a2=a3=a4=a5=a6=0;
    //string s,s1;
    //char now,pre,c;
    cin>>n>>m;general=n;total=0;
    for(i=0;i<m;i++)
    {
        cin>>a1>>a2;
        vll[a1].pb(a2);
        vll[a2].pb(a1);
    }
    dfs(1);
    cout<<total;
    return 0;
}

ll dfs(ll n)
{
    if(sll.find(n)!=sll.end()) return 0;
    sll.insert(n);
    if(sll.size()==general)
    {
        sll.erase(n);
        return 1;
    }
    for(int i=0;i<vll[n].size();i++)
        total+=dfs(vll[n][i]);
    sll.erase(n);
    return 0;
}


