#include <bits/stdc++.h>
using namespace std;


int main(){
    for(int j=0; j<105; j++){
        int s1, s2;
        cin >> s1 >> s2;
        if(s1 == 0 && s2 == 0){
            break;
        }
        int ans = s1+s2;
        char mozi;
        mozi = 65;
        for(int i=1; i<5; i++){
            int a, b;
            cin >> a >> b;
        int temp;
        temp = a+b;
        if(ans <= temp){
            ans = temp;
            mozi = 65+i;
        }
        }
        cout << mozi << " " << ans << endl;
    }
    return 0;
}
