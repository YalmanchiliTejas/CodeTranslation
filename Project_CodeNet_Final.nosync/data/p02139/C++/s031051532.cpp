#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    ll n,q;
    cin >> n >> q;
    ll x = 0;
    for(int i=0;i<q;i++){
        ll a,b;
        cin >> a >> b;
        if(a==1){
            x += b;
            x %= n; 
        }else{
            cout << (x+b-1)%n+1 << endl;
        }
        //cout << x << endl;
    }


    return 0;
}
