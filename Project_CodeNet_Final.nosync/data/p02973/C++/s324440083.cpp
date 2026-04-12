#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    int N; cin >> N;
    multiset<int> a;
    for(int i=0;i<N;i++){
      	a.insert(1);
        int p;
        cin >> p;
        auto ite=a.upper_bound(-p);
        a.erase(ite);
        a.insert(-p);
    }
  	a.erase(1);
    cout << a.size();
}

/*

僕が悪かったです。

 */




