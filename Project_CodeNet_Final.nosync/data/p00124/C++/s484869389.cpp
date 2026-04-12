#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct www_t{
  string name;
  int w;
  int l;
  int d;
  int p;
  int num;
};

bool asc(www_t left,www_t right) {
    return left.p == right.p ? left.num < right.num : left.p > right.p;
}

int main(){
  int n;
  scanf ("%d",&n);
  while(n){
    vector<www_t> a(n);
    for(int t=0;t<n;++t){
      cin >> a[t].name >> a[t].w >> a[t].l >> a[t].d;
      a[t].num=t;
      a[t].p=a[t].w*3+a[t].d;
    }
    sort(a.begin(), a.end(),asc);
    for(int t=0;t<n;++t){
      cout << a[t].name << "," << a[t].p << endl;
    }
    scanf ("%d",&n);
    if(n){
      printf("\n");
    }
  }
}

