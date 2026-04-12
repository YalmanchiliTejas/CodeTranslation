#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    multiset<int> ms;
    rep(i,N){
        multiset<int>::iterator itr = ms.upper_bound(vec[i] * -1);
        if (itr == ms.end()){
            ms.insert(vec[i] * -1);
        }
        else{
            ms.erase(itr);
            ms.insert(vec[i] * -1);
        }
    }
    int ans = 0;
    for (multiset<int>::iterator itr = ms.begin(); itr != ms.end(); itr++){
        ans++;
    }
    cout << ans << endl;
}