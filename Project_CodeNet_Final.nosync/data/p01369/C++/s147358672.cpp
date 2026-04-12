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
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
#define sz size()

const double EPS = 1e-10;
const int INF = 100000000;

int is(char c){
    char keys[]={'q','w','e','r','t','a','s','d','f','g','z','x','c','v','b'};
    rep(i,15){
        if(c==keys[i])return 0;
    }
    return 1;
    
}


int main(){
    string s;
    while(cin>>s){
        if(s=="#")break;
        int c=0;
        int now=-1;
        rep(i,s.sz){
            if(now==-1){
                now=is(s[i]);
            }
            else{
                if(now!=is(s[i]))c++;
                now=is(s[i]);
            }
        }
        cout<<c<<endl;
        
    }
    
    
    return 0;
}