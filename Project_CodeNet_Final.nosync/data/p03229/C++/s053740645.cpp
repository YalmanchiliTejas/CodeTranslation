#include<bits/stdc++.h>

#define int long long int
#define mp make_pair
using namespace std;

int32_t main() {
    int n;
    scanf("%lld", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    int f = 0, b = n - 1;
    int x = 0;
    int index = (n + 1)/2;
    index--;
    vector<int> ans,ans1;
    ans.push_back(v[index]);
    ans1.push_back(v[index]);
    int n1 = n , n2 = n;
    n1--,n2--;
    while(n1){
        if(x%2 == 0) {
            ans.push_back(v[b]);
            b--;
        }
        else{
            ans.push_back(v[f]);
            f++;
        }
        x++;
        n1--;
    }
    x = 0;
    f = 0,b = n-1;
    while(n2){
        if(x%2 == 0) {
            ans1.push_back(v[f]);
            f++;
        }
        else{
            ans1.push_back(v[b]);
            b--;
        }
        x++;
        n2--;
    }
    int ans2 = 0;
    /*for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }*/
    for (int i = 1; i < ans.size(); ++i) {
        ans2 += abs(ans[i] - ans[i-1]);
    }
    int ans3 = 0;
    for (int i = 1; i < ans1.size(); ++i) {
        ans3 += abs(ans1[i] - ans1[i-1]);
    }
    ans2 = max(ans2 , ans3);
    printf("%lld",ans2);
}