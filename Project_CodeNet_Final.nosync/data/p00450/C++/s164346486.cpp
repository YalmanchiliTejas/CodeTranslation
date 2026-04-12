#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int a[100005];
bool stone[100005];
int main()
{
//	cut here before submit 
//	freopen ("testcase.SGS", "r", stdin );
	int n;
	while (scanf ("%d", &n ), n ){
		memset (a, 0, sizeof (a ) );
		memset (stone, false, sizeof (stone ) );
		for (int i = 1; i <= n; i++ ){
			int in;
			scanf ("%d", &in );
			stone[i] = (in == 1 ? true : false );
		} // end rep
		int right = 0;
		a[right] = 1;
		bool left = stone[1];		// 左端の色
		bool prev = stone[1];		// 直前に置いた石の色
		for (int i = 2; i <= n; i++ ){
 			if (prev == stone[i] ){
				// 連続した色の碁石の数を１つ増やす
				a[right]++;
			}else
			if (i % 2 == 0 ){		// 偶数番目に碁石を置く場合
				if (right == 0 ){
					// テーブルに置いてある碁石は一色であり
					// 新たに置く碁石の色は異なるので、
					// 現在のテーブルに置いてある碁石を、
					// 新たに置く碁石と同じ色の碁石に、全て置き換える
					a[right]++;
					left = stone[i];
				}else{
					// 直前の連続した色の碁石を、
					// 新たに置く碁石の色と同じ色に置き換える
					a[right-1] += a[right] + 1;
					right--;
				} // end if
			}else{
				// 直前に置いた碁石とは異なった色の碁石を新たに置く
				right++;
				a[right] = 1;
			} // end if
			// 直前に置いた碁石の色 = 新たに置く碁石の色
			prev = stone[i];
		} // end for

		int res = 0;
		rep (i, right+1 ){
			// 右端が白のとき、偶数番目が白
			if (!left && (i % 2 == 0 ) ){
				res += a[i];
			}else // 右端が黒のとき、奇数番目が白	
			if (left && (i % 2 != 0 ) ){
				res += a[i];
			} // end if
		} // end rep
		printf ("%d\n", res );

	} // end loop
		
	return 0;
}