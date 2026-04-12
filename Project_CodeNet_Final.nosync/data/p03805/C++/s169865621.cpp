/// Author: Sarfaraz Alam
# include <bits/stdc++.h>
# define pb push_back
# define ll long long
# define fi first
# define se second
# define all(vc) vc.begin(),vc.end()
# define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
# define DEBUG
typedef unsigned long long int ull;
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;

//int a[N], ans = 1, x;


bool vis[N] ;
vector<int>adj[N];

void dfs(int x , int n, int * c, int * cont)
{
  //cout<<"inside the dfs\n";

  vis[x] = true;
    *c = *c + 1;
  if(*c == n)
    *cont = *cont + 1;



  for(auto u: adj[x])
  {
    if(vis[u] == true)continue;
    dfs(u , n, c, cont);
    //vis[u] = false;
  }

  vis[x] = false;
  *c =  *c - 1;

}











int main()
{

  //  cout<<"works till before taking input\n";

    //Code begins
    ll n,  m;
    cin>>n>>m;
    ull v1, v2;


    while(m--)
    {
        cin>>v1>>v2;
    //    cout<<"inside the input loop\n";
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    ///cout<<"works till here|\n";
    // for(auto x: adj)
    // {
    //   for(auto e : x)
    //   cout<<e<<" ";
    //   cout<<endl;
    // }

    int cont = 0;
    int c = 0;
    dfs(1, n, &c, & cont);
    //cout<<"succes\n";

    cout<<cont<<endl;
    return 0;
}
