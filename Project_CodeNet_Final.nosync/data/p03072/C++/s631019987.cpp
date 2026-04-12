#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, cont = 0, ans =0;
    cin >> n;

    int v[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    //        .
    // i: 6 5 6 8
    //    .
    // j: 6 5 6 8

    for(int i = n-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            if(v[i] >= v[j])
                cont++;
        }
        if(cont == i)
            ans++;
        cont = 0;
    }

    ans++;
    cout << ans << endl;


}
