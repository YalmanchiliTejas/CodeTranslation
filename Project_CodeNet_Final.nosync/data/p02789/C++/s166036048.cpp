#include <bits/stdc++.h>

#define FOR0(i,n) for (int i = 0; i < n; i++)
#define FOR(i,j, n) for (int i = j; i < n; i++)
// bool isEven(ll n) {return (n%2!=0)?false:true;};
#define INF 1000000000 // 1 billion, safer than 2B for Floyd Warshall’s

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
// #define int ll


using namespace std;
typedef pair<int, pair<int, int> > ppp;

//leetcode

int main()
{
	int m, n;
  cin>>m>>n;
  if(m==n)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}