#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    int h,w;
    cin >> h >> w;
    string str;
    int cnt = 0;
    rep(i,h){
        cin >> str;
        rep(j,w){
            if(str[j] == '#'){
                cnt++;
            }
        }
    }

    if(cnt == h+w-1){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }

    return 0;
}
