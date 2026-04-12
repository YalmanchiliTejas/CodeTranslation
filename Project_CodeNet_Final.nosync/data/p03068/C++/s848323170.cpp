#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define pb push_back
#define sz(i) (int)(i.size())
#define F first
#define S second
#define L long double
#define P pair<int, int>
const int inf = 0x3f3f3f3f3f3f3f3LL;
const int mod = (int)1e9 + 7;
using namespace std;
#if LOCAL
#include "../../tr.h"
#else
#define tr(...)
#define endl '\n'
#endif
template<class T> void smin(T& a, T val) {if (a > val) a = val;}template<class T> void smax(T& a, T val) {if (a < val) a = val;}
const int N = 5*(int)1e5 + 10;

int n, a[N];

int k;
string s;

int32_t main(){_

   cin>>n;
   cin>>s>>k;

   --k;

   for (int i = 0; i < n; ++i)
   {
      if(s[i] != s[k])s[i] = '*';
   }

   cout<<s;
   

   return 0;
}

// Common sense: do smth instead of nothing
// Even a single second counts...
// If other's can do it, even I can do it. It wouldn't be that tough. Let me give it a try.
// Mistakes made in past
// -Ques. ask for max-min => think binary_search, DP, greedy
// -not reading question properly / skipping to read & understand all samples properly & wasting time in wrong direction.
// -Using wrong indexing in nested loops something like a[i], when it is supposed to be a[j](WA)
// -value of const int N is not correct (WA/RTE).
// -Did you memset dp to -1 ?
// -check for small edges cases and work on small test cases manually if WA
// -not deallocating memory to pointers can lead to MLE. Use delete :))
// -not reading problem statements of harder problems E,..., thinking it couldn't be solved, but it isn't the case.
// -Avoid using #define int long long as much as possible when it's dp problem and requires high memory say, O(N^2, N=5000) (MLE)
// -Check Bitwise Operator Precedence 
// -Use pragmas to optimize (by constant factor) when necessary..
// -Think before coding & starting to debug. Have patience to look inside code and actually see how it works