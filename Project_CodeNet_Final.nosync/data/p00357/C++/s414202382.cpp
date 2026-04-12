#include <bits/stdc++.h>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main(){
    int n;
    cin >> n;
    vector<int> hoge;
    REP(i,n){
        int a;
        cin >> a;
        hoge.push_back(a);
    }
    REP(tere,2){
        int now = 1;
        for(int i = 0;i < n;++i){
            if(i >= now){
                cout << "no" << endl;
                return 0;
            }
            now = max(now,1 + i + hoge[i]/10);
        }
        reverse(hoge.begin(),hoge.end());
    }
    cout << "yes" << endl;
    return 0;
}
