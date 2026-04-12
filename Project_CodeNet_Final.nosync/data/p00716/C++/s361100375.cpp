#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <stdio.h>
#include <bitset>
#include <complex>
#include <math.h>
#include <iomanip>
using namespace std;
//using ll = long long;
#define MM 1000000000
#define MOD MM+7
#define pi pair<int32,int32>
#define pl pair<int64,int64>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
int main(){
    vector<int> ans(0);
    double m,n,y; cin >> m;
    for (int i = 0; i < m; i++){
        int res = 0;
        int sum;
        cin >> sum >> y >> n;
        int check;
        double per,giv;
        for(int j = 0; j < n; j++){
            cin >> check >> per >> giv;
            int tmp = 0,sum2 = sum;
            if (check == 0){
                for (int k = 0; k < y; k++){
                    tmp += sum2*per;
                    sum2 -= giv;
                }
                tmp += sum2;
            } else {
                for (int k = 0; k < y; k++){
                    sum2 *= (1.0+per);
                    sum2 -= giv;
                }
                tmp = sum2;
            }
            res = max(res,tmp);
        }
        ans.push_back(floor(res));
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}
  


