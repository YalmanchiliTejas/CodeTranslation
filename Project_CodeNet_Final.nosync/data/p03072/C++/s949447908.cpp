#include <bits/stdc++.h>

// # DEFINES # //
#define ll long long
#define M (ll)1e9+7
#define EPS 1e-9

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    ll count = 0;
    bool maior;
    for(int i = arr.size()-1; i >= 0; i--) {
        maior = false;
        for(int j = i; j >= 0; j--) {
            if(arr[i] < arr[j])
                maior = true;
        }
        if(maior == false)
            count++;
    }
    cout << count << endl;
    

    return 0;
}