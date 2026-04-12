#include <bits/stdc++.h>
#include <fstream>
#define inputtxt() std::ifstream in("input.txt"); std::cin.rdbuf(in.rdbuf())
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define foreach(e, v) for (auto e : v)
#define all(obj) (obj).begin(), (obj).end()
#define rall(obj) (obj).rbegin(), (obj).rend()
#define collect(arr, size) rep(i,size) cin >> arr[i];

int main(){
    int n; cin >> n;
    vector<int> height(n);
    collect(height, n);
    int m = 0, viewable = 0;
    rep(i,n){
        if(m<=height[i]){
            viewable++;
        }
        m = max(m,height[i]);
    }
    cout << viewable << endl;
}