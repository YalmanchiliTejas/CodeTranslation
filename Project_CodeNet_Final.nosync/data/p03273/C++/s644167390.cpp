#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <deque>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<pi,int>
#define sqr(x) ((x)*(x))
#define FOR for(int i=0;i<n;i++)for(int j=0;j<m;j++)
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m;
string asd[110];
bool f[110],c[110];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>asd[i];
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<m;j++)if(asd[i][j]=='#'){flag=false;break;}
        f[i]=flag;}
    for(int j=0;j<m;j++){
        bool flag=true;
        for(int i=0;i<n;i++)if(asd[i][j]=='#'){flag=false;break;}
        c[j]=flag;}
    for(int i=0;i<n;i++){
        if(f[i])continue;
        for(int j=0;j<m;j++)if(!c[j])cout<<asd[i][j];
        cout<<'\n';}
    return 0;
}
