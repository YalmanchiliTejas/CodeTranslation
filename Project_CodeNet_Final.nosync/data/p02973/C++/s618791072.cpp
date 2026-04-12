#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+1;

int n;
int a[N];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = n-1; i >= 0; --i){
        int p = upper_bound(v.begin(), v.end(), a[i])-v.begin();
        if(p == v.size())
            v.push_back(a[i]);
        else v[p] = a[i];
    }
    cout << v.size() << '\n';
}
