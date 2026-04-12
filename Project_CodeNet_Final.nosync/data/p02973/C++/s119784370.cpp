#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e10
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;

//bit全探索
vector<ll>bitSearch(int bit,int n){
    vector<ll>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    S.push_back(1e9);
    return S;
}

int main(){
   int n;
   cin >> n;
   vector<ll> a(n);
   bool f = true;
   rep(i, n){
      cin >> a[i];
      if(i == 0)continue;
      if(a[i - 1] != a[i])f = false;
   }
   if(f){
      cout << n << endl;
      return 0;
   }
  
   vector<ll> list(n);
   rep(i, n){
      list[i] = - (2 * n) + i;
   }
   rep(i, n){
      int lb = lower_bound(ALL(list), a[i]) - list.begin();
      if(list[lb] < 0){
         list[lb] = a[i];
      }
      else {
         list[lb - 1] = a[i];
      }
     //sort(ALL(list));
   }
   ll res = 0;
   rep(i, n){
      if(list[i] > 0)res++;
   }
   cout << res << endl;
  //for(auto l : list)cout << l << " ";
}