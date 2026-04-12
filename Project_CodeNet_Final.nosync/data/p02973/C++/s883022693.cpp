#include<iostream>
#include<vector>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    vector<int> color;
    color.push_back(a[0]);
    for(int i = 1; i < n; i++){
        int l = 0, r = color.size() - 1;
        if (color[r] < a[i]) {
            while(l < r){
                int idx = (r + l) / 2;
                if (color[idx] >= a[i]) {
                    l = idx + 1;
                }else{
                    r = idx;
                }
            }
            color[l] = a[i];
        }else{
            color.push_back(a[i]);
        }
    }
    cout << color.size() << endl;
}