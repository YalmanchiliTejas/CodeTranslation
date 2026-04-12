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
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;

int main(){
    int n,a,b,c,x;
    while(cin>>n>>a>>b>>c>>x){
        if(n==0 && a==0 && b==0 && c==0 && x==0)break;
        int num=0;
        vi y;
        rep(i,n){
            int tmp;
            cin>>tmp;
            y.pb(tmp);
        }
        
        int count=0;
        while(1){
            count++;
            if(y[num]==x){
                num++;
                if(num>=n){
                    cout<<count-1<<endl;
                    break;
                }
            }
            x=(a*x+b)%c;
            if(count>=10001){
                cout<<"-1"<<endl;
                break;
            }
        }

    }
    
    return 0;
}