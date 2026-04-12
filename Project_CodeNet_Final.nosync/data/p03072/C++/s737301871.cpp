#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;
 
int main(){
    
    int N,H[110],Hm,ans;
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> H[i];
    }

    ans = 0;
    Hm = 0;

    for(int i=1;i<=N;i++){
        if(Hm<=H[i]){
            ans+=1;
        }
        if(H[i]>Hm){
            Hm=H[i];
        }
    }

    cout << ans;

    return 0;

}