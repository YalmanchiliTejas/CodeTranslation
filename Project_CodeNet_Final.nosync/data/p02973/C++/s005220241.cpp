#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> ns(n+100);
    rep(i, n+100) ns.at(i) = -1;
	int max = 0;
    int nk = n/100;
    if(n < 100){
      for(int i=0; i<n; i++){
          int a;
          cin >> a;
          rep(j, n){
              if(max < j) max = j;
              if(ns.at(j) < a){
                ns.at(j) = a;
                break;
              }
          }
      }
    }else{
      for(int i=0; i<n; i++){
          int a;
          cin >> a;
      	  int l = 0;
      	  for(int k=0; k<=nk+1; k++){
          	if(ns.at(k*100) < a){
              l = k;
              break;
            }
          }
          for(int j=100*l-100; j<=100*l; j++){
            if(j >= 0){
              if(max < j) max = j;
              if(ns.at(j) < a){
                ns.at(j) = a;
                break;
              }
            }
          }
      }
    }
    cout << max+1 << endl;
}