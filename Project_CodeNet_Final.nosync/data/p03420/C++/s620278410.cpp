#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<array>
#include<vector>
#include<set>
#include <utility>
#include <map>
#include<bitset>

using namespace std;



int main(){
int n,k; cin>>n>>k;

long long ans=0;

for(int i=k+1;i<=n;i++){
  ans+=(n/i)*(i-k);
  if(n%i==0){continue;}
  else {ans+=max(n%i-max((k-1),0),0); }

}
cout<<ans<<endl;
}
