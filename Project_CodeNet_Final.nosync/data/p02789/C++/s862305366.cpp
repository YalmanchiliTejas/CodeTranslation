/**************************
*                         *
*  Nothing Is Impossible  *
*                         *
**************************/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <cmath>
#include <map>
#define GetRand(Min, Max) ((rand()%(int)(((Max) + 1)-(Min))) + (Min))
#define Rep(i, min, max) for (int i = min; i < max; ++i)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
   ios::sync_with_stdio(NULL);
   cin.tie(NULL); cout.tie(NULL);
   int a,b; cin >> a >> b;
   if (a == b){
      cout << "Yes" << endl;
   }
   else{
      cout << "No" << endl;
   }
   return 0;
}