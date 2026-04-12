#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;
ll dp1[110][5];
ll dp2[110][5];

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    dp1[0][0]=1;   
    int n=s.length();
    for(int i=0;i<n;i++){
        int now=s[i]-'0';
        //cout<<now<<endl;
        if(now==0){
            for(int j=0;j<=3;j++){
                dp1[i+1][j]+=dp1[i][j];
                dp2[i+1][j]+=dp2[i][j];
                dp2[i+1][j+1]+=dp2[i][j]*9;
            }
        }else{
            for(int j=0;j<=3;j++){
                dp1[i+1][j+1]+=dp1[i][j];
                dp2[i+1][j]+=dp1[i][j];
                dp2[i+1][j+1]+=dp1[i][j]*(now-1);
                dp2[i+1][j]+=dp2[i][j];
                dp2[i+1][j+1]+=dp2[i][j]*9;
            }
        }
    }
    cout<<dp1[n][k]+dp2[n][k]<<endl;
}