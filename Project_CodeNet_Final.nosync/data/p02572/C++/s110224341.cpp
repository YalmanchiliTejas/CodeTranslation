#include <iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<cmath>

#include<cstdlib>

#include<utility> 

#include<cstdio> 

#define vii vector< pair<int,int> >

#define vi vector<int>

#define INF 1000000007

#define ff first

#define ss second

#define lli long long int

#define ulli unsigned long long int

using namespace std;

int main() {

 ios_base::sync_with_stdio(false);

    cin.tie(NULL);

  int n;

  cin>>n;

  vi v(n);

  for(int i=0; i<n; i++)

  cin>>v[i];

  ulli sum=0, ans=0;

  for(int i=0; i<n; i++)

  ans+=v[i]%INF;

  for(int i=0; i<n; i++){

    ans-=v[i]%INF;   

    sum+=((v[i]%INF)*(ans%INF))%INF;

  }

  cout<<sum%INF<<endl;

 // cout<<12839201%INF;

}