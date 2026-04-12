#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)

int main(){
    int N;
    cin >> N;
    multiset<long long> s;
    long long a;
    rep(i, N){
        cin >> a;
        s.insert(a);
        set<long long>::iterator ite;;
        ite = s.find(a);
        while(ite != s.begin()){
            ite--;
            if(*ite < a){
                s.erase(ite);
                break;
            }
        }
    }
    cout << s.size() << endl;
}
