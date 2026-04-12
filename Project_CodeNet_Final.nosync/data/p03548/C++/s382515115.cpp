#include<bits/stdc++.h>
#define int long long
#define loop(i, a, b) for(int i = a; i < b; i++)
#define rep(i, a) loop(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int MOD = 1e9 + 7, INF = 1e9;
using vi = vector <int>;
using vvi = vector <vi>;
//g++ -std==c++14
 
signed main(){
    int x, y, z;
    cin >> x >> y >> z;

    x -= z * 2;
    int cnt = 0;
    while(1){
        x -= y;
        cnt ++;
        if(x >= z){
            x -= z;
            if(x >= y);
            else
                break;
        }
        else
            break;
    }
    cout << cnt << endl;    
}