#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
vector<int> a;

bool isOK(int index,int key){
  if(a[index]<key)return true;
  else return false;
}

int binary_search(int key) {
    int left = -1;
    int right = (int)a.size();

   while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    return right;
}

int main(void){
  int n,t,x,i,c;
  cin>>n>>x;
  a.push_back(x);
  for(i=1;i<n;i++){
    cin>>x;
    t=binary_search(x);
    if(t==a.size()){
      a.push_back(x);
    }
    else{
      a[t]=x;
    }
  }

  cout<<a.size()<<endl;

	return 0;
}
