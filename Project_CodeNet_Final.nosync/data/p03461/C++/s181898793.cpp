#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ld long double
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define piii pair<pii,pii>
#define precise cout<<fixed<<setprecision(10)
#define st first
#define nd second
#define ins insert
#define vi vector<int>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX=105;
const int inf=1e9+9;
int tab[MAX][MAX];
int f[MAX][MAX];
int32_t main()
{
  BOOST;
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++)
  	for (int j=1;j<=m;j++)
  		cin>>tab[i][j];
  for (int i=0;i<=100;i++)
    for (int j=0;j<=100;j++)
       for (int k=1;k<=n;k++)
         for (int l=1;l<=m;l++)
           f[i][j]=max(f[i][j],tab[k][l]-i*k-j*l);
           
  for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
    {
    	int mini=inf;
    	for (int k=0;k<=100;k++)
    	  for (int l=0;l<=100;l++)
    	    mini=min(mini,f[k][l]+i*k+j*l);
    	if (mini!=tab[i][j])cout<<"Impossible",exit(0);
    }
   
    cout<<"Possible\n";
  cout<<"202 "<<"10401\n";
  for (int i=1;i<=100;i++)cout<<i<<" "<<i+1<<" "<<"X"<<"\n";
  for (int i=102;i<=201;i++)cout<<i<<" "<<i+1<<" "<<"Y"<<"\n";
  for (int i=0;i<=100;i++)
    for (int j=0;j<=100;j++)
      cout<<i+1<<" "<<202-j<<" "<<f[i][j]<<"\n";
  cout<<"1 "<<"202";
  
  return 0;
}

