#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <deque>
using namespace std;

typedef long long ll;

int main(){
   int N;
   cin >> N;
   vector<int> v;
   for(int i = 0; i < N; i++){
       int A;
       cin >> A;
       if(v.size() == 0){
           v.push_back(A);
       } else if(A > v[0]){
           v[0] = A;
       } else if(v[v.size()-1] >= A){
           v.push_back(A);
       } else {
           int l = -1, r = v.size();
           while(r-l > 1){
               int m = (l+r)/2;
               if(v[m] >= A){
                   l = m;
               } else  r = m;
           }
           v[r] = A;
       }
   }

   cout << v.size() << endl;
}

