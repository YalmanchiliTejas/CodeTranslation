#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <cctype>

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <algorithm>


using namespace std;

#define Max INT_MAX
#define Inf (INT_MAX/2)
#define Min INT_MIN


#define rep(i, n) for(int i = 0; i < n; i++)
#define repi(i,l,n) for(int (i)=(int)(l);(i)<(int)(n);(i)++)
// s <= x < g ?
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
// 0 <= x < w && 0 <= y < h ?
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))

typedef pair<int, int> P;

int main()
{
    int n;
    while( cin >> n ){
        vector<int> vec;
        if( n == 0) {break;}
        rep(i,n){
            int tmp;
            cin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        double sum = 0.0;
        for( int i = 1; i<vec.size() - 1; i++ ){
            //cout << "add" << i << endl;
            sum += double(vec[i]);
        }
        cout << floor(sum/double(vec.size()-2) ) << endl;
    }
    return 0;
}