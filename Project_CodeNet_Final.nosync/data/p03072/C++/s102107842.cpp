#include <bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cin >>n ;

    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a.at(i);
    }

    vector <int> m(n);
    for(int i = 0 ; i < n; i++) {

        if(i == 0) {
            m.at(0) = a.at(0);
        } else {
            m.at(i) = max(m.at(i - 1),a.at(i));
        }


    }

    int ans = 0;

    for (int i = 0; i < n; i ++) {
        if(i == 0){
            ans++;
        } else {
if(a.at(i)>=m.at(i - 1)){
    ans ++;
}
        }
        
    }

    cout << ans << endl;


}
