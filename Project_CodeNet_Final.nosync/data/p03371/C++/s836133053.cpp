#include<iostream>

typedef long long ll;
using namespace std;

int main()
{ll A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;

 ll min_sum = 1e10;
 for(ll m = 0; m <= 100000; m++)
 { ll sum = max((X-m),(ll)0)*A + max((Y-m),(ll)0)*B + 2*m*C;
  min_sum = min(min_sum, sum);}
 
 cout << min_sum << endl;
 
 return 0;
}