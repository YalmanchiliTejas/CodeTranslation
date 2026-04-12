#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    int H[20];
    for(int i=0;i<N;i++)
        cin >> H[i];
    
    // N個の旅館
    int ans = 0;
    for(int i=0;i<N;i++){
        bool flag = true;
        for(int j=0;j<i;j++){
            if(H[j] > H[i])
                flag = false;
        }
        if(flag)
            ans++;
    }
    
    cout << ans << endl;    

}