#include<bits/stdc++.h>

using namespace std;

int main(){

  while(1){

    int n,sum,ave;
  cin >> n;
  vector<int>vec(n);
  sum=0;
  ave=0;

  if(n==0)break;

  for(int i=0;i<n;i++){
    cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());

  for(int i=1;i<n-1;i++){
    sum+=vec.at(i);
  }

  ave = sum/(n-2);
  cout << ave <<endl;
  }


}

