#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    int t = n / 2 - 1;
    for(int i = 0; i < n; i++){
        if(a[i] <= b[t]){
            cout << b[t + 1] << endl;
        }else{
            cout << b[t] << endl;
        }
    }
    return 0;
}