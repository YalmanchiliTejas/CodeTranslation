#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main (){
    FastIO
    string s;
    cin >> s;
    lld n, i;
    n = s.length();
    lld f = 0;
    for(i = 1; i < n; i+=1){
    	if (s[i] != s[i-1]){
    		f = 1;
    		break;
    	}
    }
    if (f == 1)
    	cout << "Yes\n";
    else
    	cout <<  "No\n";
    return 0;
}