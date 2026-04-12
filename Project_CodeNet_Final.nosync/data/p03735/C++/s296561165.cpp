#include<bits/stdc++.h>
#define pb           push_back
#define pii          pair<int,int>
#define vi           vector<int>
#define vii         vector<pair<int,int>>
#define mp           make_pair
#define FOR(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD0(i, n) for (int i = (int)n; i >= 0; i--)
#define FORD1(i, n) for (int i = (int)n; i >= 1; i--)
#define debug(X) { cout << #X << " = " << (X) << endl; }
#define endl '\n'
#define int long long int
using namespace std;
vii data;
int n;
int cnt[(int)2e5 + 5];
int add(int i){
    cnt[data[i].second]++;
    if(cnt[data[i].second] == 1)return 1;
    return 0;
}
int remove(int i){
    cnt[data[i].second]--;
    if(cnt[data[i].second] == 0)return -1;
    return 0;
}
bool check(int len){
    memset(cnt, 0, sizeof cnt);
    int ans = 0;
    int i = 1;
    ans += add(i);
    int j = 1;
    i++;
    if(ans == n)return true;
    while(i < data.size() -1){
        ans += add(i);
        while(data[i].first- data[j].first > len){
            ans += remove(j);
            j++;
        }
        i++;
        if(ans == n)return true;
    }
    return false;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    int x, y;
    FOR(i, n){
        cin >> x >> y;
        if(y < x)swap(x, y);
        data.pb(mp(x, i));
        data.pb(mp(y, i));
    }
    sort(data.rbegin(), data.rend());
    map<int, bool> found;
    int ans = 1e18;
    int start =-1;
    FOR(i, data.size()){
        //debug(data[i].first);
        if(found[data[i].second] && start == -1){
            start = data[i].first;
        } 
        found[data[i].second] = true;
        if(found.size() == n){
            ans =min(ans, (data[0].first - data[i].first)*((start == -1 ? data[i+1].first : start)- data.back().first)); 
            break;
        }
    }
    if(data[0].second == data.back().second){
        cout << ans;
        return 0;
    }
    int len = data[0].first - data.back().first;

//    debug(len);
    reverse(data.begin(), data.end());
    int s= 0, e = 1e9;
    while(s <= e){
        int mid = (s+e)/2;
        if(check(mid)){
            e= mid-1;
            ans = min(ans, len*mid);
        }else s= mid+1;
    }
    cout << ans;

}


