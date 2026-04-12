#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#include <iomanip>
#include <utility>

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n) for(int i=1;i<=(n);i++)
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,h[25];
    cin>>n;

    int maxh=0,sum=0;
    rep(i,n){
	cin>>h[i];

	if(maxh<=h[i]){
	    sum++;
	    maxh=h[i];
	}
    }
    cout<<sum<<'\n';
    return 0;
}
