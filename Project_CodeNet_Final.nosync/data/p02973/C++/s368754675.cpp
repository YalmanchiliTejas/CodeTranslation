#include <bits/stdc++.h>
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf("%.12lf\n",mid);
// __builtin_popcount(int) count 1's in binary
// get decimal pert of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
int mod = 998244353;

long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}

/*string sentence = "And I feel fine...";
    istringstream iss(sentence);
*/  

double eps = .000000001;

int main ()
{
  prep();
  int n;
  cin >> n;
  int lst[n];
  for (int i=0; i<n; i++){
      cin >> lst[i];
  }
  int colors = 1;
  multiset<int> cur;
  cur.insert(lst[0]);
  for (int i=1; i<n; i++){
      //cout << i << endl;
      // get the highest lowest element that's at the front of a stream
      // if there is no stream with elements below, start new one
      multiset<int>::iterator lower = cur.lower_bound(lst[i]);
      if (lower == cur.end()){
          lower--;
      }
      if (lower == cur.begin() && *lower >= lst[i]){
          colors++;
          cur.insert(lst[i]);
          continue;
      }
      bool dont = false;
      while (*lower >= lst[i]){
          lower--;
          if (lower == cur.end() && *lower >= lst[i]){
              dont = true;
              colors++;
              cur.insert(lst[i]);
              break;
          }
      }
      if (!dont){
          cur.erase(lower);
          cur.insert(lst[i]);
      }
      
  }
  cout << colors;
  return 0; 
 
} 
