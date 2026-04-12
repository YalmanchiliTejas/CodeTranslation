#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define ROF(i,b,a) for (int i=(b);i>(a);--i)
#define REP(i,n) FOR(i,0,n)
#define PER(i,n) ROF(i,n-1,-1)

typedef int i32;
typedef long long int i64;
typedef unsigned long long int ui64;
typedef float f32;
typedef double f64;
typedef long double f128;


int main(){
    int N, M;
    cin >> N >> M;
    int a[M],b[M];
    REP(i,M){
        cin >> a[i] >> b[i];
    }
    vector<int> v(N);
    int perm_num = 1;
    REP(i,N){
        v[i] = i+1;
        perm_num *= i+1;
    }
    bool flag;
    int cnt = 0;
    REP(i,perm_num){
        if(v[0]!=1) continue;
        REP(j,N-1){
            flag = true;
            REP(k,M){
                if(v[j]==a[k] && v[j+1]==b[k] || v[j]==b[k] && v[j+1]==a[k]){
                    flag = true;
                    break;
                }else{
                    flag = false;
                }
            }
            if(!flag) break;
        }
        if(flag) cnt++;
        next_permutation(v.begin(),v.end());
    }
    cout << cnt;
}



