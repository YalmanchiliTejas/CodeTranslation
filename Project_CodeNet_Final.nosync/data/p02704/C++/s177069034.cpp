#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef unsigned long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

void ok(){
    cout << "Yes" << endl;
    exit(0);
}

void ng(){
    cout <<  "-1" << endl;
    exit(0);
}

Int n;
Int s[550], t[550];
Int u_all[550], v_all[550];

vector<vector<Int>> solve(int k){
    vector<Int> u(n), v(n);
    for(int i = 0;i < n;i++){
        u[i] = (u_all[i] >> k) % 2;
        v[i] = (v_all[i] >> k) % 2;
    }

    vector<vector<Int>> ans(n, vector<Int>(n,2));
    Int free_c = n, free_r = n;

    for(int i = 0;i < n;i++){
        if(s[i] != u[i]){
            free_r--;
            for(int j = 0;j < n;j++)
                ans[i][j] = u[i];
        }
    }

    for(int i = 0;i < n;i++){
        if(t[i] != v[i]){
            free_c--;
            for(int j = 0;j < n;j++){
                if(ans[j][i] != 2 && ans[j][i] != v[i])ng();
                ans[j][i] = v[i];
            }
        }
    }

    if(free_r == 1){
        for(int i = 0;i < n;i++){
            if(t[i] == v[i]){
                Int cnt = 0;
                for(int j = 0;j < n;j++){
                    if(ans[j][i] != 2 && ans[j][i] == v[i])cnt++;
                }
                if(cnt == 0){
                    for(int j = 0;j < n;j++){
                        if(ans[j][i] == 2){
                            ans[j][i] = v[i];
                        }
                    }   
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(s[i] == u[i]){
                for(int j = 0;j < n;j++){
                    if(ans[i][j] == 2){
                        ans[i][j] = u[i];
                    }
                }
            }
        }
    }
    else if(free_c == 1){
        for(int i = 0;i < n;i++){
            if(s[i] == u[i]){
                Int cnt = 0;
                for(int j = 0;j < n;j++){
                    if(ans[i][j] != 2 && ans[i][j] == u[i])cnt++;
                }
                if(cnt == 0){
                    for(int j = 0;j < n;j++){
                        if(ans[i][j] == 2){
                            ans[i][j] = u[i];
                        }
                    }   
                }
            }
        }
        for(int i = 0;i < n;i++){
            if(t[i] == v[i]){
                for(int j = 0;j < n;j++){
                    if(ans[j][i] == 2){
                        ans[j][i] = v[i];
                    }
                }
            }
        }
    }
    else{
        Int start = 0;
        for(int i = 0;i < n;i++){
            Int num = start;
            bool done = false;
            for(int j = 0;j < n;j++){
                if(ans[i][j] != 2)continue;
                ans[i][j] = num;
                num ^= 1;
                done = true;
            }
            if(done)
                start ^= 1;
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> s[i];
    for(int i = 0;i < n;i++)cin >> t[i];
    for(int i = 0;i < n;i++)cin >> u_all[i];
    for(int i = 0;i < n;i++)cin >> v_all[i];

    vector<vector<Int>> ans(n, vector<Int>(n,0));

    for(int k = 0;k < 64;k++){
        auto tmp_ans = solve(k);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ans[i][j] += tmp_ans[i][j] << k;
            }                    
        }
    }

    for(int i = 0;i < n;i++){
        Int tmp = ans[i][0];
        for(int j = 0;j < n;j++){
            if(s[i] == 0)tmp &= ans[i][j];
            else tmp |= ans[i][j];
        }
        if(tmp != u_all[i])ng();
    }

    for(int i = 0;i < n;i++){
        Int tmp = ans[0][i];
        for(int j = 0;j < n;j++){
            if(t[i] == 0)tmp &= ans[j][i];
            else tmp |= ans[j][i];
        }
        if(tmp != v_all[i])ng();
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
    
    
    return 0;
}