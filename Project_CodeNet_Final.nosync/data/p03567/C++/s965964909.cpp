#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string n,a,b;
    cin >> n;
    for(int i=0;i<n.size()-1;i++){
        if(n[i]=='A'&&n[i+1]=='C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}