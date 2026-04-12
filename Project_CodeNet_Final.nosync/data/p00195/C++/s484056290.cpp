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
    while(1){
        int maxiNum=999999,maxi=-1;
        rep(i,5){
            int a,b;
            cin>>a>>b;
            if(i==0 && a==0 && b==0)goto end;
            
            if(a+b>maxi){
                maxiNum=i;
                maxi=a+b;
            }
            
        }
        char num[]={'A','B','C','D','E'};
        cout<<num[maxiNum]<<" "<<maxi<<endl;
    }
end:;

    return 0;
}