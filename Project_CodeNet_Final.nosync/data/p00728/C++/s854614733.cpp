#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DEBUG(x) cerr <<#x<<":"<<x<<endl;
#define DEBUG2(x, y) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<endl;
#define DEBUG3(x, y, z) cerr <<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl;
#define DEBUGVC(x) cerr <<#x<<": "; for(auto a:x) cerr << a <<" "; cerr << endl;
#define DEBUGMP(x) cerr <<#x<<":"<<endl; for(auto a:x) cerr << a.first <<" "<< a.second << endl;
#define MAX_N (1000006)
#define INF (1LL << 60)
const int MOD = (int)1e9+7;


signed main(){
    while (true) {
        int n;
        cin >> n;
        if (n==0) { break; }
        vector<int> v;
        for(int i=0; i<n; i++) {
            int p;
            cin >> p;
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        int sum = 0;
        for(int i=1; i<n-1; i++) {
            sum += v[i];
        }
        cout << sum/(n-2) << endl;
    }
}
