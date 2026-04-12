#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
   int n;cin>>n;
   vector<ll> v;
   int ans=200000;
   for(int i=0;i<n;i++){
       ll a;cin>>a;
       auto j=upper_bound(v.begin(),v.end(),a,greater<int>());
       if(j==v.end())v.push_back(a);
       else *j=a;
   }
   cout<<v.size();
}