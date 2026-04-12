#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <list>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, nums[100009];
    cin>>N;
    rep(i,N) cin>>nums[i];
    
    sort(nums,nums+N);
    
    int fr=nums[0], bk=nums[N-1], idf=1, idb=N-2;
    ll sum = bk-fr;
    while(idf<=idb){
        ll mxf = max(abs(fr-nums[idf]), abs(bk-nums[idf]));
        ll mxb = max(abs(fr-nums[idb]), abs(bk-nums[idb]));
        ll idx;
        if(mxf>mxb){
            idx=idf;
            idf++;
        }else{
            idx=idb;
            idb--;
        }
        
        ll fv = abs(fr-nums[idx]);
        ll bv = abs(bk-nums[idx]);
        sum += max(fv,bv);
        if(fv>bv){
            fr=nums[idx];
        }else{
            bk=nums[idx];
        }
    }
    cout1(sum)
}
