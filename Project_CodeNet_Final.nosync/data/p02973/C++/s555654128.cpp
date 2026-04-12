
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
    int N;cin >> N;
    vector<int> vec;
    for(int i = 0;i < N;i++){
        int b;cin >> b;
        vec.push_back(-b);
    }
    multiset<int> se;
    se.insert(vec.front());
    for(int i = 1;i < N;i++){
        auto itr = se.upper_bound(vec.at(i));
        if(itr == se.end()){
            se.insert(vec.at(i));
        }else{
            se.erase(itr);
            se.insert(vec.at(i));
        }
    }
    /*
    for(auto a: se){
        cout<<a<<" ";
    }
    */

   // cout<<endl;
    cout<<se.size()<<endl;

}
