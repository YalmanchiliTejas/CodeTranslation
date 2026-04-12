#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iterator>
#include <math.h>
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define dd double
#define mp make_pair
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // int T,p;
    // cin>>T;
    // for(p=1;p<=T;p++)
    // {
      ll N;
      cin>>N;
      ll A[N],i,j,k,a=0,b,c,sum[N],prod=0;
      for(i=0;i<N;i++)
      {
        cin>>A[i];
        a+=A[i];
        a=a%1000000007;
        sum[i]=a;
      }
      for(i=0;i<N;i++)
      {
        j=a-sum[i];
        if(j<0)
        j+=1000000007;
        prod=(prod+(j*A[i])%1000000007)%1000000007;
      }
      cout<<prod;
      return 0;
}