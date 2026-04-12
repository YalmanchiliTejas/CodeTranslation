#include<iomanip>
#include <string>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
#include <numeric>
#include<math.h>
#include <ctype.h>
#include <algorithm> // sort
#include <map> // pair
using namespace std;
#define nin(n) int n; cin >> n;
#define kin(k) int k; cin >> k;
const int INF = 1001001001;
int main(){
  int n;
  cin >> n;
  vector< long long int> vec(n);
  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  long long ans=0;
  if(n%2==0){
    for(int i=0;i<n/2-1;i++){
      ans=ans+(vec.at(n-1-i)-vec.at(i))*2;
    }
    ans=ans+vec.at(n/2)-vec.at(n/2-1);
  }
  if(n%2!=0){
    for(int i=0;i<n/2;i++){
      ans=ans+(vec.at(n-1-i)-vec.at(i))*2;
    }
    if((vec.at(n/2)-vec.at(n/2-1))<(vec.at(n/2+1)-vec.at(n/2))){
      ans=ans-vec.at(n/2)+vec.at(n/2-1);
    }
    else{
      ans=ans+vec.at(n/2)-vec.at(n/2+1);
    }
  }
  cout << ans << endl;
}
    
            