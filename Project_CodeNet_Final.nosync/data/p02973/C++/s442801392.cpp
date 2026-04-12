#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int binary_search(int x){
    int ok = ans.size();
    int ng = - 1;
    while (abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if (ans[mid] < x) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (binary_search(a) == ans.size()) ans.push_back(a);
        else ans[binary_search(a)] = a;
    }
    cout << ans.size() << endl;
}