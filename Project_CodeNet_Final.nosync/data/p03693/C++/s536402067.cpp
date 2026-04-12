  #include <cstdio>
  #include <iostream>
  #include <string.h>
  #include <cstring>
  #include <cmath>
  #include <math.h>
  #include <algorithm>
  #include <iomanip>
  #include <map>
  #include <set>
  #include <vector>
  #include <sstream>
  #include <queue>  
  #include <bitset>
#define MAX 100005
#define INF 9999999999999
#define pb push_back
using namespace std;
typedef long long int ll;
 typedef pair<ll,ll> ii;
 typedef vector<ii> vii;
 typedef vector <ll > vi;
vector <vii> adj(MAX);
ll arr[200005];
int main()
{
//  freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll arr[200005];
  string str;
  ll n,a,b,c,p,q,sum=0,cnt=0;
  cin>>a>>b>>c;
  sum+=100*a+10*b+c;
  if(sum%4==0)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
 

 return 0;
}