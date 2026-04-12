#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define pu push
#define pp pop_back
#define in insert
#define forn(low,high,i) for(i=low;i<high;i++)
#define forrev(high,low,i) for(i = high; i>= low;i--)                                 //g++ template.cpp -o template.exe
#define zeroes(x) memset(x,0,sizeof(x))                                        //all elements to 0  |  \   \0
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =1e9+7;
const ll maxn=100000;







bool sortbysec(const pair<int,int> &a,                         //sorting of elements wrt second
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

bool sortinrev(const pair<int,int> &a,                   //sorting in descending wrt first 
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
bool sortinrevsec(const pair<int,int> &a,                  //sorting in dsc wrt second
               const pair<int,int> &b) 
{ 
       return (a.second > b.second); 
} 




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif



    
  int n;
  cin>>n;
  

  if(n<30)
    cout<<"No";
  else
    cout<<"Yes";

  



  return 0;
}