#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int a[22];

int main(){
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 0; i < n; ++i){
        bool flag = true;
        for(int j = 0; j < i;++j){
            if(a[j] > a[i]){flag = false; break;}
        }
        if(flag)res++;
    }
    cout << res << '\n';
    return 0;
}
