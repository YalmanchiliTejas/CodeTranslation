#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> P;
int main(void){
    int n, ans = 0;
    set<P> s;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        a *= -1;
        auto itr = s.upper_bound(P(a, n));
        if(itr == s.end()){
            s.insert(P(a, ans++));
        }else{
            int c = itr->second;
            s.erase(itr);
            s.insert(P(a, c));
        }
    }
    cout << ans << endl;
}
