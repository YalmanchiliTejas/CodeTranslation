#include <bits/stdc++.h>

using namespace std;
int n, ans[200001];
pair < int, int > a[200001];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    int mid = n / 2;
    for(int i = 1; i <= n; i++){
        if(mid >= i){
            ans[a[i].second] = a[mid + 1].first;
        }
        else{
            ans[a[i].second] = a[mid].first;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }
}
