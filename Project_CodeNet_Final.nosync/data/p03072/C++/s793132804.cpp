#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define all(x) (x).begin(),(x).end()
typedef long long int ll;
using namespace std;
int main()
{
  int n;
  cin >> n;
  int maxval =0;
  int tmp =0;
  int count = 0;
  REP(i,n ){
    cin >> tmp;
    maxval = max(tmp, maxval);
    if(max(tmp, maxval) == tmp){
      count ++;
    }

  }  
  cout << count << endl;

}
