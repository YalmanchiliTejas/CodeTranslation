#include <bits/stdc++.h>

using namespace std;


int main(){
    int N;cin >> N;
    vector<int> vec;
    for(int a = 0;a < N;a++){
        int b;cin >> b;
        vec.push_back(b);
    }
    int ma = 0;
    int ans = 0;
    for(int a = 0;a < N;a++){
        if(ma  <= vec.at(a)){
            ans++;
        }
        ma = max(ma,vec.at(a));
    }
    cout<<ans<<endl;
}
