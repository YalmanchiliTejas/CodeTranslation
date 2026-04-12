#include <bits/stdc++.h>
#define All(v) v.begin(), v.end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;

const int MAX_N = (int)1e5 + 5;
multiset<int> S;

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        auto itr = S.lower_bound(a);
        if(itr==S.begin()){
            S.emplace(a);
        } else {
            itr--;
            S.erase(itr);
            S.emplace(a);
        }
    }
    cout<<S.size()<<endl;
    return 0;
}