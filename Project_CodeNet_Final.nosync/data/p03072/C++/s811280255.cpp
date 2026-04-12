

#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15

int main(){

 long long n;
 cin>>n;

 int a[n];

 for(int i=0;i<n;i++)
    cin>>a[i];


  int maxi= a[0],cnt=1;

  for(int i=1;i<n;i++){

     if(a[i] >= maxi){
     //   cout<<a[i]<<" "<<i<<endl;
      cnt++;
      maxi = a[i]; }
  }

  cout<<cnt<<endl;

  return 0;
}

