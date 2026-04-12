#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m = a[0];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= m){
            cnt++;
            m = a[i];
        }
    }
    cout << cnt;
}