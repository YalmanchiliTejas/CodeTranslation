#include<bits/stdc++.h>
using namespace std;
#define ll int64_t
#define ul unsigned long long int
#define vi vector<int>
#define vl vector<int64_t>
#define all(x) x.begin(),x.end()
#define pb push_back
#define fo(x,a,b) for(int x=a; x<b; x++)
#define rfo(x,a,b) for(int x=a; x>=b; x--)
#define fi first
#define sec second
#define mp make_pair
int sgn(int x) { return x>0 ? 1 : ( x<0 ? -1 : 0); }
typedef pair<int,int> pairs;
double pi = 3.14159265358979323846;
ll mod = 1000000007;

void solve()
{
    int temp;
  cin>>temp;
  if(temp>=30) cout<<"Yes";
  else cout<<"No";
    cout<<"\n";
    return;
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    {
        solve();
    }
    return 0;
}