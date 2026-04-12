#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<functional>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

#define INF 1000000007
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define CLR(a) memset((a), 0, sizeof(a))

using ll = long long;
using namespace std;

inline int toInt(string s){
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}

template<class T> inline string toString(T x){
    ostringstream sout;
    sout << x;
    return sout.str();
}

int main(void){

    int h, w;
    cin >> h >> w;

    int ans = 0;
    FOR(i,0,h){
        FOR(j,0,w){
            char c;
            cin >> c;
            if(c=='#')ans++;
        }
    }

    if(ans!=(h+w-1))cout << "Impossible" << endl;
    else cout << "Possible" << endl;

    return 0;
}
