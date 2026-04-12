#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;
class Edge{
public:
    int from,to,value;
    Edge(LL a,LL b,LL c){
        from = a;
        to = b;
        value = c;
    }
    Edge(LL a,LL b){
        from = a;
        to = b;
    }
};

int main(){
    string s;
    string q = "yuiophjklnm";
    while(cin >> s){
        if(s == "#")return 0;
        int ans = 0;
        bool now = !!count(q.begin(),q.end(), s.front());
        for(char c : s){
            if(now != !!count(q.begin(),q.end(),c)){
                now = !!count(q.begin(),q.end(),c);
                ans++;
            }
        }
        cout<<ans<<endl;
    }
}

