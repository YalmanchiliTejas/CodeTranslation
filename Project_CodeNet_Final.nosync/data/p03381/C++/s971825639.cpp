#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

int main() {
    int n;
    cin >> n;
    pair<int, int> sorta[200001];
    for(int i = 0; i < n; i++){
    	int a;
    	cin >> a;
    	sorta[i] = make_pair(a, i);
    }
    sort(sorta, sorta + n);
    int ans[200001];
    for(int i = 0; i < n; i++){
    	if(i < n / 2) ans[sorta[i].second] = sorta[(n - 1) / 2 + 1].first;
    	else ans[sorta[i].second] = sorta[(n - 1) / 2].first;
    }
    for(int i = 0; i < n; i++){
    	cout << ans[i];
    	if(i == n - 1) cout << endl;
    	else cout << " ";
    }
    return 0;
}