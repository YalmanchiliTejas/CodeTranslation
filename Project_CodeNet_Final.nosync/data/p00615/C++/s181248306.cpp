#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <sstream>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

#define dump(x)  cerr << #x << " = " << (x) << endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back

int main() {
    int n,m;
    while(cin>>n>>m){
        if(n==0 && m==0)break;
        
        vi in;
        rep(i,n){
            int a;
            cin>>a;
            in.pb(a);
        }
        rep(i,m){
            int a;
            cin>>a;
            in.pb(a);
        }
        in.pb(0);
        
        sort(all(in));
        
        int maxi=-1;
        rep(i,in.size()-1){
            maxi=max(maxi,in[i+1]-in[i]);
        }
        
        cout<<maxi<<endl;
        
    }

    return 0;
}