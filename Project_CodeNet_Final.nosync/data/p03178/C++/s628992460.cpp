#include <bits/stdc++.h>
#define endl '\n'
#define modulo 1000000007
#define PI acos(-1)
#pragma GCC target ("avx2")
#pragma GCC optimize("trapv")
#define int long long
#define sinDegrees(x) sin((x) * PI / 180.0)
#define cosDegrees(x) cos((x) * PI / 180.0)
#define tanDegrees(x) tan((x) * PI / 180.0)
#define atanDegrees(x) atan(x)* 180.0 / PI
using namespace std;
int power(int x,int y,int m)
{
int temp;
if(y == 0)
return 1;
temp = (power(x, y/2,m))%m;
if (y%2 == 0)
return ((temp%m)*temp);
else
return ((x*temp%m)*temp%m)%m;
}
int inv(int x)
{
return (power(x,modulo-2,modulo))%modulo;
}
bool comp(int a,int b)
{
return a>b;
}
///solution created by: Ahmadsm2005
int DP[10001][101][2];
int32_t main()
{
//freopen("output.txt","w", stdout);
//freopen("rect.in","r", stdin);
iostream::sync_with_stdio(0);
cin.tie(0);
string s;
cin>>s;
int m;
cin>>m;
for(int i=0;i<s.size();i++){
for(int l=0;l<m;l++){
for(int x=0;x<=(s[i]-'0');x++){
DP[i+1][(l+x)%m][(x<(s[i]-'0')?1:0)]=(DP[i+1][(l+x)%m][(x<(s[i]-'0')?1:0)]+DP[i][l][0]+((i|l)?0:1))%modulo;
}
for(int x=0;x<=9;x++){
DP[i+1][(l+x)%m][1]=(DP[i+1][(l+x)%m][1]+DP[i][l][1])%modulo;
}
}
}
cout<<((DP[s.size()][0][0]+DP[s.size()][0][1]-1)%modulo+modulo)%modulo;
return 0;
}
