#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define MP make_pair
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define REP2(i,d,n) for(int i=(d);i<(n);i++)
#define RREP(i,n) for(int i=(n);i>=0;i--)
#define CLR(a) memset((a),0,sizeof(a))
#define MCLR(a) memset((a),-1,sizeof(a))
#define RANGE(x,y,maxX,maxY) (0 <= (x) && 0 <= (y) && (x) < (maxX) && (y) < (maxY))

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI > VVI;
typedef vector<string> VS;
typedef vector<LL> VLL;
typedef pair<int,int> PII;

const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;

const int DX[]={1,0,-1,0},DY[]={0,-1,0,1};

int main(){
    int n,a;
    cin >> n;
    VI result(n, 0);

    REP(i, n){
        cin >> a;
        if(n % 2 == 0){
            if(i % 2 == 0){
                result[n/2 + i/2] = a;
            }else{
                result[n/2 - (i+1)/2] = a;
            }
        }else{
            if(i % 2 == 0){
                result[n/2 - i/2] = a;
            }else{
                result[n/2 + (i+1)/2] = a;
            }
        }
    }

    REP(i, n){
        cout << result[i] << (i+1==n ? "\n" : " ");
    }
}
