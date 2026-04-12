#include<bits/stdc++.h>
const int N = 205;
using namespace std;

vector <int> mv;
int n, a[N];

void change(int k){
    mv.push_back(k);
    for (int i = k; i < n; i++) swap(a[i], a[i-k]);
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j < n; j++){
            change(1);
            if (a[0] < a[n-1]) change(n-1);
        }
        change(1);
    }
    cout << (int)mv.size() << "\n";
    for (auto x : mv) cout << x << "\n";
}
