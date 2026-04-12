#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(),a.end(), compare);

    set<int> color;// (color, end-of-line)
    color.insert(a[0].second);
    for(int i=1; i<n; i++){
        auto itr = color.lower_bound(a[i].second);
        if(itr != color.begin()){
            color.erase(*prev(itr));
        }
        color.insert(a[i].second);
    }
    cout << color.size() << endl;
    return 0;
}