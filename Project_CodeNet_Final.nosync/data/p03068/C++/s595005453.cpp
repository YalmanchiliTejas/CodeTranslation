#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, k;
    string a;
    char b;

    cin >> n >> a >> k;

    b = a[k - 1];

    for(char i : a){
        if(i == b){
            cout << i;
        } else {
            cout << '*';
        }
    }

    return 0;
}
