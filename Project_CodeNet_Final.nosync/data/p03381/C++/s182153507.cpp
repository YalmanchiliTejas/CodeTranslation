#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> sx(n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
        sx[i] = x[i];
    }

    sort(sx.begin(),sx.end());
    int low = sx[n/2-1];
    int high = sx[n/2];

    for(int i = 0; i < n; i++){
        if(x[i]<=low){cout << high << endl;}
        else{cout << low << endl;}
    }


    return 0;

}
