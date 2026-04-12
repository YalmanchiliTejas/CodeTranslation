#include<bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define pb push_back
#define sd(x) scanf("%d",&x)
#define nax 101010
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define mp make_pair
#define pi pair<int ,int>
#define pii pair <pi,pi>
using namespace std;
int arr[200];
int fix[10];
int main(int argc, char const *argv[])
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int r,g,b;
  cin >> r >> g >> b;
  int x = (g*10+b)%4;
  if(x)
    cout<< "NO\n";
  else
    cout<<"YES\n";
  return 0;
}
 