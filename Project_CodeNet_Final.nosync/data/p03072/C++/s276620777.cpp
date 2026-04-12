#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
using namespace std;
#define MAX 300000
typedef long long ll;

int main(){
  int n;
  cin>>n;
  int h,maxh,count=1;
  cin>>maxh;
  for(int i=1;i<n;i++){
    cin>>h;
    if(h>=maxh){
      count++;
      maxh=h;
    }
  }
  cout<<count<<endl;
  
}
