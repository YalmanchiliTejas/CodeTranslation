#include <bits/stdc++.h>
const int INF = 1e9;
const int MODk = 1e9+7;
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
    int n;
    while(cin >> n){
        if(n == 0){
            return 0;
        }
        vector<int> s;;
        for(int a = 0;a < n;a++){
            int b;cin >> b;
            s.push_back(b);
        }
        sort(s.begin(),s.end());
        cout<<(accumulate(s.begin(),s.end(),0LL)-*max_element(s.begin(),s.end())-*min_element(s.begin(),s.end()))/(max(n-2,0))<<endl;;
    }
}

