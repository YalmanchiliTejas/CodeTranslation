#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,ans=0;
    cin >> n;
    map<int,int> mp;
    for(int i = 0;i < n;i ++){
        int a;
        cin >> a;
        a ++;
        if(mp.size()==0 || a<=mp.begin()->first) mp[a] ++;
        else{
            auto ite = mp.lower_bound(a);
            if(ite==mp.end()){
                mp.rbegin()->second --;
                if(mp.rbegin()->second==0) mp.erase(mp.rbegin()->first);
                mp[a] ++;
            }else{
                ite --;
                ite->second --;
                if(ite->second==0) mp.erase(ite->first);
                mp[a] ++;
            }
        }
    }
    for(auto ite = mp.begin();ite != mp.end();++ite){
        ans += ite->second;
    }
    cout << ans << endl;
    return 0;
}