#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n, l, r;
    while(cin >> n >> l >> r, n != 0){
        vector<int> v;
        for(int i=0;i<n;++i){
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        int ans = 0;
        for(int i=l;i<=r;++i){
            bool is_leap = false, exist = false;
            for(int j=0;j<v.size();++j){
                if(i%v[j] != 0)continue;
                if((j+1)%2 != 0)is_leap = true;
                else is_leap = false;
                exist = true;
                break;
            }
            if(!exist){
                if(n%2)is_leap = false;
                else is_leap = true;
            }
            if(is_leap)ans++;
        }
        cout << ans << endl;
    }

    return 0;
}

