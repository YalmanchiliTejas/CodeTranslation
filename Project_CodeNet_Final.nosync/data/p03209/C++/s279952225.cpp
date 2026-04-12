#include <iostream>
//#include <iomanip>
//#include <algorithm>
//#include <numeric>
//#include <queue>
//#include <stack>
//#include <math.h>
#include <vector>
//#include <unordered_map>
//#include <string>
typedef long long LL;
//typedef long double LD;
using namespace std;
vector<LL> p;
vector<LL> burger;

LL eat_burger(int n_in, LL x_in){
    if(n_in==0){
        if(x_in<=0){
            return 0;
        }else{
            return 1;
        }
    }else if(x_in<=burger[n_in-1]+1){
        //cout << "test1 " << x_in << " " << burger[n_in-1]+1 << endl;
        return eat_burger(n_in-1, x_in-1);
    }else{
        //cout << "test2 " << x_in << " " << burger[n_in-1]+1 << " " << x_in-2-burger[n_in-1] << endl;
        return p[n_in-1] + 1 + eat_burger(n_in-1, x_in-2-burger[n_in-1]);
    }
}

int main() {
    int n;
    LL x;
    LL tmp_p;
    LL tmp_burger;
    LL ans;
    cin >> n >> x;

    p.push_back(1);
    burger.push_back(1);
    for(int i=0; i<n; i++){
        tmp_p = p[i]*2 + 1;
        tmp_burger = burger[i]*2 + 3;
        p.push_back(tmp_p);
        burger.push_back(tmp_burger);
    }

    ans = eat_burger(n, x);
    cout << ans << endl;
}