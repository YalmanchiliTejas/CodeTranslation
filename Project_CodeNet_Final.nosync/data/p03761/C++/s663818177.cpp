#include <iostream>
#include <cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define reprev(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define MAX 100100
#define MAX_N 200100
#define SENTINEL 2000000000
#define NIL -1
const int MOD = 1e9+7;
const int INF = 1 << 29;

int main(){
    int n;cin>>n;
    string s[n];
    rep(i,n){
        cin>>s[i];
        }
    int num[n][27];
    memset(num,0,sizeof(num));
    rep(i,n){
        rep(j,26){
            rep(k,s[i].length()){
                if(s[i][k]-'a'==j){
                    num[i][j]++;
                }
            }
        }
    }
    int mins[27];
    rep(i,27)mins[i]=INF;
    rep(i,27){
        rep(j,n){
            if(mins[i]>num[j][i])mins[i]=num[j][i];
        }
    }
    rep(i,26){
        rep(j,mins[i]){
            char s=i+'a';
            cout<<s;
        }
    }
    cout<<endl;
    return 0;
}