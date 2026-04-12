#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
typedef long long int ll;

#define PI (acos(-1))
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define dumparr(x) cerr << #x ; for(auto elem: x){cerr << " " << elem;} cerr << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

int main(void){
    int n; cin >> n;
    vector <int> as;
    vector <bool> painted;
    int a;
    REP(i, n){
        cin >> a;
        as.push_back(a);
        painted.push_back(false);
    };
    map <int, int> curs = {{as[0], 1}};
    for(int i=1; i<n; i++){
        int min_val = (*curs.begin()).first;
        int max_val = (*curs.rbegin()).first;

        if (as[i] > min_val){
            auto it = curs.lower_bound(as[i]);
            it--;
            int d = it->first;
            if (curs[d] == 1){
                curs.erase(d);
            } else {
                curs[d]--;
            }
            curs[as[i]]++;
        } else {
            curs[as[i]]++;
        }
    }
    int ans = 0;
    for (auto c: curs){
        ans += c.second;
    }
    cout << ans << endl;
    return 0;
}