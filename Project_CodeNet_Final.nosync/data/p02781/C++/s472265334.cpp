#include <bits/stdc++.h>
using namespace std;

long long int nCr(int n, int r){
    if(n < r) return 0;

    if(r == 0) return 1;
    else if(r == 1) return n;
    else if(r == 2) return n * (n-1) / 2;
    else if(r == 3) return n * (n-1) * (n-2) / 6;
    else return 0;
}

int main(){
    string n;
    int k;
    cin >> n >> k;

    int d = n.length();
    vector<int> num(d);
    for(int i=0; i<d; i++){
        num[i] = n[i] - '0';
    }

    vector<int> pow9(4,1);
    for(int i=1; i<4; i++){
        pow9[i] = pow9[i-1] * 9;
    }

    long long int ans = 0;
    for(int i=0; i<d; i++){
        if(i == d-1){
            if(k == 1) ans += num[i];
            if(k == 0) ans += 1;
            break;
        }

        if(num[i] != 0){
            ans += nCr(d-1-i,k) * pow9[k];
            //cout << nCr(d-1-i,k) << " " << pow9[k] << " " << ans << endl;
            ans += (num[i] - 1) * nCr(d-1-i,k-1) * pow9[k-1];
            k -= 1;
        }
    }
    cout << ans << endl;
    return 0;
}