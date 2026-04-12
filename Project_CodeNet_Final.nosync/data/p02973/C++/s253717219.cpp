#include <bits/stdc++.h>
#define rep0(i, n) for(int i=0; i<(int)(n);i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep0(i, n) cin >> a[i];
    multiset<int> colmin; //別々の色ごとで最後に塗られた数
    colmin.insert(a[n-1]);
    for(int i = n - 2 ; i >= 0 ; i --){
        auto it = colmin.upper_bound(a[i]);
        if(it != colmin.end())colmin.erase(it);//既存の色で塗れる場合は既存を削除して
        colmin.insert(a[i]); //追加
    }
    cout << colmin.size() << endl;
    return 0;
}