#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define loop(i,a,b) for(int i=(a); i<int(b); i++)
#define rep(i,b) loop(i,0,b)

int main(){
    int n;
    while(cin >> n && n){
        vector<pair<int,int>> v;
        v.reserve(n/2);
        rep(i,n){
            int g; cin >> g;
            int cnt = 0;
            if(i&1){
                while(v.size() && v.back().first!=g){
                    cnt+=v.back().second;
                    v.pop_back();
                }
                if(v.size()==0) v.push_back(make_pair(g,0));
                v.back().second++;
                v.back().second += cnt;
            } else {
                if(v.size() && v.back().second==g){
                    cnt+=v.back().second;
                    v.pop_back();
                }
                v.push_back(make_pair(g,cnt+1));
            }
        }
        int ans = 0;
        rep(i,v.size())if(v[i].first==0){
                ans+=v[i].second;
        }
        cout << ans << endl;
    }
}